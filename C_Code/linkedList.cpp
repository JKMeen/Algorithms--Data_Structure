//���Ḯ��Ʈ pDays={��,ȭ,��,��,��, ��, ��}

#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef char element;
typedef struct ListNode { 
	element day[3];
	struct ListNode *link;   
} ListNode; 


void printList( ListNode* p )
{
	ListNode *tmp = p->link; // p���Ͱ� �ƴ� p->link���� �����ؾ��Ѵ�.
	printf("���Ḯ��Ʈ ���:");
	while( tmp!= NULL ) {
		printf(" %s ", tmp->day );
		tmp = tmp->link;
	}
	printf("\n");
}

// phead: ����Ʈ�� ��� �������� ������
// before : ���� ���
// new_node : ���Ե� ��� 
void insert_node( ListNode *before, ListNode *new_node)
{	// if���� �ʿ������
	new_node->link = before->link;
	before->link = new_node;
}

ListNode *search(ListNode *head, char x[])
{
	ListNode *p = head->link;
	while (p != NULL){
		if (strcmp(p->day, x) == 0) return p;  // Ž�� ����
		p = p->link;
	}
	return p;  // Ž�� ������ ��� NULL ��ȯ
}

// phead : ��� �����Ϳ� ���� ������ 
// before: ������ ����� ���� ���
// removed: ������ ��� 
void remove_node(ListNode *before, ListNode *removed)
{
	before->link = removed->link;
	free(removed);
}

int main()
{
	ListNode *pDays; //

	pDays = (ListNode*)malloc(sizeof(ListNode));
	pDays->link = NULL;

	ListNode *new_node, *before, *remove;

	// �޸� �Ҵ�
	/*��*/
	new_node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(new_node->day, "��");  // c������ ��Ʈ���� �����Ƿ� strcpy(��Ʈ��ī��)�� ���
	new_node->link = NULL;
	insert_node( pDays, new_node);
	
	/*��*/
	new_node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(new_node->day, "��");
	new_node->link = NULL;
	//search
	before = search( pDays, "��"); // �������� ã�Ƽ� before�� �־���
	insert_node( before, new_node);

	/*ȭ*/
	new_node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(new_node->day, "ȭ");
	new_node->link = NULL;
	before = search(pDays, "��");
	insert_node(before, new_node);

	new_node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(new_node->day, "��");
	new_node->link = NULL;
	before = search(pDays, "ȭ");
	insert_node(before, new_node);
	
	printList(pDays);

	printf("���� �� ���\n");
	remove = search(pDays, "��");
	before = search(pDays, "ȭ");
	remove_node(before, remove);

	printList( pDays );
	return 0;
}