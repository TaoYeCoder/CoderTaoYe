#include"Queue.h"

void QueueInit(Queue* pq)//��ʼ�� 
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}



void QueueDestroy(Queue* pq)//����
{
	assert(pq);
	//��һ���ṹ��
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}


void QueuePush(Queue* pq, QDataType x)//��������
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));//������ǵ�һ���ṹ��
	if (newnode == NULL)
	{
		perror("malloc");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->phead == NULL)
	{

		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}


void QueuePop(Queue* pq)//��ͷ�����ݾ���ɾ��ͷ
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)//���ض�ͷ����
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}

QDataType QueueBack(Queue* pq)//���ض�β����
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}

int QueueSize(Queue* pq)//�����ܵ����ݸ���
{
	assert(pq);

	return pq->size;
}

bool QueueEmpty(Queue* pq)//�ǿյķ�����
{
	assert(pq);

	return pq->phead == NULL && pq->ptail == NULL;
}