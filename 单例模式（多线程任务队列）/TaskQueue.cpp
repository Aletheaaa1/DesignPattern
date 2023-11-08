#include "TaskQueue.h"
TaskQueue* TaskQueue::GetInstance()
{
	static TaskQueue task;
	return &task;
}

bool TaskQueue::IsEmpty()
{
	std::unique_lock<std::mutex> lock(mutex);
	return data.empty();
}

void TaskQueue::AddTask(int node)
{
	std::unique_lock<std::mutex> lock(mutex);
	data.push(node);
}

int TaskQueue::RemoveTask()
{
	std::unique_lock<std::mutex> lock(mutex);
	if (!data.empty())
	{
		int front = data.front();
		data.pop();
		return 	front;
	}
	else
	{
		return -1;
	}
}

int TaskQueue::GetTask()
{
	std::unique_lock<std::mutex> lock(mutex);
	if (data.empty())
	{
		return -1;
	}
	else
	{
		return data.front();
	}
}