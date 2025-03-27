#include <iostream>
#include <iomanip> 
using namespace std;

double calculatePi(int n) {
    double pi = 0.0;

    for (int i = 0; i < n; i++) {
        double term = 1.0 / (2 * i + 1); // 1/1, 1/3, 1/5, ... 계산
        if (i % 2 == 0)
            pi += term;
        else
            pi -= term;
    }

    return 4 * pi;
}

int main() {
    int n;
    cout << "반복 횟수를 입력하세요 (n값): ";
    cin >> n;

    if (n < 1) {
        cout << "n은 1 이상의 정수여야 합니다." << endl;
    } else {
        double piValue = calculatePi(n);
        cout << fixed << setprecision(10);
        cout << "근사적인 π 값: " << piValue << endl;
    }

    return 0;
}
