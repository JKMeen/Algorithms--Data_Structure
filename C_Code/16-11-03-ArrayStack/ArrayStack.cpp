#include "stack.h"
#include <string.h>

// ���� �ʱ�ȭ �Լ�
void init(StackType *s) {
	//�߰�
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s){
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

// �����Լ�
void push(StackType *s, element item) { 
	if (is_full(s)){
		printf("�ڸ� ����\n");
		exit(0);
	}
	else {
		s->top++; // top �ִ� ũ�� ����
		s->stack[s->top] = item; // top�� �������� �������
	}
}

// �����Լ�
element pop(StackType *s) { 
	if (is_empty(s)){
		printf("������ ���� \n");
		exit(0);
	}
	else {
		element tmp = s->stack[s->top];
		s->top--;
		return tmp;
	}
}

// ��ũ�Լ�, �� ���� �ִ� �ָ� ��ȯ
element peek(StackType *s) {
	if( is_empty(s) ) {
		printf("���� ���� ����\n");
		exit(0) ;
	}
	else return s->stack[s->top];
}

// ��ȣ ¦�� �´��� üũ
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
				//�ڵ� �߰�
              break;
			case ')':   
			case ']':    
			case '}':
              //�ڵ� �߰�
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