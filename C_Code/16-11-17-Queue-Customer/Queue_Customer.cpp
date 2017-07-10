#include "queue.h"

//�ʱ�ȭ
void init(QueueType *q)
{
	q->front = 0;
	q->rear = 0;
}


// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	//�ڵ� �߰�
	return q->front == q->rear;
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	//�ڵ� �߰�
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType *q, element item) // ���� �Լ�
{
	if (is_full(q))
	{
		printf("ť�� ��ȭ�����Դϴ�"); exit(0);
	}
	//�ڵ� �߰�
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType *q) // ���� �Լ�
{
	if (is_empty(q)){
		printf("ť�� ��������Դϴ�"); exit(0);
	}
	//�ڵ� �߰�
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

// 0���� 1������ �Ǽ� ���� ���� �Լ�
double random()
{
	return rand() / (double)RAND_MAX;
}

int duration = 1000;         // �ùķ��̼� �ð� 
double arrival_prob = 0.5; // �ϳ��� �ð� ������ �����ϴ� ��� ���� ��
int max_serv_time = 5; // �ϳ��� ���� ���� �ִ� ���� �ð�
int current_clock;

int customers = 0;         // ��ü����
int served_customers;  // ���񽺹��� ����
int waited_time;      // ������ ��ٸ� �ð�

// ���� ���ڸ� �����Ͽ� ���� �����ߴ��� �������� �ʾҴ����� �Ǵ�
int is_customer_arrived()
{
	if (random() < arrival_prob)
		return true;
	else return false;
}

// ���� ������ ���� ť�� ����
void insert_customer(int arrival_time)
{
	element customer;

	customer.id = customers++;
	customer.arrival_time = arrival_time;
	customer.service_time = (int)(max_serv_time*random()) + 1;
	//ť�� �߰�
	enqueue(&Q, customer);
	printf("�� < %d >��(��) %d�п� ���ɴϴ�. ���񽺽ð��� %d���Դϴ�.\n",
		customer.id, customer.arrival_time, customer.service_time);
}

// ť���� ��ٸ��� ���� ������ ���� ���� �ð��� ��ȯ�Ѵ�.
int remove_customer()
{
	element customer;
	int service_time = 0;

	if (is_empty(&Q)) return 0;
	//ť���� ���� �����Ͽ� customer�� ����
	customer = dequeue(&Q);
	service_time = customer.service_time - 1;
	served_customers++;
	waited_time += (current_clock - customer.arrival_time);
	printf("�� < %d >��(��) %d�п� ���񽺸� �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
		customer.id, current_clock, current_clock - customer.arrival_time);
	return service_time;
}

// ���ġ�� ����Ѵ�.
void print_stat()
{
	printf("\n############################## \n");
	printf("���񽺹��� ���� = %d\n", served_customers);
	printf("��ü ��� �ð� = %d��\n", waited_time);
	printf("1�δ� �� ��� �ð� = %.2f��\n", (double)waited_time / served_customers);
	printf("���� ������� ���� = %d\n", customers - served_customers);
}


// �ùķ��̼� ���α׷�
void main()
{
	/*int service_time = 0;
	current_clock = 0;

	init(&Q);
	srand((unsigned int)time(NULL));
	while (current_clock < duration)
	{
		current_clock++;
		printf("����ð�=%d\n", current_clock);
		if (is_customer_arrived())
		{
			insert_customer(current_clock);
		}
		if (service_time > 0)
			service_time--;
		else
		{
			service_time = remove_customer();
		}
	}

	print_stat();*/

}