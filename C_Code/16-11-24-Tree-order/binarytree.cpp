#include "binaryTree.h"

// 전위 순회
void preorder(TreeNode *root){
	if (root){
		printf("%3d", root->data); //노드 방문
		preorder(root->left); //왼쪽서브트리 순회
		preorder(root->right); //오른쪽서브트리 순회
	}
}

// 중위 순회
void inorder( TreeNode *root ){
   if ( root ){
       inorder( root->left ); // 왼쪽서브트리 순회
       printf("%3d", root->data ); // 노드 방문
      inorder( root->right ); //오른쪽서브트리 순회
	}
}

// 후위 순회
void postorder( TreeNode *root ){
    if ( root ){
         postorder( root->left );	 // 왼쪽서브트리 순회
         postorder( root->right );  // 오른쪽서브트리순회
         printf("%3d", root->data );  // 노드 방문
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

	printf("전위 순회 결과 >>> ");
	preorder(root);

	printf("\n중위 순회 결과 >>> ");
	inorder(root);

	printf("\n후위 순회 결과 >>> ");
	postorder(root);
	printf("\n");
}





