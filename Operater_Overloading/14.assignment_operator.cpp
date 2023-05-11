#include <iostream>
#include <cassert>

using namespace std;

/*
	deep copy vs shallow copy
	기본 복사 생성자 = 맴버 와 맴버의 복사를 지원하는 얕은복사이다.
	이렇게 하면 맴버에 동적할당을 하게 되면, 문제가 생긴다.
	그렇기에 내부에서 동적생성을 따로 해주고 복사해야하는 문제가 생긴다.
*/

class Mystring
{
public:
	char* data = nullptr;
	int length = 0;

	Mystring(const char* const src = " ")
	{
		assert(src);

		length = strlen(src) + 1;
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];
		data[length - 1] = '\0';
	}

	Mystring(const Mystring& other)
	{
		this->length = other.length;
		if (other.data != nullptr)
		{
			this->data = new char[length];
			for (int i = 0; i < this->length; i++)
				this->data[i] = other.data[i];
		}
		else
		{
			data = nullptr;
		}
	}
	~Mystring()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	Mystring& operator =(const Mystring& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;

			cout << "copy assignment operator" << endl;
			this->length = other.length;

			if (other.data != nullptr)
			{
				this->data = new char[length];
				for (int i = 0; i < this->length; i++)
					this->data[i] = other.data[i];
			}
			else
			{
				this->data = nullptr;
			}
		}
		return *this;
	}

	Mystring(Mystring&& other)
	{
		cout << "move constructor" << endl;
		this->data = std::move(other.data);
		this->length = std::move(other.length);

		other.data = nullptr;
	}

	Mystring& operator= (Mystring&& other)
	{
		cout << "Move assignment operator" << endl;

		if (this == &other) // prevent self-assignment
			return *this;
		
		if (this->data != nullptr)
		{
			if (other.data != nullptr && this->data != other.data)
			{
				delete[] this->data;
				this->data = nullptr;

				this->data = std::move(other.data);
			}
		}
		else
			this->data = std::move(other.data);

		this->length = std::move(other.length);

		other.data = nullptr;

		return *this;
	}

};

int main()
{
	cout << "#################1#################" << endl;
	Mystring str("Hello");
	cout << (int*)str.data << endl;
	cout << str.data << endl << endl;

	cout << "#################2#################" << endl;
	// copy
	{
		Mystring copy(str);
		copy = str;
		cout << (int*)copy.data << endl;
		cout << copy.data << endl << endl;
	}

	cout << "#################3#################" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl;
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl << endl;
	}

	cout << "#################4#################" << endl;
	{
		Mystring copy(std::move(str));
		copy = std::move(str);

		cout << (int*)copy.data << endl;
		cout << copy.data << endl << endl;
	}

	cout << "#################5#################" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl;
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl << endl;
	}

	return 0;
}

/*
	Test class
	Special member function
	- 기본
	- 복사
	- 이동
	- 복사대입
	- 이동대입
	- 소멸
	을 직접 만들어보기.
*/