#include "queue.h"

//초기화
void init(QueueType *q)
{
	q->front = 0;
	q->rear = 0;
}


// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	//코드 추가
	return q->front == q->rear;
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	//코드 추가
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType *q, element item) // 삽입 함수
{
	if (is_full(q))
	{
		printf("큐가 포화상태입니다"); exit(0);
	}
	//코드 추가
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType *q) // 삭제 함수
{
	if (is_empty(q)){
		printf("큐가 공백상태입니다"); exit(0);
	}
	//코드 추가
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

// 0에서 1사이의 실수 난수 생성 함수
double random()
{
	return rand() / (double)RAND_MAX;
}

int duration = 1000;         // 시뮬레이션 시간 
double arrival_prob = 0.5; // 하나의 시간 단위에 도착하는 평균 고객의 수
int max_serv_time = 5; // 하나의 고객에 대한 최대 서비스 시간
int current_clock;

int customers = 0;         // 전체고객수
int served_customers;  // 서비스받은 고객수
int waited_time;      // 고객들이 기다린 시간

// 랜덤 숫자를 생성하여 고객이 도착했는지 도착하지 않았는지를 판단
int is_customer_arrived()
{
	if (random() < arrival_prob)
		return true;
	else return false;
}

// 새로 도착한 고객을 큐에 삽입
void insert_customer(int arrival_time)
{
	element customer;

	customer.id = customers++;
	customer.arrival_time = arrival_time;
	customer.service_time = (int)(max_serv_time*random()) + 1;
	//큐에 추가
	enqueue(&Q, customer);
	printf("고객 < %d >이(가) %d분에 들어옵니다. 서비스시간은 %d분입니다.\n",
		customer.id, customer.arrival_time, customer.service_time);
}

// 큐에서 기다리는 고객을 꺼내어 고객의 서비스 시간을 반환한다.
int remove_customer()
{
	element customer;
	int service_time = 0;

	if (is_empty(&Q)) return 0;
	//큐에서 고객을 삭제하여 customer에 저장
	customer = dequeue(&Q);
	service_time = customer.service_time - 1;
	served_customers++;
	waited_time += (current_clock - customer.arrival_time);
	printf("고객 < %d >이(가) %d분에 서비스를 시작합니다. 대기시간은 %d분이었습니다.\n",
		customer.id, current_clock, current_clock - customer.arrival_time);
	return service_time;
}

// 통계치를 출력한다.
void print_stat()
{
	printf("\n############################## \n");
	printf("서비스받은 고객수 = %d\n", served_customers);
	printf("전체 대기 시간 = %d분\n", waited_time);
	printf("1인당 평군 대기 시간 = %.2f분\n", (double)waited_time / served_customers);
	printf("아직 대기중인 고객수 = %d\n", customers - served_customers);
}


// 시뮬레이션 프로그램
void main()
{
	/*int service_time = 0;
	current_clock = 0;

	init(&Q);
	srand((unsigned int)time(NULL));
	while (current_clock < duration)
	{
		current_clock++;
		printf("현재시각=%d\n", current_clock);
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