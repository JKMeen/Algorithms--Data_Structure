#include "stack.h"
#include <string.h>

// 스택 초기화 함수
void init(StackType *s) {
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s){
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {  // 삽입함수
	if (is_full(s))
	{
		printf("스택 포화 상태 \n");
		exit(0);
	}
	else
	{
		s->top++;
		s->stack[s->top] = item;
	}
}

element pop(StackType *s) { // 삭제함수
	if (is_empty(s))
	{
		printf("스택 공백 상태\n");
		exit(0);
	}
	else
	{
		element tmp = s->stack[s->top];
		s->top--;
		return tmp;
	}
}

element peek(StackType *s) {// 피크함수
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(0);
	}
	else return s->stack[s->top];
}


double check_matching(char in[])
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);

	init(&s); // 스택 초기화

	for (i = 0; i < n; i++) { // i=0; while( in[i] != '\0')
		ch = in[i];
		switch (ch){
		case '(':
		case '[':
		case '{':
			push(&s, ch);
			break;
		case ')':
		case ']':
		case '}':
			if (is_empty(&s)) return false;
			open_ch = pop(&s);
			if ((open_ch == '(' && ch != ')') ||
				(open_ch == '{' && ch != '}') ||
				(open_ch == '[' && ch != ']')) return false;
			break;
		}
	}
	if (!is_empty(&s)) return false;
	return true;
}

double eval(char exp[])
{
	double op1, op2, value;
	int len = strlen(exp);
	char ch;
	StackType s;

	init(&s);
	for (int i = 0; i<len; i++){
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')  // 입력이 피연산자이면 ;
		{
			value = ch - '0';
			push(&s, value);
		}
		else{  //연산자이면 피연산자를 스택에서 제거 
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch){ //연산을 수행하고 스택에 저장 
			case '+': value = op2 + op1; push(&s, value); break;
			case '-': value = op2 - op1; push(&s, value); break;
			case '*': value = op2 * op1; push(&s, value); break;
			case '/': value = op2 / op1; push(&s, value); break;
			}
		}
	}
	value = pop(&s);
	return value;
}


// 우선순위
int prec(int op)
{
	switch (op) {
	case '(':     case ')':     return 0;
	case '+':     case '-':     return 1;
	case '*':     case '/':     return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[], char post[])
{
	int i = 0, j = 0; // j는 post의 index
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init(&s);					// 스택 초기화 
	for (i = 0; i<len; i++){
		ch = exp[i];
		// 연산자이면
		switch (ch){
		case '+': case '-': case '*': case '/': // 연산자

			// 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				post[j++] = pop(&s);

			push(&s, ch);
			break;
		case '(':	// 왼쪽 괄호
			push(&s, ch);
			break;
		case ')':	// 오른쪽 괄호
			top_op = pop(&s);
			// 왼쪽 괄호를 만날때까지 출력
			while (top_op != '('){
				post[j++] = top_op;
				top_op = pop(&s);
			}
			break;
		default:		// 피연산자
			post[j++] = ch;
			break;
		}
	}

	while (!is_empty(&s))	// 스택에 저장된 연산자들 출력
		post[j++] = pop(&s);
	post[j] = '\0'; // 중요!!
}


int main()
{
	char input[100];
	char post[100];

		printf("수식 입력 >>> ");
		scanf("%s", input);
		if (check_matching(input)){
			printf("수식의 짝이 맞음\n");
			infix_to_postfix(input, post);
			printf("수식 계산 결과 >>> %.2f\n", eval(post));
		}
		else {
			printf("수식의 짝이 틀림\n");
		}

	return 0;
}


