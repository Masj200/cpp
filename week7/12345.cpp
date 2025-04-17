#include <iostream>
using namespace std;

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 3. 멤버 함수 (void형, 참조 전달)
    void add_void(const Complex& other) {
        real += other.real;
        imag += other.imag;
    }

    // 4. 멤버 함수 (리턴형, 참조 전달)
    Complex add_return(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 5. 연산자 오버로딩
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display(const string& label) const {
        cout << label << ": " << real << " + " << imag << "i" << endl;
    }
};

// 1. 일반 함수 (void형, 참조 전달)
void add_by_reference(const Complex& a, const Complex& b, Complex& c) {
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
}

// 2. 일반 함수 (리턴형, 값 전달)
Complex add_by_value(Complex a, Complex b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    Complex a(1, 2);  // a = 1 + 2i
    Complex b(3, 4);  // b = 3 + 4i

    // 1. 일반 함수 (void형, 참조 전달)
    Complex c1;
    add_by_reference(a, b, c1);
    c1.display("1. 일반 함수 void 참조");

    // 2. 일반 함수 (리턴형, 값 전달)
    Complex c2 = add_by_value(a, b);
    c2.display("2. 일반 함수 return 값 전달");

    // 3. 멤버 함수 (void형, 참조 전달)
    Complex c3 = a;
    c3.add_void(b);
    c3.display("3. 멤버 함수 void 참조");

    // 4. 멤버 함수 (리턴형, 참조 전달)
    Complex c4 = a.add_return(b);
    c4.display("4. 멤버 함수 return 참조");

    // 5. 연산자 오버로딩
    Complex c5 = a + b;
    c5.display("5. 연산자 오버로딩");

    return 0;
}
