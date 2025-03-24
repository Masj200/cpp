#include <iostream>
using namespace std;

// 정수를 뒤집는 함수
int reverse(int num) {
    int reversedNum = 0;
    while (num > 0) {
        reversedNum = reversedNum * 10 + (num % 10);
        num /= 10;
    }
    return reversedNum;
}

int main() {
    int num;
    cout << "정수를 입력하세요: ";
    cin >> num;
    
    cout << "뒤집힌 숫자: " << reverse(num) << endl;
    
    return 0;
}
