#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 5x5 크기의 배열을 0과 1로 랜덤하게 채우는 함수
void randomMap(int map[5][5]) {
    srand(time(0)); // 난수 초기화

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2; // 0 또는 1 할당
        }
    }
}

// 5x5 크기의 체커 보드를 출력하는 함수
void printMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

// 가로, 세로, 대각선이 모두 0이거나 1인지 확인하는 함수
void checkMap(int map[5][5]) {
    bool allSame;
    
    // 가로줄 검사
    for (int i = 0; i < 5; i++) {
        allSame = true;
        for (int j = 1; j < 5; j++) {
            if (map[i][j] != map[i][0]) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            cout << "가로 " << i + 1 << "번째 줄이 모두 " << map[i][0] << "입니다." << endl;
        }
    }

    // 세로줄 검사
    for (int j = 0; j < 5; j++) {
        allSame = true;
        for (int i = 1; i < 5; i++) {
            if (map[i][j] != map[0][j]) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            cout << "세로 " << j + 1 << "번째 줄이 모두 " << map[0][j] << "입니다." << endl;
        }
    }

    // 왼쪽 상단 -> 오른쪽 하단 대각선 검사
    allSame = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][i] != map[0][0]) {
            allSame = false;
            break;
        }
    }
    if (allSame) {
        cout << "왼쪽 상단 -> 오른쪽 하단 대각선이 모두 " << map[0][0] << "입니다." << endl;
    }

    // 오른쪽 상단 -> 왼쪽 하단 대각선 검사
    allSame = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][4 - i] != map[0][4]) {
            allSame = false;
            break;
        }
    }
    if (allSame) {
        cout << "오른쪽 상단 -> 왼쪽 하단 대각선이 모두 " << map[0][4] << "입니다." << endl;
    }
}

int main() {
    int map[5][5];

    randomMap(map); // 랜덤한 값으로 배열 채우기
    cout << "체커 보드 출력:" << endl;
    printMap(map); // 결과 출력

    cout << "\n체크 결과:" << endl;
    checkMap(map); // 가로, 세로, 대각선 체크

    return 0;
}
