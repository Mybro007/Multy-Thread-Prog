#include <iostream>
#include <vector>
#include <algorithm>
#include <future>
#include <thread>

// Функция для поиска минимального элемента в подмассиве от start до end
int find_minimum_index(const std::vector<int>& arr, int start, int end)
{
    int min_index = start;
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

// Основная функция сортировки выбором
void selection_sort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; ++i) {
        // Запуск асинхронной задачи для поиска минимального элемента
        std::future<int> min_index_future = async(std::launch::async, find_minimum_index, std::ref(arr), i, arr.size() - 1);

        // Получаем результат из асинхронной задачи
        int min_index = min_index_future.get();

        // Если найден минимальный элемент, меняем его с текущим элементом
        if (min_index != i)
        {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    std::vector<int> arr(size);

    std::cout << "Введите массив: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    selection_sort(arr);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
