#ifndef __PRODUCER__
#define __PRODUCER__
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <memory>
#include "queue.hh"
#include "consumer.hh"
using namespace std;

extern Queue q;

class Producer
{
public:
	Producer();
	void operator()();

protected:
	virtual bool isFinish();
	virtual void enQueue(unsigned long data);

protected:
	static mutex mtx;
	static int threadCounter;
	Data data;
};
#endif