#define MAX_QUEUE_SIZE 500
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//typedef int element;

typedef struct {
	int id;
	int arrival_time;
	int service_time;
} element;

typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

QueueType Q;


