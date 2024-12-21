#include <iostream>
#include <vector>
#include <functional>
#include <future>
#include <thread>
#include <algorithm>

// �������������� �������, ������� �������� �������� �������
void func(int& x)
{
    x *= 2;
};


// ����������� ������� ��� ������������� ���������� for_each
template<typename Iterator, typename Function>
void parallel_for_each(Iterator begin, Iterator end, Function func) {
    auto length = std::distance(begin, end);

    // ���� ����� ��������� ���������� ����, ������������ ��� � ������� ������
    if (length <= 1000) { // ����� ������������ ���� ����� � ����������� �� ��������
        std::for_each(begin, end, func);
    }
    else {
        // ��������� �������� �� ���
        Iterator mid = begin + length / 2;

        // ��������� ���������� ��������� ����� � ������ ����� � ��������� �������
        auto future_left = std::async(std::launch::async, parallel_for_each<Iterator, Function>, begin, mid, func);
        auto future_right = std::async(std::launch::async, parallel_for_each<Iterator, Function>, mid, end, func);

        // ������� ���������� ����� ������
        future_left.get();
        future_right.get();
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    // ������ ����������
    std::vector<int> vec(10000, 1);  // �������� ��������� 10000 ���������

    // ����� �� ���������
    std::cout << "�� ���������: ";
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n"; // ������ ������ ������ ���� ���������

    // ������ ������������� for_each
    parallel_for_each(vec.begin(), vec.end(), func);

    // ����� ����� ���������
    std::cout << "����� ���������: ";
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n"; // ������ ������ ������ ���� ���������

    return 0;
}
