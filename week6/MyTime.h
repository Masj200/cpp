#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
private:
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    MyTime();                                 // 기본 생성자
    MyTime(int h, int m, int s, int ms);      // 사용자 정의 생성자

    void convert(double duration);            // 초 단위를 시간으로 변환
    void print() const;                       // 시간 출력
    MyTime add(MyTime t) const;               // 시간 더하기
    void reset();                             // 시간 리셋
    void read();                              // 사용자 입력
};

#endif
