#include <iostream>
using namespace std;

template <typename T>
T smax(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int x = 5, y = 10;
    cout << smax(x, y) << endl; // 10 출력

    double a = 3.14, b = 2.71;
    cout << smax(a, b) << endl; // 3.14 출력

    return 0;
}