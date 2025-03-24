#include <iostream>
#include "reverse.h"

int main() {
    int number;
    std::cout << "숫자를 입력하세요: ";
    std::cin >> number;

    int reversedNumber = reverse(number);
    std::cout << "뒤집힌 숫자: " << reversedNumber << std::endl;

    return 0;
}
