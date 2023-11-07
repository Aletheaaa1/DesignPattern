#include <iostream>

#include "TaskQueue.h"

int main()
{
	TaskQueue* task = TaskQueue::GetInstance();
	TaskQueue* task2 = TaskQueue::GetInstance();
	std::cout << &(*task) << "  " << &(*task2);
}