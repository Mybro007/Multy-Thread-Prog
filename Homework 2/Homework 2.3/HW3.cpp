#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Data {
public:
    int value;
    std::mutex mtx;

    Data(int val) : value(val) {}

    // ��� ������ ��������
    void print() const {
        std::cout << value << " ";
    }
};

// ������� 1: ������������� std::lock
void swap_lock(Data& d1, Data& d2) {
    // ������ ��������� ����� ��������
    std::lock(d1.mtx, d2.mtx);  // �������������� ������ ���������, ����� �������� ��������
    std::lock_guard<std::mutex> lock1(d1.mtx, std::adopt_lock);  // ���������� adopt_lock, ����� �� ����������� ��������
    std::lock_guard<std::mutex> lock2(d2.mtx, std::adopt_lock);

    // ����� ����������
    std::swap(d1.value, d2.value);
}

// ������� 2: ������������� std::scoped_lock
void swap_scoped_lock(Data& d1, Data& d2) {
    // ������ ��������� ����� �������� � ������� scoped_lock
    std::scoped_lock lock(d1.mtx, d2.mtx);  // ��� �������� ������������� � ����� �����

    // ����� ����������
    std::swap(d1.value, d2.value);
}

// ������� 3: ������������� std::unique_lock
void swap_unique_lock(Data& d1, Data& d2) {
    // �������� ���������� ���������� ��� ������� ��������
    std::unique_lock<std::mutex> lock1(d1.mtx);
    std::unique_lock<std::mutex> lock2(d2.mtx);

    // ����� ����������
    std::swap(d1.value, d2.value);
}

int main() {
    // ������ ��� ������� Data
    Data d1(10);
    Data d2(20);

    std::cout << "Initial values: ";
    d1.print();
    d2.print();
    std::cout << std::endl << std::endl;

    // ������ ������ � �������������� std::lock
    std::cout << "Swapping using std::lock: \n";
    swap_lock(d1, d2);
    std::cout << "After swap: ";
    d1.print();
    d2.print();
    std::cout << std::endl << std::endl << std::endl;

    // ������ ������ � �������������� std::scoped_lock
    d1.value = 10;
    d2.value = 20;
    std::cout << "Swapping using std::scoped_lock: \n";
    swap_scoped_lock(d1, d2);
    std::cout << "After swap: ";
    d1.print();
    d2.print();
    std::cout << std::endl << std::endl << std::endl;

    // ������ ������ � �������������� std::unique_lock
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
