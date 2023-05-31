#include "02_myArray.h"

template<class T>
inline void myArray<T>::Print()
{
	std::cout << "Hello" << std::endl;
}
// 컴파일 타이밍에 인라인화 시켜준다. 사용시점에 이미 구현도가 정의되어있어야한다.
// 그러나, 그러한 구현부가 class T 가 분리되어 있어서 컴파일러가 받아들이지 못한다.


// 템플릿 자체가 함수를 정의하기 위해 만든 틀. 함수 자체가 정의된 상태가 아니다.
// 템플릿 코드 자체가 컴파일 시에 정의가 된다.

// 컴파일러가 인라인화 시키면서 함수가 최적화 되어있는지, 아닌지 확인해서 그대로 코드영역에 넣을지 검사한다.
// 컴파일 타임에 만들어 진다는 뜻 은 사용 시점에 모든것이 정의되어 있어야 한다는 것.
// 그러나, class T 는 만들어져 있지 않기 때문에, 컴파일러가 넣을지 바꿀지 확인해야 하는데, 컴파일러는 헤더를 같이 읽지 못하고 따로 읽는다.
// 정의되어있지 않은 class T에 대한 함수를 컴파일러는 읽지 못하기 때문에, 따로 분리되어 있는 함수를 확인하지 못한다.