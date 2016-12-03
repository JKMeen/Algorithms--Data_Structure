#include "binaryTree.h"
//#define max(X,Y)   X>Y?X:Y

// 중위 순회
void inorder(TreeNode *root){
	if (root){
		inorder(root->left); // 왼쪽서브트리 순회
		printf("%d ", root->data); // 노드 방문
		inorder(root->right); //오른쪽서브트리 순회
	}
}
// 전위 순회
void preorder(TreeNode *root){
	if (root){
		printf("%3d", root->data); //노드 방문
		preorder(root->left); //왼쪽서브트리 순회
		preorder(root->right); //오른쪽서브트리 순회
	}
}

// 후위 순회
void postorder(TreeNode *root){
	if (root){
		postorder(root->left);	 // 왼쪽서브트리 순회
		postorder(root->right);  // 오른쪽서브트리순회
		printf("%3d", root->data);  // 노드 방문
	}
}


int get_node_count(TreeNode *node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) +
		get_node_count(node->right);
	return count;
}

int max(int a, int b)
{
	if (a>b) return a;
	else return b;
}

int get_height(TreeNode *node)
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t; // p는 부모노드, t는 현재노드 
	TreeNode *n;     // n은 새로운 노드
	t = *root;
	p = NULL;
	// 탐색을 먼저 수행 
	while (t != NULL){
		if (key == t->data) return;
		p = t;
		if (key < t->data) t = t->left;
		else t = t->right;
	}
	// key가 트리 안에 없으므로 삽입 가능
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;   //메모리 할당에 실패한 경우
	n->data = key; // 데이터 복사
	n->left = n->right = NULL;

	// 부모 노드와 링크 연결
	if (p != NULL)
	if (key < p->data)
		p->left = n;
	else p->right = n;
	else *root = n;
}

void delete_node(TreeNode **root, int key)
{
	TreeNode *p, *t, *child, *succ, *succ_p;
	// key를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;

	// key를 갖는 노드 t를 탐색한다.
	while (t != NULL && t->data != key){
		p = t;
		t = (key < t->data) ? t->left : t->right;
	}
	// 탐색이 종료된 시점에 t가 NULL이면 트리안에 key가 없음
	if (t == NULL) { 	// 탐색트리에 없는 키
		printf("key is not in the tree");
		return;
	}

	// 첫번째 경우: 단말노드인 경우
	if ((t->left == NULL) && (t->right == NULL)){
		if (p != NULL){    // 부모노드의 자식필드를 NULL로 만든다.
			if (p->left == t)
				p->left = NULL;
			else p->right = NULL;
		}
		else // 만약 부모노드가 NULL이면 삭제되는 노드가 루트
			*root = NULL;
	}
	// 두번째 경우: 하나의 자식만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL)){
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL){
			if (p->left == t)	// 부모를 자식과 연결 
				p->left = child;
			else p->right = child;
		}
		else //만약 부모노드가 NULL이면 삭제되는 노드가 루트
			*root = child;
	}
	// 세번째 경우: 두개의 자식을 가지는 경우
	else{
		// 오른쪽 서브트리에서 후계자를 찾는다.
		succ_p = t;
		succ = t->right;
		// 후계자를 찾아서 계속 왼쪽으로 이동한다.
		while (succ->left != NULL){
			succ_p = succ;
			succ = succ->left;
		}
		// 후속자의 부모와 자식을 연결 
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		t->data = succ->data; // 후속자가 가진 키값을 현재 노드에 복사
		t = succ; // 원래의 후속자 삭제
	}
	free(t);
}


void main()
{
	TreeNode *root = NULL; // 1. 루트 추가
	int key; // 받을 키 값
	int del;
	
	printf("Input Key, (EXIT : -1) >>> ");
	scanf("%d", &key);
	while (key != -1){
		insert_node(&root, key);
		printf("Input Key, (EXIT : -1) >>> ");
		scanf("%d", &key);
	}
	printf("\n\n< 중위순회 결과 > \n");
	inorder(root);
	printf("\n< 트리 개수 >\n[ %d 개 ]\n\n", get_node_count(root));
	printf("< 트리 높이 >\n[ %d 개 ]\n\n\n", get_height(root));

	while (del != -1){
		printf("Input del, (EXIT : -1) >>> ");
		scanf("%d", &del);
		delete_node(&root, del);
		printf("< %d 삭제 >\n");
	}

	printf("\n\n< 중위순회 결과 > \n");
	inorder(root);
	printf("\n< 트리 개수 >\n[ %d 개 ]\n\n", get_node_count(root));
	printf("< 트리 높이 >\n[ %d 개 ]\n\n\n", get_height(root));
}





