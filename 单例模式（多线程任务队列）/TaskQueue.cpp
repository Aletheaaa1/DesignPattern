#include "TaskQueue.h"
TaskQueue* TaskQueue::GetInstance()
{
	static TaskQueue task;
	return &task;
}

bool TaskQueue::IsEmpty()
{
	return data.empty();
}

void TaskQueue::AddTask(int node)
{
	data.push(node);
}

bool TaskQueue::RemoveTask()
{
	if (!data.empty())
	{
		data.pop();
		return true;
	}
	else
	{
		return false;
	}
}

int TaskQueue::GetTask()
{
	if (data.empty())
	{
		return -1;
	}
	else
	{
		return data.front();
	}
}