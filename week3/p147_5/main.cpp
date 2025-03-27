#include <iostream>
#include "russian_roulette.h"

int main() {
    int n;
    std::cout << "장전할 총알 개수를 입력하세요: ";
    std::cin >> n;

    playRussianRoulette(n);

    return 0;
}
