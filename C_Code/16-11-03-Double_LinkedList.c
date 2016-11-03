//���Ḯ��Ʈ pDays={��,ȭ,��,��,��, ��, ��}

#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef char element;
typedef struct DlistNode {
	element day[3];
	struct DlistNode *prev;
	struct DlistNode *next;
} DlistNode;

void printList( DlistNode* p )
{
	DlistNode *tmp = p->next;
	printf("\n���Ḯ��Ʈ ���:");
	while( tmp!= p ) {
		printf(" %s ", tmp->day );
		tmp = tmp->next;
	}
}

// before : ���� ���
// new_node : ���Ե� ��� 
void dinsert_node(DlistNode *before, DlistNode *new_node) 
{ 
	new_node->prev = before;                  
	new_node->next = before->next;     
	before->next->prev = new_node;     
	before->next = new_node;             
} 

// phead : ��� �����Ϳ� ���� ������ 
// removed: ������ ��� 
void dremove_node(DlistNode *phead_node, DlistNode *removed) 
{ 
	if( removed == phead_node ) return; 
	removed->prev->next = removed->next;   
	removed->next->prev = removed->prev;   
	free(removed); 
} 

DlistNode *search(DlistNode *head,  char x[])
{
	DlistNode *p = head->next;
	while( p != head ){
		if( strcmp(p->day, x) ==0) return p;  // Ž�� ����
		p = p->next;
	}
	return p;  // Ž�� ������ ��� NULL ��ȯ
}

int main()
{
	DlistNode *pDays;

	pDays = (DlistNode*)malloc(sizeof(DlistNode));
	pDays->next = pDays;
	pDays->prev = pDays;

	DlistNode *new_node, *before, *remove;
	new_node = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy( new_node->day, "��");
	new_node->next = NULL;
	new_node->prev = NULL;

	dinsert_node( pDays, new_node );
	printList( pDays );

	new_node = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy( new_node->day, "ȭ");
	new_node->next = NULL;
	new_node->prev = NULL;
	before = search( pDays, "��");
	dinsert_node( before, new_node );
	printList( pDays );

	new_node = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy( new_node->day, "��");
	new_node->next = NULL;
	new_node->prev = NULL;
	before = search( pDays, "ȭ");
	dinsert_node( before, new_node );
	printList( pDays );

	new_node = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy( new_node->day, "��");
	new_node->next = NULL;
	new_node->prev = NULL;
	before = search( pDays, "ȭ");
	dinsert_node( before, new_node );
	printList( pDays );

	remove = search( pDays, "ȭ");
	dremove_node( pDays, remove );
	printList( pDays );


	return 0;
}