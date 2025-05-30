#include <iostream>
using namespace std;

void readNumber(int num) {
    int units[] = {10000, 1000, 100, 10, 1};
    string unitsName[] = {"만", "천", "백", "십", ""};

    bool started = false;

    for (int i = 0; i < 5; i++) {
        int digit = num / units[i];
        num %= units[i];

        if (digit > 0) { 
            if (started) cout << " ";
            cout << digit << unitsName[i];
            started = true;
        }
    }
    cout << endl;
}

int main() {
    int num;
    cout << "10000 미만의 정수를 입력하세요: ";
    cin >> num;

    if (num <= 0 || num >= 10000) {
        cout << "잘못된 입력입니다. 1 이상 9999 이하의 숫자를 입력하세요." << endl;
    } else {
        readNumber(num);
    }

    return 0;
}
