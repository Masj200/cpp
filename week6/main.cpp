#include <iostream>
#include <iomanip>
#include "MyTime.h"
using namespace std;

// MyTime 클래스 구현
MyTime::MyTime() : hour(0), minute(0), second(0), millisecond(0) {}

MyTime::MyTime(int h, int m, int s, int ms)
    : hour(h), minute(m), second(s), millisecond(ms) {}

void MyTime::convert(double duration) {
    hour = static_cast<int>(duration / 3600);
    duration -= hour * 3600;
    minute = static_cast<int>(duration / 60);
    duration -= minute * 60;
    second = static_cast<int>(duration);
    duration -= second;
    millisecond = static_cast<int>(duration * 1000);
}

void MyTime::print() const {
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << ":"
         << setw(3) << millisecond << endl;
}

MyTime MyTime::add(MyTime t) const {
    MyTime result;
    result.millisecond = millisecond + t.millisecond;
    result.second = second + t.second + result.millisecond / 1000;
    result.millisecond %= 1000;
    result.minute = minute + t.minute + result.second / 60;
    result.second %= 60;
    result.hour = hour + t.hour + result.minute / 60;
    result.minute %= 60;
    return result;
}

void MyTime::reset() {
    hour = minute = second = millisecond = 0;
}

void MyTime::read() {
    double input;
    cout << "초 단위 시간을 입력하세요: ";
    cin >> input;
    convert(input);
}

// main 함수 (테스트)
int main() {
    MyTime t1, t2, t3;

    t1.read();
    cout << "t1: ";
    t1.print();

    t2.convert(3661.789); // 예시: 1시간 1초 789밀리초
    cout << "t2: ";
    t2.print();

    t3 = t1.add(t2);
    cout << "t3 = t1 + t2: ";
    t3.print();

    cout << "t3 리셋 후: ";
    t3.reset();
    t3.print();

    return 0;
}
