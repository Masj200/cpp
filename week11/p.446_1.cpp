#include <iostream>
using namespace std;

// Point 클래스 정의
class Point {
protected:
    int x, y;

public:
    Point(int xx, int yy) : x(xx), y(yy) {}

    void draw() {
        cout << x << "," << y << "에 점을 그려라.\n";
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

// Rectangle 클래스 정의 (Point 상속 + 사각형 그리기)
class Rectangle : public Point {
    int width, height;

public:
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) {}

    void draw() {
        cout << x << "," << y << "에 가로 " << width
             << " 세로 " << height << " 사각형을 그려라.\n";

        // 위쪽 여백
        for (int i = 0; i < y; ++i) {
            cout << endl;
        }

        // 사각형을 '*'로 출력
        for (int i = 0; i < height; ++i) {
            // 왼쪽 여백
            for (int j = 0; j < x; ++j) {
                cout << " ";
            }
            // 별표 출력
            for (int j = 0; j < width; ++j) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

// main 함수
int main() {
    Point p(3, 1);
    p.draw();  // 3,1에 점을 그려라.

    Rectangle r(5, 2, 10, 4);
    r.draw();  // 사각형 정보 출력 및 그리기

    return 0;
}
