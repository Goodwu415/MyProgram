#ifndef ALGO_RBTREE_H_
#define ALGO_RBTREE_H_
#include <stdio.h>
#include <stdint.h>
#include <stdexcept>
#include "rbtree_defs.h"

namespace alg{
	template<typename KeyT, typename ValueT>
	class RBTree:public RBTreeAbstract{
		private:
		struct KVNode: public rbtree_node_t{
			KeyT key;
			ValueT value;
		};
#define KVNode(node) static_case<KVNode*>(node)
		void destruct(KVNode* n)
		{
			if(n == NULL) return;
			destruct(KVNODE(n->left));
			destruct(KVNODE(n->right);
			delete n;
		}
		public:
			~RBTree()
			{
				destruct(KVNODE(get_root()));
			}
			void insert(const KeyT& key, const ValueT& value)
			{
				KVNode* inserted_node = new_node(key, value, RED, NULL, NULL);
				if(get_root() == NULL)
				{
					set_root(inserted_node);
				}else
				{
					KVNode* n = KVNODE(get_root());
					while(1)
					{
						if(key == n->key)
						{
							n->value = value;
							delete (inserted_node);
							return;
						}else if(key < n->key)
						{
							if(n->left == NULL)
							{
								n->left = inserted_node;
								break;
							}else{
								n = static_case<KVNode*>(n->left);
							}
						}
					}
					inserted_node->parent = n;
				}
				insert_case1(inserted_node);
			}
				
		
		bool contains(KeyT key)
		{
			if(lookup_node(key))
				return true;
			
			return false;
		}
		ValueT operator[](KeyT key)
		{
			kVNode* n = lookup_node(key);
			if(n == NULL) throw std::out_of_range("no such key");
			return n->value;
		}
		void delete_key(KeyT key)
		{
			rbtree_node child;
			KVNode* n = loopup_node(key);
			if(n == NULL)return;
			if(n->left != NULL && n->right != NULL)
			{
				KVNode* pred = static_cast<KVNode*>(maximum_node(n->left));
				n->key = pred->key;
				n->value = pred->value;
				n = pred;
			}
			assert(n->left == NULL || n->right == NULL);
			child = n->right == NULL ? n->left : n->right;
			if(node_color(n ) == BLACK)
			{
				n->color = node_color(child);
				delete_case1(n);
			}
			replace_node(n, child);
			
			if(n->parent == NULL && child != NULL)
				child->color = BLACK;
			delete(n);
		}
		
		void print()
		{
			print_helper(KVNODE(get_root()),0);
			puts("");
		}
	protected:
		void print_helper(KVNode* n, int indent)
		{
			int i;
			if(n == NULL)
			{
				fputs("<empty tree>", stdout);
				return;
			}
			if(n->right != NULL)
				print_helper(KVNODE(n->right), indent + INDENT_STEP);
			for(i =0; i < indent; ++i)
				fputs(" ", stdout);
			if(n->color == BLACK)
				printf("%d\n", (int)n->key);
			else
				printf("<%d>\n", (int)n->key);
			if(n->left != NULL)
				print_helper(KVNODE(n->left), indent + INDENT_STEP);
		}
		
		KVNode* new_node(KeyT key, ValueT vale, color rbtree_node_color, rbtree_node left, rbtree_node right)
		{
			KVNode* result = new KVNode;
			result->key = key;
			result->value = value;
			result->color = rbtree_node_color;
			result->left = left;
			result->right = right;
			if(left != NULL)left->parent = result;
			if(right != NULL)right->parent = result;
			result->parent = NULL;
			return result;
		}
		KVNode* lookup_node(KeyT key)
		{
			KVNode* n = KVNODE(get_root());
			while(n != NULL)
			{
				if(key == n->key)
				{
					return n;
				}else if(key < n->key)
				{
					n = KVNODE(n->left);
				}else
				{
					n = KVNODE(n->right);
				}
			}
			return n;
		}
	};
}
#endif
