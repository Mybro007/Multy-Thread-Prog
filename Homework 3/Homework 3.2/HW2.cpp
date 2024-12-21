#include <iostream>
#include <vector>
#include <functional>
#include <future>
#include <thread>
#include <algorithm>

// Обрабатывающая функция, которая изменяет элементы вектора
void func(int& x)
{
    x *= 2;
};


// Рекурсивная функция для параллельного выполнения for_each
template<typename Iterator, typename Function>
void parallel_for_each(Iterator begin, Iterator end, Function func) {
    auto length = std::distance(begin, end);

    // Если длина диапазона достаточно мала, обрабатываем его в текущем потоке
    if (length <= 1000) { // Можем адаптировать этот порог в зависимости от нагрузки
        std::for_each(begin, end, func);
    }
    else {
        // Разбиваем диапазон на два
        Iterator mid = begin + length / 2;

        // Запускаем рекурсивно обработку левой и правой части в отдельных задачах
        auto future_left = std::async(std::launch::async, parallel_for_each<Iterator, Function>, begin, mid, func);
        auto future_right = std::async(std::launch::async, parallel_for_each<Iterator, Function>, mid, end, func);

        // Ожидаем завершения обоих блоков
        future_left.get();
        future_right.get();
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    // Пример контейнера
    std::vector<int> vec(10000, 1);  // Заполним контейнер 10000 единицами

    // Вывод до обработки
    std::cout << "До обработки: ";
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n"; // Пример вывода первых трех элементов

    // Запуск параллельного for_each
    parallel_for_each(vec.begin(), vec.end(), func);

    // Вывод после обработки
    std::cout << "После обработки: ";
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n"; // Пример вывода первых трех элементов

    return 0;
}
