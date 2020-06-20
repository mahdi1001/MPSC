#ifndef __SLEEPTHREAD__
#define __SLEEPTHREAD__
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <memory>
using namespace std;

class ISleepThread
{
public:
    ISleepThread() = default;
    virtual ~ISleepThread() = default;
    virtual void sleep(unsigned int millisecond) = 0;
};

class SleepThread : public ISleepThread
{
public:
    SleepThread() = default;
    virtual ~SleepThread() = default;
    void sleep(unsigned int millisecond);
};

class FactorySleepThread
{
public:
    static shared_ptr<ISleepThread> create();
    static void setSleepThread(shared_ptr<ISleepThread> st);

private:
    static shared_ptr<ISleepThread> sleepThread;
};
#endif