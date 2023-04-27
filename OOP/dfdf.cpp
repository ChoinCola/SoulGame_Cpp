#include <iostream>

class MyFriendClass {
private:
    int secret_number;

public:
    MyFriendClass() {
        secret_number = 42;
    }

    friend void print_secret(MyFriendClass obj);  // friend 함수 선언
};

void print_secret(MyFriendClass obj) {  // friend 함수 정의
    std::cout << "The secret number is: " << obj.secret_number << std::endl;
}

int main() {
    MyFriendClass obj;
    print_secret(obj);  // friend 함수 호출
    return 0;
}