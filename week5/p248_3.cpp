#include <iostream>

struct Time {
    int hours;
    int minutes;
};

// (1) 값 반환 방식
Time addTimeByValue(Time t1, Time t2) {
    Time result;
    result.hours = t1.hours + t2.hours;
    result.minutes = t1.minutes + t2.minutes;
    if (result.minutes >= 60) {
        result.hours += result.minutes / 60;
        result.minutes %= 60;
    }
    return result;
}

// (2) 참조를 사용하는 방식
void addTimeByReference(const Time& t1, const Time& t2, Time& result) {
    result.hours = t1.hours + t2.hours;
    result.minutes = t1.minutes + t2.minutes;
    if (result.minutes >= 60) {
        result.hours += result.minutes / 60;
        result.minutes %= 60;
    }
}

// (3) 포인터를 사용하는 방식
void addTimeByPointer(const Time* t1, const Time* t2, Time* result) {
    result->hours = t1->hours + t2->hours;
    result->minutes = t1->minutes + t2->minutes;
    if (result->minutes >= 60) {
        result->hours += result->minutes / 60;
        result->minutes %= 60;
    }
}

int main() {
    Time t1 = {2, 45}; // 2시간 45분
    Time t2 = {1, 30}; // 1시간 30분

    // 값 반환 방식
    Time result1 = addTimeByValue(t1, t2);
    std::cout << "값 반환 방식: " << result1.hours << "시간 " << result1.minutes << "분\n";

    // 참조 방식
    Time result2;
    addTimeByReference(t1, t2, result2);
    std::cout << "참조 방식: " << result2.hours << "시간 " << result2.minutes << "분\n";

    // 포인터 방식
    Time result3;
    addTimeByPointer(&t1, &t2, &result3);
    std::cout << "포인터 방식: " << result3.hours << "시간 " << result3.minutes << "분\n";

    return 0;
}
