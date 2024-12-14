#include<iostream>
#include<thread>
#include<Windows.h>
#include<vector>

void foo(std::vector<int> v1, std::vector<int> v2, std::vector<int>& answ, int startind, int endind);

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
		int q = 1000;
		while(q<=1000000)
		{
			int dsize = q / qth;
			int curind = 0;
			std::vector<int> v1(q);
			std::vector<int> v2(q);
			std::vector<int> answ(q);
			auto start = std::chrono::steady_clock::now();
			for (int i = 0; i < threads.size(); i++)
			{
				threads[i] = std::thread(foo, v1, v2, std::ref(answ), curind, (curind+dsize-1));
				curind += dsize;
				threads[i].join();
			}
			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsedSeconds = end - start;
			std::cout << elapsedSeconds.count() << "\t";
			q *= 10;
		}
		std::cout << "\n";
		qth *= 2;
	}
	
	return 0;
}

void foo(std::vector<int> v1, std::vector<int> v2, std::vector<int>& answ, int startind, int endind)
{
	for (int i = startind; i <= endind; i++)
	{
		answ[i] = v1[i] + v2[i];
	}
}