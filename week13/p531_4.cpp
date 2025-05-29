#include <iostream>
#include <cstdlib>  // rand()
using namespace std;

class SampleList {
    int list[100];

public:
    SampleList() {
        for (int x = 0; x < 100; x++) {
            list[x] = rand() % 1000;
        }
    }

    // (1) 함수로 접근
    int get(int index) const {
        return list[index];
    }

    // (2) 인덱스 연산자 중복
    int operator[](int index) const {
        return list[index];
    }

    // (3) 두 수의 구간 반환용 연산자 중복 (시작~끝 구간 합 반환 예시)
    int operator()(int start, int end) const {
        int sum = 0;
        for (int i = start; i <= end; ++i)
            sum += list[i];
        return sum;
    }

    // 리스트 출력용 (확인용)
    void print() const {
        for (int i = 0; i < 100; i++)
            cout << list[i] << ' ';
        cout << endl;
    }
};

int main() {
    SampleList s;

    // 확인 예제
    cout << "s.get(5): " << s.get(5) << endl;
    cout << "s[5]: " << s[5] << endl;
    cout << "s(0, 9): " << s(0, 9) << endl;

    return 0;
}
