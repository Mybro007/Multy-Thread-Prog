#include<iostream>
#include<thread>

void foo1(int& counter, int maxClient)
{
	if (counter < maxClient)
	{
		counter++;
	}
}

void foo2(int& counter)
{
	if (counter > 0)
	{
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
	cl.detach();
	std::thread op(foo2, std::ref(counter));
	op.join();
	return 0;
}