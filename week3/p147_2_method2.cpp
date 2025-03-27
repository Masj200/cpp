#include <iostream>
using namespace std;

int reverse(int);  // 함수 원형 선언

int main() {
    int num;
    cout << "정수를 입력하세요: ";
    cin >> num;
    
    cout << "뒤집힌 숫자: " << reverse(num) << endl;
    
    return 0;
}

int reverse(int num) {  // 함수 정의
    int reversedNum = 0;
    while (num > 0) {
        reversedNum = reversedNum * 10 + (num % 10);
        num /= 10;
    }
    return reversedNum;
}
