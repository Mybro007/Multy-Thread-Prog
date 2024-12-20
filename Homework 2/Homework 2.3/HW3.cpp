#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Data {
public:
    int value;
    std::mutex mtx;

    Data(int val) : value(val) {}

    // Для вывода значений
    void print() const {
        std::cout << value << " ";
    }
};

// Вариант 1: Использование std::lock
void swap_lock(Data& d1, Data& d2) {
    // Захват мьютексов обоих объектов
    std::lock(d1.mtx, d2.mtx);  // Синхронизируем захват мьютексов, чтобы избежать дедлоков
    std::lock_guard<std::mutex> lock1(d1.mtx, std::adopt_lock);  // Используем adopt_lock, чтобы не блокировать мьютексы
    std::lock_guard<std::mutex> lock2(d2.mtx, std::adopt_lock);

    // Обмен значениями
    std::swap(d1.value, d2.value);
}

// Вариант 2: Использование std::scoped_lock
void swap_scoped_lock(Data& d1, Data& d2) {
    // Захват мьютексов обоих объектов с помощью scoped_lock
    std::scoped_lock lock(d1.mtx, d2.mtx);  // Все мьютексы захватываются в одном блоке

    // Обмен значениями
    std::swap(d1.value, d2.value);
}

// Вариант 3: Использование std::unique_lock
void swap_unique_lock(Data& d1, Data& d2) {
    // Создание уникальных блокировок для каждого мьютекса
    std::unique_lock<std::mutex> lock1(d1.mtx);
    std::unique_lock<std::mutex> lock2(d2.mtx);

    // Обмен значениями
    std::swap(d1.value, d2.value);
}

int main() {
    // Создаём два объекта Data
    Data d1(10);
    Data d2(20);

    std::cout << "Initial values: ";
    d1.print();
    d2.print();
    std::cout << std::endl << std::endl;

    // Пример обмена с использованием std::lock
    std::cout << "Swapping using std::lock: \n";
    swap_lock(d1, d2);
    std::cout << "After swap: ";
    d1.print();
    d2.print();
    std::cout << std::endl << std::endl << std::endl;

    // Пример обмена с использованием std::scoped_lock
    d1.value = 10;
    d2.value = 20;
    std::cout << "Swapping using std::scoped_lock: \n";
    swap_scoped_lock(d1, d2);
    std::cout << "After swap: ";
    d1.print();
    d2.print();
    std::cout << std::endl << std::endl << std::endl;

    // Пример обмена с использованием std::unique_lock
    d1.value = 10;
    d2.value = 20;
    std::cout << "Swapping using std::unique_lock: \n";
    swap_unique_lock(d1, d2);
    std::cout << "After swap: ";
    d1.print();
    d2.print();
    std::cout << std::endl << std::endl << std::endl;

    return 0;
}
