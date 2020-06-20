#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <memory>
#include "queue.hh"
#include "consumer.hh"
#include "producer.hh"
#include "sleepThread.hh"
using namespace std;

Producer::Producer()
{
	data.number[0] = ++threadCounter;
	data.number[1] = 0;
}
void Producer::operator()()
{
	while (!isFinish())
	{
		++data.number[1];
		mtx.lock();
		enQueue(data.data);
		mtx.unlock();
		FactorySleepThread::create()->sleep(100);
	}
}

bool Producer::isFinish() { return Consumer::isFinish(); }
void Producer::enQueue(unsigned long data) { q.enQueue(data); }

int Producer::threadCounter = 0;
mutex Producer::mtx;
