#include "binaryTree.h"
//#define max(X,Y)   X>Y?X:Y

// ���� ��ȸ
void inorder(TreeNode *root){
	if (root){
		inorder(root->left); // ���ʼ���Ʈ�� ��ȸ
		printf("%d ", root->data); // ��� �湮
		inorder(root->right); //�����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
void preorder(TreeNode *root){
	if (root){
		printf("%3d", root->data); //��� �湮
		preorder(root->left); //���ʼ���Ʈ�� ��ȸ
		preorder(root->right); //�����ʼ���Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
void postorder(TreeNode *root){
	if (root){
		postorder(root->left);	 // ���ʼ���Ʈ�� ��ȸ
		postorder(root->right);  // �����ʼ���Ʈ����ȸ
		printf("%3d", root->data);  // ��� �湮
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
	TreeNode *p, *t; // p�� �θ���, t�� ������ 
	TreeNode *n;     // n�� ���ο� ���
	t = *root;
	p = NULL;
	// Ž���� ���� ���� 
	while (t != NULL){
		if (key == t->data) return;
		p = t;
		if (key < t->data) t = t->left;
		else t = t->right;
	}
	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;   //�޸� �Ҵ翡 ������ ���
	n->data = key; // ������ ����
	n->left = n->right = NULL;

	// �θ� ���� ��ũ ����
	if (p != NULL)
	if (key < p->data)
		p->left = n;
	else p->right = n;
	else *root = n;
}

void delete_node(TreeNode **root, int key)
{
	TreeNode *p, *t, *child, *succ, *succ_p;
	// key�� ���� ��� t�� Ž��, p�� t�� �θ���
	p = NULL;
	t = *root;

	// key�� ���� ��� t�� Ž���Ѵ�.
	while (t != NULL && t->data != key){
		p = t;
		t = (key < t->data) ? t->left : t->right;
	}
	// Ž���� ����� ������ t�� NULL�̸� Ʈ���ȿ� key�� ����
	if (t == NULL) { 	// Ž��Ʈ���� ���� Ű
		printf("key is not in the tree");
		return;
	}

	// ù��° ���: �ܸ������ ���
	if ((t->left == NULL) && (t->right == NULL)){
		if (p != NULL){    // �θ����� �ڽ��ʵ带 NULL�� �����.
			if (p->left == t)
				p->left = NULL;
			else p->right = NULL;
		}
		else // ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = NULL;
	}
	// �ι�° ���: �ϳ��� �ڽĸ� ������ ���
	else if ((t->left == NULL) || (t->right == NULL)){
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL){
			if (p->left == t)	// �θ� �ڽİ� ���� 
				p->left = child;
			else p->right = child;
		}
		else //���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = child;
	}
	// ����° ���: �ΰ��� �ڽ��� ������ ���
	else{
		// ������ ����Ʈ������ �İ��ڸ� ã�´�.
		succ_p = t;
		succ = t->right;
		// �İ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�.
		while (succ->left != NULL){
			succ_p = succ;
			succ = succ->left;
		}
		// �ļ����� �θ�� �ڽ��� ���� 
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		t->data = succ->data; // �ļ��ڰ� ���� Ű���� ���� ��忡 ����
		t = succ; // ������ �ļ��� ����
	}
	free(t);
}


void main()
{
	TreeNode *root = NULL; // 1. ��Ʈ �߰�
	int key; // ���� Ű ��
	int del;
	
	printf("Input Key, (EXIT : -1) >>> ");
	scanf("%d", &key);
	while (key != -1){
		insert_node(&root, key);
		printf("Input Key, (EXIT : -1) >>> ");
		scanf("%d", &key);
	}
	printf("\n\n< ������ȸ ��� > \n");
	inorder(root);
	printf("\n< Ʈ�� ���� >\n[ %d �� ]\n\n", get_node_count(root));
	printf("< Ʈ�� ���� >\n[ %d �� ]\n\n\n", get_height(root));

	while (del != -1){
		printf("Input del, (EXIT : -1) >>> ");
		scanf("%d", &del);
		delete_node(&root, del);
		printf("< %d ���� >\n");
	}

	printf("\n\n< ������ȸ ��� > \n");
	inorder(root);
	printf("\n< Ʈ�� ���� >\n[ %d �� ]\n\n", get_node_count(root));
	printf("< Ʈ�� ���� >\n[ %d �� ]\n\n\n", get_height(root));
}





