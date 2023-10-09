#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include <stdlib.h>
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;//单链表
	QDataType data;//放数据
}QNode;

typedef struct	Queue
{
	QNode* phead;//头节点
	QNode* ptail;//尾节点
	QDataType size; //统计有多少节点
}Queue;

void QueueInit(Queue *pq);//初始化  
void QueueDestroy(Queue*pq);//销毁
void QueuePush(Queue*pq,QDataType x);//插入数据
void QueuePop(Queue* pq);//队头出数据就是删队头
QDataType QueueFront(Queue* pq);//返回对头数据
QDataType QueueBack(Queue* pq);//返回队尾数据
int QueueSize(Queue* pq);//返回总的数据个数
bool QueueEmpty(Queue* pq);//是空的返回真