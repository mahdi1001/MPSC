
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <memory>
#include "sleepThread.hh"
#include "queue.hh"
#include "producer.hh"
#include "consumer.hh"
using namespace std;

Queue q;

int main(int argc, char *argv[])
{
	if (argc != 3)
		return 0;
	int numOfProducerThread = atoi(argv[1]);
	int count = atoi(argv[2]);

	thread *producerThread = new thread[numOfProducerThread];
	for (int index = 0; index < numOfProducerThread; index++)
		producerThread[index] = thread((Producer()));
	thread consumerThread((Consumer(count)));

	consumerThread.join();
	for (int index = 0; index < numOfProducerThread; index++)
		producerThread[index].join();

	cout << "FINISH!\n";
}
