#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <memory>
#include "queue.hh"
using namespace std;

Queue::Queue()
{
	size = 0;
	tail = 0;
	head = 0;
}
void Queue::enQueue(unsigned long data)
{
	if (!isFull())
	{
		q[tail++] = data;
		tail = tail & (MAX_QUEUE_SIZE - 1);
		++size;
	}
}
inline bool Queue::isFull() { return size == (MAX_QUEUE_SIZE - 1); }
inline bool Queue::isEmpty() { return size == 0; }
unsigned long Queue::deQueue()
{
	unsigned long data = 0;
	if (!isEmpty())
	{
		data = q[head++];
		head = head & (MAX_QUEUE_SIZE - 1);
		--size;
	}
	return data;
}