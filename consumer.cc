#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <memory>
#include "consumer.hh"
#include "sleepThread.hh"
using namespace std;
extern Queue q;

Consumer::Consumer(int count) { maxCount = count; }
void Consumer::operator()()
{
    for (int counter = 0; counter < maxCount;)
    {
        data.data = deQueue();
        if (data.data == 0)
            continue;
        counter++;
        print(data);
        FactorySleepThread::create()->sleep(100);
    }
    finish = true;
}
inline unsigned long Consumer::deQueue() { return q.deQueue(); }

inline void Consumer::print(const Data &value)
{
    cout << "Thread " << value.number[0] << " : " << value.number[1] << endl;
}
bool Consumer::isFinish() { return finish; }
bool Consumer::finish = false;