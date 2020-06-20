#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "../consumer.hh"
#include "../producer.hh"
#include "../sleepThread.hh"

using namespace ::testing;
Queue q;
class FakeSleepThread : public ISleepThread
{
public:
    void sleep(unsigned int millisecond) override {}
};
class testingProducer : public Producer
{
public:
    testingProducer() { finish = 1; }
    unsigned int getThreadCounter() {return data.number[0]; }
    unsigned int getCounter() { return data.number[1]; }
    static int finish;

private:
    bool isFinish() { return !(--finish); }
    void enQueue(unsigned long data) {}
};
int testingProducer::finish;

TEST(producer, checkThreadCounter)
{
    testingProducer p;
    EXPECT_EQ(p.getThreadCounter(), 1);
}

TEST(producer, checkCounterIsZero)
{
    testingProducer p;
    p();
    EXPECT_EQ(p.getCounter(), 0);
}

TEST(producer, checkCounterIsOne)
{
    testingProducer p;
    p.finish=2;
    FactorySleepThread::setSleepThread(make_shared<FakeSleepThread>());
    p();
    EXPECT_EQ(p.getCounter(), 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
