#include<iostream>
#include <chrono>
#include<thread>

void foo1(int& counter, int maxClient)
{
	while (counter <= maxClient)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		counter++;
	}
}

void foo2(int& counter)
{
	while (counter != 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		counter--;
	}
}

int main()
{
	int counter{ 0 };
	int maxClient{};
	std::cout << "Input the MAX quantity of clients: ";
	std::cin >> maxClient;
	std::thread cl(foo1, std::ref(counter), maxClient);
	std::thread op(foo2, std::ref(counter));
	cl.detach();
	op.join();
	return 0;
}