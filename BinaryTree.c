#include <stdio.h>

//树的深度： 


//二叉树 
typedef struct _Tree{
	int data;
	struct _Tree *pParent;
	struct _Tree *pLeftChild;
	struct _Tree *pRightChild;
}Tree,*PTree;

int main()
{
	int array[] = {22,31,31,12,3,6,5,7,24,223,62,13,54};
	
	PTree pt;
	Tree a,b,c,d;
	pt = &a;
	a.pParent = NULL;
	a.data = 20;
	a.pLeftChild = &b;
	a.pRightChild = &c;
	b.pParent = &a;
	b.pLeftChild = &d;
	b.data = 30;
	c.data = 50;
	d.data = 100;
	
	printf("%d %d\n",a.data, b.data);
	
	
	return 0;
}
