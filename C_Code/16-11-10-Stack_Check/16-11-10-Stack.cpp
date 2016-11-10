#include "stack.h"
#include <string.h>

// ���� �ʱ�ȭ �Լ�
void init(StackType *s) {
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s){
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {  // �����Լ�
	if (is_full(s))
	{
		printf("���� ��ȭ ���� \n");
		exit(0);
	}
	else
	{
		s->top++;
		s->stack[s->top] = item;
	}
}

element pop(StackType *s) { // �����Լ�
	if (is_empty(s))
	{
		printf("���� ���� ����\n");
		exit(0);
	}
	else
	{
		element tmp = s->stack[s->top];
		s->top--;
		return tmp;
	}
}

element peek(StackType *s) {// ��ũ�Լ�
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(0);
	}
	else return s->stack[s->top];
}


double check_matching(char in[])
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);

	init(&s); // ���� �ʱ�ȭ

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
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')  // �Է��� �ǿ������̸� ;
		{
			value = ch - '0';
			push(&s, value);
		}
		else{  //�������̸� �ǿ����ڸ� ���ÿ��� ���� 
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch){ //������ �����ϰ� ���ÿ� ���� 
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


// �켱����
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
	int i = 0, j = 0; // j�� post�� index
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init(&s);					// ���� �ʱ�ȭ 
	for (i = 0; i<len; i++){
		ch = exp[i];
		// �������̸�
		switch (ch){
		case '+': case '-': case '*': case '/': // ������

			// ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				post[j++] = pop(&s);

			push(&s, ch);
			break;
		case '(':	// ���� ��ȣ
			push(&s, ch);
			break;
		case ')':	// ������ ��ȣ
			top_op = pop(&s);
			// ���� ��ȣ�� ���������� ���
			while (top_op != '('){
				post[j++] = top_op;
				top_op = pop(&s);
			}
			break;
		default:		// �ǿ�����
			post[j++] = ch;
			break;
		}
	}

	while (!is_empty(&s))	// ���ÿ� ����� �����ڵ� ���
		post[j++] = pop(&s);
	post[j] = '\0'; // �߿�!!
}


int main()
{
	char input[100];
	char post[100];

		printf("���� �Է� >>> ");
		scanf("%s", input);
		if (check_matching(input)){
			printf("������ ¦�� ����\n");
			infix_to_postfix(input, post);
			printf("���� ��� ��� >>> %.2f\n", eval(post));
		}
		else {
			printf("������ ¦�� Ʋ��\n");
		}

	return 0;
}


