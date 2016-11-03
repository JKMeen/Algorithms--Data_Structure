//연결리스트 pDays={월,화,수,목,금, 토, 일}

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
	printf("\n연결리스트 출력:");
	while( tmp!= p ) {
		printf(" %s ", tmp->day );
		tmp = tmp->next;
	}
}

// before : 선행 노드
// new_node : 삽입될 노드 
void dinsert_node(DlistNode *before, DlistNode *new_node) 
{ 
	new_node->prev = before;                  
	new_node->next = before->next;     
	before->next->prev = new_node;     
	before->next = new_node;             
} 

// phead : 헤드 포인터에 대한 포인터 
// removed: 삭제될 노드 
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
		if( strcmp(p->day, x) ==0) return p;  // 탐색 성공
		p = p->next;
	}
	return p;  // 탐색 실패일 경우 NULL 반환
}

int main()
{
	DlistNode *pDays;

	pDays = (DlistNode*)malloc(sizeof(DlistNode));
	pDays->next = pDays;
	pDays->prev = pDays;

	DlistNode *new_node, *before, *remove;
	new_node = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy( new_node->day, "월");
	new_node->next = NULL;
	new_node->prev = NULL;

	dinsert_node( pDays, new_node );
	printList( pDays );

	new_node = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy( new_node->day, "화");
	new_node->next = NULL;
	new_node->prev = NULL;
	before = search( pDays, "월");
	dinsert_node( before, new_node );
	printList( pDays );

	new_node = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy( new_node->day, "목");
	new_node->next = NULL;
	new_node->prev = NULL;
	before = search( pDays, "화");
	dinsert_node( before, new_node );
	printList( pDays );

	new_node = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy( new_node->day, "수");
	new_node->next = NULL;
	new_node->prev = NULL;
	before = search( pDays, "화");
	dinsert_node( before, new_node );
	printList( pDays );

	remove = search( pDays, "화");
	dremove_node( pDays, remove );
	printList( pDays );


	return 0;
}