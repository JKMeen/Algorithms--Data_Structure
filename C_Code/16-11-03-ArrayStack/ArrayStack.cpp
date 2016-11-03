#include "stack.h"
#include <string.h>

// 스택 초기화 함수
void init(StackType *s) {
	//추가
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s){
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

// 삽입함수
void push(StackType *s, element item) { 
	if (is_full(s)){
		printf("자리 없어\n");
		exit(0);
	}
	else {
		s->top++; // top 최대 크기 증가
		s->stack[s->top] = item; // top에 아이템을 집어넣음
	}
}

// 삭제함수
element pop(StackType *s) { 
	if (is_empty(s)){
		printf("아이템 없어 \n");
		exit(0);
	}
	else {
		element tmp = s->stack[s->top];
		s->top--;
		return tmp;
	}
}

// 피크함수, 맨 위에 있는 애만 반환
element peek(StackType *s) {
	if( is_empty(s) ) {
		printf("스택 공백 에러\n");
		exit(0) ;
	}
	else return s->stack[s->top];
}

// 괄호 짝이 맞는지 체크
int check_matching(char in[]) 
{ 
    StackType s;
    char ch, open_ch; 
    int i, n = strlen(in);  
    init(&s);
   
    for (i = 0; i < n; i++) { 
          ch = in[i];
          switch(ch){
            case '(':   
			case '[':    
			case '{':
				//코드 추가
              break;
			case ')':   
			case ']':    
			case '}':
              //코드 추가
              break;
           }
     }
    if(!is_empty(&s)) return false; 
    return true;
}

int main()
{
	char input[100];
	

}