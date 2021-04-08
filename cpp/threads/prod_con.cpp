#include <iostream>
#include <mutex>
#include <condition_variable>
#include <cstdlib>
#include <thread>
using namespace std;

mutex gmutex;
condition_variable gcv;

bool ready = false;
int data = 0;

int produceData()
{
    for (int i = 0; i < 100; ++i)
    {
        int num = rand() % 1000;
        cout << "\n Produced Data : " << num;
        return num;
    }
}

void consumeData(int data)
{
    cout << "\n Consume Data : " << data;
}

void consume()
{
    while (true)
    {
        unique_lock<mutex> lck(gmutex);
        gcv.wait(lck, []() { return ready; });
        consumeData(data);
        ready = false;
        lck.unlock();
        gcv.notify_one();
    }
}

void produce()
{
    while (true)
    {
        unique_lock<mutex> lck(gmutex);
        data = produceData();
        ready = true;
        lck.unlock();
        gcv.notify_one();
        lck.lock();
        gcv.wait(lck, []() { return ready == false; });
    }
}

void startConsumer(int times) { consume(); }
void startProducer(int times) { produce(); }

int main()
{
    thread t1(startConsumer);
    thread t2(startProducer);
    t1.join();
    t2.join();
}