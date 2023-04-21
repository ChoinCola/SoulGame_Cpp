#include <iostream>

class Rectangle {
private:
    int width;
    int height;
public:
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }
    int getArea() {
        return width * height;
    }
};

int main() {
    Rectangle rect(5, 10);
    int area = rect.getArea(); // 50
    std::cout << area << std::endl;
    return 0;
}