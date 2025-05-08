#include <iostream>
#include <cstring>
using namespace std;

class Sample {
    char* name;
    static int count;  // 정적 변수 선언

public:
    // 기본 생성자
    Sample() {
        name = nullptr;
        count++;
    }

    // 생성자
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }

    // 복사 생성자
    Sample(const Sample& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        count++;
    }

    // 소멸자
    ~Sample() {
        delete[] name;
        count--;
    }

    // 정적 함수로 객체 수 출력
    static void printCount() {
        cout << "현재 Sample 객체 수: " << count << endl;
    }
};

// 정적 변수 정의
int Sample::count = 0;

int main() {
    Sample::printCount();     // 0
    Sample a("sample");
    Sample::printCount();     // 1
    Sample b(a);
    Sample::printCount();     // 2
    return 0;
}
