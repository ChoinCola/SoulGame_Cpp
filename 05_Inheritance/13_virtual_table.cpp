#include <iostream>

using namespace std;

// c++ 기본의 객체 class 선언.
class A
{
	int a; // 4byte;
public:
	void func();
};

/*
    class Base                                     Base my_base;
    *__vfptr         --------------------------->  -Base virtual-table
    virtual func1()  <---------------------------  -func1()
    virtual func2()  <---------------------------  -func2()
                 ^
                 |
                 \
                  \________________________________
                                                   \
    class Derived : public Base                     \   Derived my_derived;
    *__vfptr (inherited) --------------------------->\  -Derived virtual_table
    virtual func1()      <----------------------------\--func1() // 오버라이딩 하지 않을 키워드는 virtual을 넣어주지 않는게 좋다. 이유없이 생성이 될 수 있기 때문.
                                                       \-func2()
*/

class Base
{
public:
    virtual void func1() { cout << "func1" << endl; }
    virtual void func2() { cout << "func2" << endl; }
};

class Derived : public Base
{
public:
    virtual void func1() { cout << "Derived::func1" << endl; }
    void func3() { cout << "func3" << endl; }
};

int main()
{
    Base* bptr = new Base();
    bptr->func1();

    Derived* dptr = new Derived();
    dptr->func1();
    dptr->func2();
    dptr->func3();

	return 0;
}