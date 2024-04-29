// Задача 2.
// Написать функцию/метод, которая на вход получает массив положительных
// целых чисел произвольной длины. 
// Например [42, 12, 18].
// На выходе возвращает массив чисел, которые являются общими делителями
// для всех указанных числе.
// В примере это будет [2, 3, 6].

#include <iostream>
#include <vector>

class CommonDivision {
private:
    // Функция для нахождения общего делителя двух чисел
    int findCommonDivisor(int a, int b) {
        while (b != 0) {
            int x = b;
            b = a % b;
            a = x;
        }
        return a;
    }

public:

    CommonDivision() = default;
    ~CommonDivision() = default;

    // Функция для нахождения общих делителей массива
    std::vector<int> findCommonDivisorsArr(const std::vector<int> &arr) {
        int comDiv = arr[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            comDiv = findCommonDivisor(comDiv, arr[i]);
        }

        std::vector<int> commonDivision;
        for (int i = 2; i <= comDiv; ++i) {
            if (comDiv % i == 0) {
                commonDivision.push_back(i);
            }
        }

        return commonDivision;
    }
};

// Функция для читаемого вывода массива
void printResult(std::vector<int> result) {
    std::cout << "[";
    for (auto i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < (result.size() - 1)) {std::cout << " ";}
        else {std::cout << "]" << std::endl;}
    }
}

int main() {
    std::vector<int> num = {42, 12, 18};
    CommonDivision test;
    std::vector<int> res = test.findCommonDivisorsArr(num);
    printResult(res);

    return 0;
}