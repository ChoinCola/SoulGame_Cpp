#include <iostream>

using namespace std;


/*
��� ���� ������      �θ� Ŭ����         �ڽ�Ŭ����
   public         public            public
                  protected         protected
                  private            ���� �Ұ�

   protected      public            protected
                  protected         protected
                  private            ���� �Ұ�

   private        public            private
                  protected         private
                  private            ���� �Ұ�
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
        // �����ϴ°͵��� �̹� private���� �޾ұ� ������ �ٽ� ��ӽ�Ű��, �̹� private�̱� ������ ������ �� ���Եȴ�.
    }
};

int main()
{
    A a;
    //a. // �ƹ��͵� ���� �ʴ´�.

	return 0;
}