#include<iostream>
#include<thread>
#include<Windows.h>
#include<vector>

void foo1(int qth);
void foo2(int qth);
void foo3(int qth);
void foo4(int qth);

int main()
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	int numCPU = sysInfo.dwNumberOfProcessors;
	int qth = 1;
	while (qth <= 16)
	{
		if (qth == 1)
		{
			std::cout << "Number of hardware cores: " << numCPU << "\n\n";
			std::cout << "\t   1000\t\t10000\t\t100000\t\t1000000\n";
		}
		std::cout << qth << " streams: ";
		
		std::vector<std::thread> threads(qth);
		for (int j = 0; j < 4; j++)
		{
			if (j == 0)
			{
				auto start = std::chrono::steady_clock::now();
				for (int i = 0; i < threads.size(); i++)
				{
					threads[i] = std::thread(foo1, qth);
					threads[i].join();
				}
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsedSeconds = end - start;
				std::cout << elapsedSeconds.count() << "\t";
			}
			else if (j == 1)
			{
				auto start = std::chrono::steady_clock::now();
				for (int i = 0; i < threads.size(); i++)
				{
					threads[i] = std::thread(foo2, qth);
					threads[i].join();
				}
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsedSeconds = end - start;
				std::cout << elapsedSeconds.count() << "\t";
			}
			else if (j == 2)
			{
				auto start = std::chrono::steady_clock::now();
				for (int i = 0; i < threads.size(); i++)
				{
					threads[i] = std::thread(foo3, qth);
					threads[i].join();
				}
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsedSeconds = end - start;
				std::cout << elapsedSeconds.count() << "\t";
			}
			else
			{
				auto start = std::chrono::steady_clock::now();
				for (int i = 0; i < threads.size(); i++)
				{
					threads[i] = std::thread(foo4, qth);
					threads[i].join();
				}
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsedSeconds = end - start;
				std::cout << elapsedSeconds.count() << "\t" << "\n";
			}
		}
		qth *= 2;
	}
	
	return 0;
}

void foo1(int qth)
{
	int size = 1000/qth;
	std::vector<int> v1(size);
	std::vector<int> v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] += v2[i];
	}
}

void foo2(int qth)
{
	int size = 10000/qth;
	std::vector<int> v1(size);
	std::vector<int> v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] += v2[i];
	}
}

void foo3(int qth)
{
	int size = 100000/qth;
	std::vector<int> v1(size);
	std::vector<int> v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] += v2[i];
	}
}

void foo4(int qth)
{
	int size = 100000/qth;
	std::vector<int> v1(size);
	std::vector<int> v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] += v2[i];
	}
}