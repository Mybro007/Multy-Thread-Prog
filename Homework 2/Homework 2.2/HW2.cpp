#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
#include <mutex>
#include <atomic>

std::mutex printMutex;  // Мьютекс для синхронизации вывода

// Функция для имитации работы потока
void calculate(int threadNumber, int totalSteps) {
    auto start = std::chrono::high_resolution_clock::now();  // Засекаем время начала работы потока

    // Задержка для имитации работы
    for (int i = 0; i < totalSteps; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Блокировка для синхронизации вывода
        {
            std::lock_guard<std::mutex> lock(printMutex);

            // Переход на нужную строку для потока
            std::cout << "\033[" << threadNumber + 3 << ";0H"; // Перемещение курсора на нужную строку

            // Отображение прогресс-бара для текущего потока
            std::cout << std::setw(2) << threadNumber << "   "
                << std::setw(16) << std::this_thread::get_id()
                << "  ";

            for (int j = 0; j <= i; ++j) {
                std::cout << char(219);  // Используем символ для закрашивания
            }
            for (int j = i + 1; j < totalSteps; ++j) {
                std::cout << " ";  // Пустое место
            }

            // Печатаем отступ перед временем
            std::cout << " ";
        }
    }

    // Подсчитываем время работы потока
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    // Блокируем вывод времени потока
    {
        std::lock_guard<std::mutex> lock(printMutex);
        // Переход на строку для вывода времени работы
        std::cout << "\033[" << threadNumber + 3 << ";" << totalSteps + 22 << "H"; // Возвращаемся к нужной строке
        std::cout << " " << std::setw(10) << std::setprecision(2) << duration.count() << " sec" << "\n";
    }
}

int main() {
    int numThreads, totalTime;

    std::cout << "Enter the number of threads: ";
    std::cin >> numThreads;

    int totalSteps = 44;

    // Вывод заголовка
    std::cout << std::setw(2) << "#" << "   "
        << std::setw(16) << "id" << "   "
        << std::setw(25) << "Progress Bar" << "   "
        << std::setw(28) << "Time" << std::endl;

    // Инициализация и запуск потоков
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(calculate, i, totalSteps));
    }

    // Ожидание завершения всех потоков
    for (auto& th : threads) {
        th.join();
    }

    std::cout << "\nAll threads have finished." << std::endl;
    return 0;
}
