#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <memory>
#include "sleepThread.hh"
using namespace std;

void SleepThread::sleep(unsigned int millisecond) { this_thread::sleep_for(chrono::milliseconds(millisecond)); }

shared_ptr<ISleepThread> FactorySleepThread::create()
{
    if (sleepThread)
        return sleepThread;
    return make_shared<SleepThread>();
}

void FactorySleepThread::setSleepThread(shared_ptr<ISleepThread> st)
{
    sleepThread = st;
}
shared_ptr<ISleepThread> FactorySleepThread::sleepThread;