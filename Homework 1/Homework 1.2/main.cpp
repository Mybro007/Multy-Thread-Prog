#include<iostream>
#include<thread>
#include<Windows.h>
#include<vector>

void f1(int numCPU);
void f2();
void f4();
void f8();
void f16();

void foo1();
void foo2();
void foo3();
void foo4();

int main()
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	int numCPU = sysInfo.dwNumberOfProcessors;
	std::thread t1(f1, numCPU);
	t1.join();
	
	return 0;
}

void foo1()
{
	int size = 1000;
	std::vector<int> v1(size);
	std::vector<int> v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] += v2[i];
	}
}

void foo2()
{
	int size = 10000;
	std::vector<int> v1(size);
	std::vector<int> v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] += v2[i];
	}
}

void foo3()
{
	int size = 100000;
	std::vector<int> v1(size);
	std::vector<int> v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] += v2[i];
	}
}

void foo4()
{
	int size = 100000;
	std::vector<int> v1(size);
	std::vector<int> v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] += v2[i];
	}
}

void f1(int numCPU)
{
	std::cout << "Number of hardware cores: " << numCPU << "\n\n";
	std::cout << "\t   1000\t\t10000\t\t100000\t\t1000000\n";

	std::cout << "1 streams: ";
	auto start = std::chrono::steady_clock::now();
	foo1();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsedSeconds = end - start;
	std::cout << elapsedSeconds.count() << "\t";

	start = std::chrono::steady_clock::now();
	foo2();
	end = std::chrono::steady_clock::now();
	elapsedSeconds = end - start;
	std::cout << elapsedSeconds.count() << "\t";

	start = std::chrono::steady_clock::now();
	foo3();
	end = std::chrono::steady_clock::now();
	elapsedSeconds = end - start;
	std::cout << elapsedSeconds.count() << "\t";

	start = std::chrono::steady_clock::now();
	foo4();
	end = std::chrono::steady_clock::now();
	elapsedSeconds = end - start;
	std::cout << elapsedSeconds.count() << "\t";
}

void oneThread()
{

}

void f2()
{

}