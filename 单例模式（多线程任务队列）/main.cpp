#include <iostream>
#include <thread>
#include <chrono>

#include "TaskQueue.h"
int main()
{
	TaskQueue* task = TaskQueue::GetInstance();

	std::thread t1(
		[=]() {
			for (int i = 0; i < 5; i++)
			{
				task->AddTask(i);
				std::cout << "+++ push data: " << 100 + i << ", threadID: " << std::this_thread::get_id() << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
			}
		}
	);
	t1.join();

	std::thread t2(
		[=]() {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			while (!task->IsEmpty())
			{
				int num = task->GetTask();
				task->RemoveTask();
				std::cout << "+++ take data: " << 100 + num << ", threadID: " << std::this_thread::get_id() << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
	);
	std::thread t3(
		[=]() {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			while (!task->IsEmpty())
			{
				int num = task->GetTask();
				task->RemoveTask();
				std::cout << "+++ take data: " << 100 + num << ", threadID: " << std::this_thread::get_id() << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
	);

	t2.join();
	t3.join();
}