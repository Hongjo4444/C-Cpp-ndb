#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s; //스택 정의
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	while(!s.empty()) //빌때까지 반복
	{
		cout << s.top() << " "; //가장 위의 데이터 출력
		s.pop(); //출력 후 pop
	}
	return 0;
}
