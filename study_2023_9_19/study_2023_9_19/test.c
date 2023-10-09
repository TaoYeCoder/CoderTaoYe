#include"Queue.h"
void MyQueue1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("Size:%d\n", QueueSize(&q));
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q)); 
		QueuePop(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}
int main()
{
	MyQueue1();
	return 0;
}