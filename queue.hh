#ifndef __QUEUE__ 
#define __QUEUE__
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <memory>
using namespace std;

static const unsigned char MAX_QUEUE_SIZE = 16; //Must be power of 2
class Queue
{
public:
	Queue();
	~Queue() = default;
	Queue(Queue &) = delete;
	Queue(Queue &&) = delete;
	void enQueue(unsigned long data);
	inline bool isFull();
	inline bool isEmpty();
	unsigned long deQueue();
private:
	unsigned long q[MAX_QUEUE_SIZE];
	atomic<unsigned int> size;
	unsigned int head;
	unsigned int tail;
};
#endif