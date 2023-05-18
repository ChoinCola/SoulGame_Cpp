#include <iostream>

using namespace std;


/*
상속 접근 지정자      부모 클래스         자식클래스
   public         public            public
                  protected         protected
                  private            접근 불가

   protected      public            protected
                  protected         protected
                  private            접근 불가

   private        public            private
                  protected         private
                  private            접근 불가
*/

class Base
{
private:
    int privateDate;

protected:
    int protectedData;

public:
    int publicData;
    void Test() {}
};

class Derived : private Base
{
public:
    Derived()
    {
        Test();
        publicData;
        protectedData;
        // privateDate;
    }
};

class A : public Derived
{
public:
    A()
    {
        // Test();
        // pulbicData;
        // protectedData;
        // 접근하는것들을 이미 private으로 받았기 때문에 다시 상속시키면, 이미 private이기 때문에 접근할 수 없게된다.
    }
};

int main()
{
    A a;
    //a. // 아무것도 뜨지 않는다.

	return 0;
}