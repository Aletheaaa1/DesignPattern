#include "TaskQueue.h"

std::atomic<TaskQueue*> TaskQueue::task = nullptr;
std::mutex TaskQueue::instance_mutex;

TaskQueue::~TaskQueue()
{
	delete task.load();
}

TaskQueue* TaskQueue::GetInstance()
{
	//	Ë«ÖØ¼ì²éËø¶¨
	auto task_instance = task.load();
	if (task_instance == nullptr)
	{
		std::unique_lock<std::mutex> lk(instance_mutex);

		task_instance = task.load();
		if (task_instance == nullptr)
		{
			task_instance = new TaskQueue();
			task.store(task_instance);
		}
	}

	return task_instance;
}

void TaskQueue::Print() const
{
	std::cout << "This is a singletion instance \n";
}