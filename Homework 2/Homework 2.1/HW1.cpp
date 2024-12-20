#include<iostream>
#include <chrono>
#include<thread>
#include <atomic>

void foo1(std::atomic<int>& counter, int maxClient)
{
    while (counter.load() <= maxClient)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        counter.fetch_add(1);
    }
}

void foo2(std::atomic<int>& counter)
{
    while (counter.load() != 0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        counter.fetch_sub(1);
    }
}

int main()
{
    std::atomic<int> counter{ 0 };
    int maxClient{};
    std::cout << "Input the MAX quantity of clients: ";
    std::cin >> maxClient;
    std::thread cl(foo1, std::ref(counter), maxClient);
    std::thread op(foo2, std::ref(counter));
    cl.detach(); 
    op.join(); 
    return 0;
}