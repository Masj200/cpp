#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 한 개의 구구단 문제를 출제하고 정답을 맞힐 때까지 반복
void playGuguOnce(int a, int b) {
    int answer;
    while (true) {
        cout << a << " × " << b << " = ";
        cin >> answer;
        if (answer == a * b) {
            cout << "정답입니다!\n";
            break;
        } else {
            cout << "틀렸습니다. 다시 시도하세요.\n";
        }
    }
}

// 두 자리 수 곱셈 문제를 출제하고 정답을 맞힐 때까지 반복
void playTwoDigitMultiplication() {
    int a = rand() % 90 + 10; // 10~99
    int b = rand() % 90 + 10; // 10~99
    playGuguOnce(a, b);
}

// 두 자리 수 덧셈 문제를 출제하고 정답을 맞힐 때까지 반복
void playTwoDigitAddition() {
    int a = rand() % 90 + 10; // 10~99
    int b = rand() % 90 + 10; // 10~99
    int answer;
    while (true) {
        cout << a << " + " << b << " = ";
        cin >> answer;
        if (answer == a + b) {
            cout << "정답입니다!\n";
            break;
        } else {
            cout << "틀렸습니다. 다시 시도하세요.\n";
        }
    }
}

// 게임 실행 함수
void startGame() {
    srand(time(0)); // 난수 시드 설정

    int choice;
    cout << "게임을 선택하세요:\n";
    cout << "1: 구구단 문제\n";
    cout << "2: 두 자리 수 곱셈 문제\n";
    cout << "3: 3~9까지의 두 자리 수 덧셈 문제\n";
    cout << "선택: ";
    cin >> choice;

    switch (choice) {
        case 1:
            playGuguOnce(rand() % 9 + 1, rand() % 9 + 1); // 1~9 범위
            break;
        case 2:
            playTwoDigitMultiplication();
            break;
        case 3:
            playTwoDigitAddition();
            break;
        default:
            cout << "잘못된 입력입니다.\n";
            return;
    }
}

// 메인 실행 함수
int main() {
    startGame();
    return 0;
}
