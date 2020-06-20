#ifndef __CONSUMER__
#define __CONSUMER__
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <memory>
#include "queue.hh"
using namespace std;

union Data {
    unsigned int number[2];
    unsigned long data;
};

class Consumer
{
public:
    Consumer(int count);
    static bool isFinish();
    void operator()();

protected:
    virtual unsigned long deQueue();
    inline void print(const Data &value);
    int maxCount;
    Data data;
    static bool finish;
};
#endif