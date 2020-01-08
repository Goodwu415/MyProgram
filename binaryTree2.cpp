#include <iostream> 
#define MAX 10000
#define NIL -1

struct Node{int parent, left,right;};

Node T[MAX];


int n, D[MAX],H[MAX]; //n �ڵ��� D ��¼��ȵ����� H ��¼�߶ȵ����� 
int count = 0; //�ݹ���� 
void setDepth(int u, int d);
int setHeight(int u);
int getSibling(int u);
void print(int u);
int main()
{
	int v, l,r,root = 0;
	scanf("%d",&n);
	
	for(int i = 0; i < n; ++i) T[i].parent = NIL;
	
	for(int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &v, &l, &r);
		T[v].left = l;// v�ڵ�������� 1  
		T[v].right = r;// v�ڵ�������� r 
		if(l != NIL) T[l].parent = v;// l ������ -1�������������ĸ��ڵ�Ϊ v 
		 
		if(r != NIL) T[r].parent = v;// r ������ -1�������������ĸ��ڵ�Ϊ v 
	}
	
	for(int i = 0; i < n; ++i)	//�ڵ�ı�ţ��������������ģ����ԣ���Ҫִ����δ��� 
		if(T[i].parent == NIL) root = i;//�ҵ����ڵ㣬���ڵ�û�и��ڵ�
	
	setDepth(root, 0);
	count = 0;
	setHeight(root);
	count = 0;
	for(int i = 0; i < n; ++i)
	{
		print(i);
		count = 0;	//���� 
	}
	 
	return 0;
}
void setDepth(int u, int d)
{
	count += 1; 
	if(u == NIL) return;//�����ݹ������, �ڵ����û���������� 
	D[u] = d; 	//D[u]�����Ϊd�� u �����ŵݹ�����룬���ı� 
	setDepth(T[u].left, d + 1);//�ȵݹ������������d + 1���������ݹ���ɺ�
								//�ٽ��ű���T[u]�ڵ���������Ͻ��ŵݹ�������
							//���������Ϊ�գ������˳���d ���ǽڵ����ȡ�
							//ÿ�εݹ飬���ᱣ�浱ǰ��dֵ��Ҳ����˵����ǰ�ݹ鲻��Ӱ����һ�εݹ�d��ֵ 
	setDepth(T[u].right, d + 1); //��ִ�е���������ʱ������ݹ鵽��ֹ����
							//�����˳����ڵ���ȱ��� d��
							//Ҳ���ǵ�����ֹ��������һ�� �ݹ�ʱ�� d 
}
//�Ӹ��ڵ���� 
int setHeight(int u)
{
	//�ұ���Щ�ݹ��Ū�±��ˡ���Ϊ����leftΪNILʱ���ͽ����ж�right�Ƿ�Ϊ��
	//��Ϊ�գ��ͽ��ŵݹ飬ֱ������������������ʱ���Ҹ㲻�����ǵݹ鷵�ص�ֵ
	//˭���գ���Ϊ���ݹ�rightʱ���п���left�����������ˣ����ţ��ֿ�ʼ�ݹ�
	//left,������ȥ����ݹ�ö��Ұ������������ˡ� 
	 //�����left����������ʱ��rightҲ�����㣬�����һ��ǿ����е����׵ġ�
	count += 1;
	int h1 = 0, h2 = 0;
	if(T[u].left != NIL)	//�ڵ�������� ��Ϊ�� 
		h1 = setHeight(T[u].left) + 1;	//�ʼ�� 0 + 1 ���Ե� 
	if(T[u].right != NIL) 
		h2 = setHeight(T[u].right) + 1; 	//�ʼ�� 0 + 1 ���Ե�
	//������Ĵ���ִ����󣬾Ϳɵõ��������ĸ�+1�����������ĸ�+1 
	return H[u] = (h1 > h2 ? h1 : h2);//���ض���֮�������Ǹ����� 
	//�Ҳ��룬�ʼreturn���� 0�� 	//�ʼ�� 1 �� 1 �����ԣ����� 1  
	
}
//���ؽڵ�u���ֵܽڵ� 
int getSibling(int u)
{
	count += 1;
	if(T[u].parent == NIL) return NIL;//���ڵ�ΪNIL�����Ǹ�
	//���ƣ���˼�ǣ�u�ڵ�ĸ��ڵ�������� != ��ǰ�ڵ� u &&
	// u�ڵ�ĸ��ڵ�������� != NIL 		NIL û�нڵ� 
	//��δ���Ӧ���Ǹ�������д�� 
	if(T[T[u].parent].left != u && T[T[u].parent].left != NIL)  
		return T[T[u].parent].left;
	//��δ��룬������������˼�෴ 
	if(T[T[u].parent].right != u && T[T[u].parent].right != NIL) 
		return T[T[u].parent].right;
	return NIL;//���������������㣬u�ڵ����Ҷ�ӽڵ㣬Ҷ�ӽڵ�ûchild; 
}

void print(int u)
{
	printf("node %d: ", u);
	printf("parent = %d, ", T[u].parent);
	printf("sibling = %d, ", getSibling(u));
	int deg = 0;//�ڵ�Ķ� ��Ҳ���ǽڵ��child�ڵ���� 
	if(T[u].left != NIL)deg++;
	if(T[u].right != NIL)deg++;
	printf("degree = %d, ", deg);
	printf("depth = %d, ", D[u]);//�ڵ����ȣ������ڼ���
	//�ڵ�ĸߣ����ǵ�ǰ�ڵ��child�ڵ㣬child�ڵ��child�ڵ㣬�Դ����ƣ�ֱ��child�ڵ�û��child�ڵ� 
	printf("height = %d, ", H[u]);
	
	if(T[u].parent == NIL)
	{
		printf("root\n");
	}else if(T[u].left == NIL && T[u].right == NIL) 
	{
		printf("leaf\n");
	}else{
		printf("internal node\n");
	}
}

