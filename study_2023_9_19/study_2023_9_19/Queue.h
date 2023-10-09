#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include <stdlib.h>
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;//������
	QDataType data;//������
}QNode;

typedef struct	Queue
{
	QNode* phead;//ͷ�ڵ�
	QNode* ptail;//β�ڵ�
	QDataType size; //ͳ���ж��ٽڵ�
}Queue;

void QueueInit(Queue *pq);//��ʼ��  
void QueueDestroy(Queue*pq);//����
void QueuePush(Queue*pq,QDataType x);//��������
void QueuePop(Queue* pq);//��ͷ�����ݾ���ɾ��ͷ
QDataType QueueFront(Queue* pq);//���ض�ͷ����
QDataType QueueBack(Queue* pq);//���ض�β����
int QueueSize(Queue* pq);//�����ܵ����ݸ���
bool QueueEmpty(Queue* pq);//�ǿյķ�����