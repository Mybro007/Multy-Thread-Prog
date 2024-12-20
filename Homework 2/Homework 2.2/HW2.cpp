#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
#include <mutex>
#include <atomic>

std::mutex printMutex;  // ������� ��� ������������� ������

// ������� ��� �������� ������ ������
void calculate(int threadNumber, int totalTime, int totalSteps) {
    auto start = std::chrono::high_resolution_clock::now();  // �������� ����� ������ ������ ������

    //int stepDuration = totalTime / totalSteps;  // ����� ��� ������ ����

    for (int i = 0; i < totalSteps; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // �������� ��� �������� ������

        // ���������� ��� ������������� ������
        {
            std::lock_guard<std::mutex> lock(printMutex);

            // ��� ������� ������ ������� ��� ���������� ����� � ���������� id
            std::cout << "\r" << std::setw(2) << threadNumber
                << "   " << std::setw(16) << std::this_thread::get_id()
                << "   ";

            // ��������� ��������-��� ��� �������� ������
            for (int j = 0; j <= i; ++j) {
                std::cout << char(219);  // ���������� ������ ��� ������������
            }
            for (int j = i + 1; j < totalSteps; ++j) {
                std::cout << " ";  // ������ �����
            }

            // �������� ������ ����� ��������
            std::cout << " ";

            // ��������� �����
            std::flush(std::cout);
        }
    }

    // ������������ ����� ������ ������
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    //�������� ����� ������ ������
    std::cout << " " << std::setw(10) << std::fixed << std::setprecision(2) << duration.count() << " sec" << "\n";

}

int main() {
    int numThreads, totalTime;

    std::cout << "Enter the number of threads: ";
    std::cin >> numThreads;
    std::cout << "Enter the total time for each thread (in milliseconds): ";
    std::cin >> totalTime;

    int totalSteps = 44;

    std::cout << std::setw(2) << "#" << "   "
        << std::setw(16) << "id" << "   "
        << std::setw(25) << "Progress Bar" << "   "
        << std::setw(28) << "Time" << std::endl;

    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(calculate, i, totalTime, totalSteps));
        threads[i].join();
    }

    std::cout << "\nAll threads have finished." << std::endl;
    return 0;
}
