/*
C++11:
Threading Support:
    Thread, mutex, condition, variable, future, packaged_task
Memory Model:
    Atomic, fence
Others:
    Lambda, mode semantics

Books
    Anthony Williams, C++ Concurrency in Action
    Colin Campbell, Parallel Programming with Microsoft C++
    Maurice Helihy, The Art of Mulltipricessor Programming
*/
#include<iostream>
#include<thread>

void threadFunction(){
    std::cout<<"Hello from Thread \n ";
}

int main(){
    std::thread th1(&threadFunction);//Constructor takes Function, Arguments can be passed with comma (,)
    std::cout<<"Hello from main \n"; // Main Thread
    th.join(); // Join worker thread
    /* OUTPUT
    Hello from main 
    Hello from Thread 

    Here, threadFunction is called first in the sequence and then next line is executed in main.
    But, as there is overhead of creating and calling thread, main thread printed first.
    */

    // USING lambda

    std::thread th2([](){
        std::cout<<"Hello from th2 \n";
        });
    th2.join();
    return 0;



}