#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s; //스택 정의(스택은 가장 먼저 들어온 것이 가장 나중에 나감)
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	while(!s.empty()) //빌때까지 반복
	{
		cout << s.top() << " "; //stack:top() 사용(가장 위의 데이터 출력), queue:front() 사용(가장 앞의 데이터 출력)
		s.pop(); //출력 후 pop
	}
	return 0;
}
