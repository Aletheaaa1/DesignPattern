#include "TaskQueue.h"

TaskQueue::~TaskQueue()
{
}

TaskQueue* TaskQueue::GetInstance()
{
	//	未初始化，所有并发执行应等待初始化的完成
	static TaskQueue task;
	return &task;
}

void TaskQueue::Print() const
{
	std::cout << "This is a singletion instance \n";
}