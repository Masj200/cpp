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

int main() {
    int map[5][5];

    randomMap(map); // 랜덤한 값으로 배열 채우기
    cout << "랜덤 체커 보드:" << endl;
    printMap(map); // 결과 출력

    return 0;
}
