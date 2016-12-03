#include "binaryTree.h"

// ���� ��ȸ
void preorder(TreeNode *root){
	if (root){
		printf("%3d", root->data); //��� �湮
		preorder(root->left); //���ʼ���Ʈ�� ��ȸ
		preorder(root->right); //�����ʼ���Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
void inorder( TreeNode *root ){
   if ( root ){
       inorder( root->left ); // ���ʼ���Ʈ�� ��ȸ
       printf("%3d", root->data ); // ��� �湮
      inorder( root->right ); //�����ʼ���Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
void postorder( TreeNode *root ){
    if ( root ){
         postorder( root->left );	 // ���ʼ���Ʈ�� ��ȸ
         postorder( root->right );  // �����ʼ���Ʈ����ȸ
         printf("%3d", root->data );  // ��� �湮
	}
}

void main()
{
	TreeNode *n1, *n2, *n3, *n4, *n5, *n6;
	TreeNode *root;

	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n6 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 15; n1->left = n2; n1->right = n3;
	n2->data = 4; n2->left = n4; n2->right = NULL;
	n3->data = 20; n3->left = n5; n3->right = n6;
	n4->data = 1; n4->left = NULL; n4->right = NULL;
	n5->data = 16; n5->left = NULL; n5->right = NULL;
	n6->data = 25; n6->left = NULL; n6->right = NULL;

	root = n1;

	printf("���� ��ȸ ��� >>> ");
	preorder(root);

	printf("\n���� ��ȸ ��� >>> ");
	inorder(root);

	printf("\n���� ��ȸ ��� >>> ");
	postorder(root);
	printf("\n");
}





