/*
	Object RelationShip : 객체 관계

	- Composition(구성) part-of
		전체클래스의 일부를 다른 부품클래스가 담당하는것.
		전체의 부품클레스는 전체클래스 와 생명주기를 공유한다.
		사람의 장기와 같은 역활을 한다.

	- Aggregation(집합) has-a
		특정 클래스의 기능의 일부를 한개이상의 다른 클래스에서 담당하는것.
		구성과 비슷하지만, 생명주기는 공유하지 않는다.

	- Association(연계) uses-a
		참조변수, 특정클래스의 참조값을 맴버변수로 가져오는것.
		클래스간의 독립적인 기능은 있지만, 다른 클래스의 협조가 필요해서
		참조를 가져오게 되는것. ( 커플링 관계라고 하고, 유지보수가 매우 어렵다 )

	- Dependency(의존) depend-on
		특정 클래스가 다른 클래스의 기능을 잠깐 사용하게 되는것
		의존과 다르게 그 클래스를 필요한 순간은 아주 잠깐 이기 때문에 관계성이 낮다.

	- Inheritance(상속) is-a
		한 클래스가 다른 클래스의 기능을 물려받는것.
		부모 클래스 자식클래스 관계라고도 부른다.

										 관계 형태    다른 클래스에 속할수 있는가  멤버의 존재를 클래스가 관리  방향성
   Composition(구성)     part-of     전체/부품                   No                        Yes             단방향
   Aggregation(집합)     has-a       전체/부품                   Yes                       No              단방향
   Association(연계)     uses-a      용도 외엔 무관              Yes                       No              단방향 or 양방향
   Dependency(의존)      depends-on  옹도 외엔 무관              Yes                       Yes             단방향

   결합도 : 낮을 수록 좋다.
   응집도 : 높을 수록 좋다.

*/

#include <iostream>

int main()
{



	return 0;
}