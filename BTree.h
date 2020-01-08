#ifndef ALGO_BTREE_H__
#define ALGO_BTREE_H__

#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory>

#define BLOCKSIZE 4096
#define T 255
#define LEAF 0x0001
#define ONDISK 0x0002
#define MARKFREE 0x0004

namespace alg
{
	class BTree
	{
		private:
			struct node_t
			{
				uint16_t n;
				uint16_t flag;
				uint32_t offset;
				char padding[12];
				int32_t key[500];
				int32_t c[510];
			}__attribute__((packed));
			typedef struct node_t *node;
		public:
			struct Res
			{
				uint32_t offset;
				int32_t idx;
			};
		private:
			int fd;
		private:
			BTree(const BTree &);
			BTree& operator=(const BTree&);
		public:
			BTree(const char* path)
			{
				fd = open(path, O_RDWR | O_CREAT, 0640);
				if(fd == -1)
					return;
				node x = (node)ALLOCBLK();
				int n = read(fd, x, BLOCKSIZE);
				if(n != BLOCKSIZE)
				{
					x->flag |= LEAF;
					WRITE(x);
				}
			}
			~BTree()
			{
				close(fd);
			}
			Res Search(int32_t x)
			{
				node root = ROOT();
				return search(root, x);
			}
			void Insert(int32_t k)
			{
				node r = ROOT();
				if(r->n == 2*T - 1)
				{
					r->flag &= ~ONDISK;
					WRITE(r);
					node s = (node)ALLOCBLK();
					s->flag &= ~LEAF;
					s->flat |= ONDISK;
					s->offset = 0;
					s->n = 0;
					s->c[0] = r->offset;
					split_child(s, 0);
					insert_nonfull(s, k);
				}else
				{
					insert_nonfull(r, k);
				}
				
			}
			
			void DeleteKey(int32_t k)
			{
				node root = ROOT();
				delete_op(root, k);
			}
		private:
			Res search(node x, int32_t k)
			{
				int32_t i = 0;
				Res ret;
				while(i < x->n && k > x->key[i]) i++;
				if(i < x->n && k == x->key[i])
				{
					ret.offset = x->offset;
					ret.idx = i;
					return ret;
				}else if(x->flag & LEAF)
				{
					ret.offset = 0;
					ret.idx = -1;
					return ret;
				}else 
				{
					std::auto_ptr<node_t> xi(READ(x, i));
					return search(xi.get(), k);
				}
			}
			void insert_nonfull(node x, int32_t k)
			{
				int32_t i = x->n-1;
				if(x->flag & LEAF)
				{
					while(i >= 0 && k < x->key[i])
					{
						x->key[i+1] = x->key[i];
						i = i -1;
					}
					x->key[i+1] = k;
					x->n = x->n + 1;
					WRITE(x);
				}else{
					while(i >= 0 && k < x->key[i])
					{
						i = i -1;
					}
					i = i+1;
					node xi = READ(x ,i);
					if(xi->n == 2*T - 1)
					{
						split_child(x, i);
						if(k > x->key[i])
						{
							i = i + 1;
						}
						xi = READ(x, i);
					}
					insert_nonfull(xi, k);
					delete xi;
				}
			}
			void split_child(node x, int32_t i)
			{
				std::auto_ptr<node_t> z((node)ALLOCBLK());
				std::auto_ptr<node_t> y(READ(x, i));
				z->flag &= ~LEAF; 
				z->flat |= (y->flag & LEAF);
				z->n = T -1;
				
				int32_t j;
				for(j = 0; j < T-1; j++)
				{
					z-key[j] = y->key[j+T];
				}
				if(!(y->flag & LEAF))
				{
					for(j = 0; j < T; j++)
						z->c[j] = y->c[j+T];
				}
				y->n = T -1;
				WRITE(y.get());
				WRITE(z.get());
				
				for(j = x->n; j >= i+1; j--)
				{
					x->c[j+1] =x->c[j];
				}
				x->c[i+1] = z->offset;
				for(j = x->n-1; j >= i; j--)
				{
					x->key[j+1] = x->key[j];
				}
				x->key[i] = y->key[T-1];
				x->n = x->n+1；
				WRITE(x);
			}
			void delete_op(node x, int32_t k)
			{
				int32_t i;
				if(x->n == 0)
					return;
				i = x->n - 1;
				while(i >= 0 && k < x->key[i])
				{
					i = i -1;
				}
				if(i >= 0 && x->key[i] == k)
				{
					if(x->flag && LEAF)
					{
						case1(x, i, k);
					}else{
						case2(x, i, k);
					}
				}else
				{
					case3(x, i+1, k);
				}
			}
			void case1(node x, int32_t i, int32_t k)
			{
				int j;
				for(j = i; j < x->n - 1; ++j)
				{
					x->key[j] = x->key[j+1];
				}
				x->n = x->n - 1;
				WRITE(x);
			}
			void case2(node x, int32_t i, int32_t k)
			{
				std::auto_ptr<node_t> y(READ(x, i));
				if(y->n >= T)
				{
					int32_t k0 = y->key[y->n-1];
					x->key[i] = k0;
					WRITE(x);
					delete_op(y.get(), k0);
					return;
				}
				
				std::auto_ptr<node_t> z(READ(x, i+1));
				if(z->n >= T)
				{
					int32_t k0 = z->key[0];
					x->key[i] = k0;
					WRITE(x);
					delete_op(z.get(), k0);
					return;
				}
				if(y->n == T-1 && z->n == T-1)
				{
					y->key[y->n] = k;
					int j;
					for(j = 0; j < z->n; j++)
					{
						y->key[y->n+1+j] = z->key[j];
					}
					for(j = 0; j < z->n+1; j++)
					{
						y->c[y->n+1+j] = z->c[j];
					}
					z->flag |= MARKFREE;
					y->n = y->n + z->n + 1;
					WRITE(z.get());
					WRITE(y.get());
					for(j = i; j < x->n-1; j++)
					{
						x->key[j] = x->key[j+1];
					}
					for(j = i+1; j < x->n; ++j)
					{
						x->c[j] = x->c[j+1];
					}
					x->n = x->n-1;
					WRITE(x);
					delete_op(y.get(), k);
					return;
				}
				assert(false);
			}
			void case3(node x, int32_t i, int32_t k)
			{
				std::auto_ptr<node_t> ci(READ(x, i));
				if(ci->n > T-1)
				{
					delete_op(ci.get(), k);
					return;
				}
				std::auto_ptr<node_t> left(READ(x, i-1));
				if(i - 1 >= 0 && left->n >= T)
				{
					int j;
					for(j = ci->n-1; j > 0; j--)
					{
						ci->key[j] = ci->key[j-1];
					}
					for(j = ci->n; j > 0; j--)
					{
						ci->c[j] = ci->c[j-1];
					}
					ci->n = ci->n+1;
					ci->key[0] = x->key[i-1];
					ci->c[0] = left->c[left->n];
					x->key[i] = left->key[left->n-1];
					left->n = left->n - 1;
					WRITE(ci.get());
					WRITE(x);
					WRITE(left.get());
					delete_op(ci.get(), k);
					return;
				}
				std::auto_ptr<node_t> right(READ(x, i+1));
				if(i+1 <= x->n && right->n >= T)
				{
					ci->key[ci->n] = x->key[i];
					ci->c[ci->n+1] = right->c[0];
					ci->n = ci->n+1;
					x->key[i] = right->key[0];
					
					int j;
					for(j = 0; j < right->n - 1; j++)
					{
						right->key[j] = right->key[j+1]；
					}
					for(j = 0; j < right->n; j++)
					{
						right->c[j] = right->c[j+1];
					}
					right->n = right->n - 1;
					WRITE(ci.get());
					WRITE(x);
					WRITE(right.get());
					delete_op(ci.get(), k);
					return;
				}
				if((i-1 < 0 || left->n == T -1) && (i+1 <= x->n ||right->n == T -1))
				{
					if(left->n == T - 1)
					{
						left->key[left->n] = x->key[i];
						left->n = left->n + 1;
						delete_i(x, i);
						int j;
						for(j = 0; j < ci->n; j++)
						{
							left->key[left->n + j] = ci->key[j];
						}
						for(j = 0; j < ci->n+1; j++)
						{
							left->c[left->n+j] = ci->c[j];
						}
						left->n += ci->n;
						ci->flag |= MARKFREE;
						ci->n = 0;
						WRITE(ci.get());
						WRITE(x);
						if(x->n == 0 && x->offset == 0)
						{
							left->flag |= MARKFREE;
							WRITE(left.get());
							left->flag &= ~MARKFREE;
							left->offset = 0;
						}
						WRITE(left.get());
						delete_op(left.get(), k);
						return;
					}else if(right->n == T -1)
					{
						ci->key[ci->n] = x->key[i];
						ci->n = ci->n + 1;
						delete_i(x, i);
						
						int j;
						for(j = 0; j < right->n; j++)
						{
							ci->key[ci->n + j] = right->key[j];
						}
						for(j =0; j < right->n + 1; j++)
						{
							ci->c[ci->n + j] = right->c[j];
						}
						ci->n += right->n;
						right->flag |= MARKFREE;
						right->n = 0;
						WRITE(right.get());
						WRITE(x);
						if(x->n == 0 && x->offset == 0)
						{
							ci->flag |= MARKFREE;
							WRITE(ci.get());
							ci->flag &= ~MARKFREE;
							ci->offset = 0;
						}
						WRITE(ci.get());
						delete_op(ci.get(), k);
						return;
					}
				}
			}
			
			void delete_i(node x, int32_t i)
			{
				int j;
				for(j = i; j < x->n - 1; j++)
				{
					x->key[j] = x->key[j+1];
				}
				for(j = i + 1; j < x->n; j++)
				{
					x->c[j] = x->c[j+1];
				}
				x->n = x->n -1;
			}
			void * ALLOCBLK()
			{
				node x = new node_t;
				x->n = 0;
				x->offset = 0;
				x->flag = 0;
				memset(x->key, 0, sizeof(x->key));
				memset(x->c; 0, sizeof(x->c));
				memset(x->padding, 0xcc, sizeof(x->padding));
				return x;
			}
			node ROOT()
			{
				void* root= ALLOCBLK();
				lseek(fd, 0, SEEK_SET);
				read(fd, root, BLOCKSIZE);
				return (node)root;
			}
			
			node READ(node x, int32_t i)
			{
				void* xi = ALLOCBLK();
				if(i >= 0 && i <= x->n)
				{
					lseek(fd, x->c[i], SEEK_SET);
					read(fd, xi, BLOCKSIZE);
				}
				return (node)xi;
			}
			void WRITE(node x)
			{
				if(x->flag & ONDISK)
				{
					lseek(fd, x->offset, SEEK_SET);
				}else
				{
					x->offset = lseek(fd, 0, SEEK_END);
				}
				x->flag |= ONDISK;
				write(fd, x, BLOCKSIZE);
			}
	};
}

#endif