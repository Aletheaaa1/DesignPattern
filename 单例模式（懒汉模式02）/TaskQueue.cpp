#include "TaskQueue.h"

TaskQueue::~TaskQueue()
{
}

TaskQueue* TaskQueue::GetInstance()
{
	//	δ��ʼ�������в���ִ��Ӧ�ȴ���ʼ�������
	static TaskQueue task;
	return &task;
}

void TaskQueue::Print() const
{
	std::cout << "This is a singletion instance \n";
}