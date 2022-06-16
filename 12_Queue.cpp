#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q; //큐 정의(큐는 가장 먼저 들어온 것이 가장 먼저 나감)
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();
	while(!q.empty()) //빌때까지 반복
	{
		cout << q.front() << " "; //stack:top() 사용(가장 위의 데이터 출력), queue:front() 사용(가장 앞의 데이터 출력)
		q.pop(); //출력 후 pop
	}
	return 0;
}
