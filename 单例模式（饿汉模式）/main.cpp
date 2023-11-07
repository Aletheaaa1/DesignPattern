#include <iostream>
#include "TaskQueue.h"

int main()
{
	TaskQueue* task = TaskQueue::GetInstance();
	task->Print();
	return 0;
}