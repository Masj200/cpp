#include <iostream>

using namespace std;

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
    int map[5][5] = {
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1}
    };

    cout << "체커 보드 출력:" << endl;
    printMap(map);

    return 0;
}
