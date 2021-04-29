// Thread barriar is where there multiple thread are joied.

#include<iostream>
#include<thread>
#include<vector>

int main(){
    std::vector<std::thread> workers;
    for (int i=0;i<10;++i){
        workers.emplace_back(std::thread([i](){
            std::cout<<"Hi from thread."<<i<<"\n"; //Output is distored as each thread is doing the same thing.
            })
        );
    }
    std::cout<<"Hi from main.\n";
    for(std::thread& th:workers) // Thread Barriar
        th.join();
}