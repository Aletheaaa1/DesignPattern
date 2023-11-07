#include "TaskQueue.h"

TaskQueue* TaskQueue::task = new TaskQueue();

TaskQueue::~TaskQueue()
{
	delete task;
}

TaskQueue* TaskQueue::GetInstance()
{
	return task;
}

void TaskQueue::Print() const
{
	std::cout << "This is a singletion instance \n";
}