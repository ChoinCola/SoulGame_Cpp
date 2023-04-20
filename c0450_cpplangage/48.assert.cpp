#include <iostream>
#include <cassert> // assert를 사용하기 위한 라이브러리

using namespace std;
// 단원문
// 디버깅 모드에서 오류체크를 하기 위한 구문.
int main()
{
	int x;
	cin >> x;

	// 들어온 숫자가 0일 경우 터트리고싶다.
	// 보통 if문을 사용하지만, assert를 사용하면 쉽게 터트릴 수 있다.

	assert(x != 0);
	// 특정 조건의 성공 유무를 체크하여 터트릴 수 있다.
	// 단, 디버그 모드에서만 동작된다. 윗부분 디버그를 리설트로 바꾸면 동작하지 않는다.

	//static_assert(false); // 무조건 컴파일 오류가 나면서 터진다. 
	
	const int x1 = 6;
	const int y1 = 7;
	static_assert(x1 > y1, "x1 is bigger than y1"); // 컴파일 전에 체크할 수 있다. C++에서 미리 오류를 띄워준다.

	return 0;
}