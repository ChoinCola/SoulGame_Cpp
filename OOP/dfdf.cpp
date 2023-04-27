#include <iostream>

class MyFriendClass {
private:
    int secret_number;

public:
    MyFriendClass() {
        secret_number = 42;
    }

    friend void print_secret(MyFriendClass obj);  // friend �Լ� ����
};

void print_secret(MyFriendClass obj) {  // friend �Լ� ����
    std::cout << "The secret number is: " << obj.secret_number << std::endl;
}

int main() {
    MyFriendClass obj;
    print_secret(obj);  // friend �Լ� ȣ��
    return 0;
}