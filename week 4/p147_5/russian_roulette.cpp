#include "russian_roulette.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void playRussianRoulette(int n) {
    std::vector<bool> cylinder(6, false); // 6개의 빈 슬롯
    std::srand(static_cast<unsigned int>(std::time(0))); // 랜덤 시드 설정

    // 랜덤한 위치에 n발의 총알 삽입
    for (int i = 0; i < n; ++i) {
        int pos;
        do {
            pos = std::rand() % 6;
        } while (cylinder[pos]); // 중복 방지
        cylinder[pos] = true;
    }

    std::cout << "러시안 룰렛 게임 시작! (" << n << "발 장전됨)\n";
    
    int players;
    std::cout << "참가자 수를 입력하세요: ";
    std::cin >> players;

    int currentPlayer = 0;
    while (true) {
        std::cout << "플레이어 " << (currentPlayer + 1) << " 차례. 방아쇠를 당깁니다...\n";
        int shot = std::rand() % 6;

        if (cylinder[shot]) {
            std::cout << "탕! 플레이어 " << (currentPlayer + 1) << " 탈락!\n";
            break;
        } else {
            std::cout << "딸깍... 살아남았습니다.\n";
        }

        // 다음 플레이어로 변경
        currentPlayer = (currentPlayer + 1) % players;
    }
}
