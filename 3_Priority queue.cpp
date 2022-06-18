#include <iostream>
#include <queue> //우선순위 큐는 스택 함수들과 동일

using namespace std;

struct cmp //구조체 안에 ()연산자를 오버로딩하여 이 안에 비교 방식을 직접 사용자 정의 할 수 있다.
{
  bool operator()(int a, int b)
  {
    return a > b;  // 오름 차순
  }
};

int main()
{
    priority_queue<int> pq; //vector 위에서 돌아가게 된다.(힙을 구현할 수 있는 컨테이너면 다 괜찮다
    
    priority_queue<int, vector<int>, less<int>> pql; //디폴트로 Max Heap(내림 차순)인 less<int>, 최대값부터 pop이 된다.
    priority_queue<int, vector<int>, greater<int>> pqg; //Min Heap(오름 차순)인 greater<int>, 최소값이 먼저 나오도록 한다.

    priority_queue<int, vector<int>, cmp> pqc; //인수로 넘길땐 cmp() 연산자는 생략하고 구조체 이름 cmp만 넘겨주면 된다.
    
    pq.push(5); //push : priority queue에 값을 삽입한다.
    pq.push(1);
    pq.push(6);
    pq.push(2);

    cout << pq.size() << endl; //출력결과 : 4, size : priority queue의 크기를 확인한다.

    while(!pq.empty()) //우선순위 큐 출력(큐가 비어있지 않다면 무한반복), empty : priority queue가 비어있는지 확인한다.
    {
        int temp = pq.top(); // 큐의 제일 앞의 부분의 값 가져오기, 출력결과 : 6 5 2 1, top : priority queue 내부의 제일 우선순위의 값을 보여준다.
        cout << temp << " ";
        pq.pop(); // 큐의 제일 앞의 부분 빼기, pop : priority queue에서 제일 우선순위의 값을 제거한다.
    }
    cout << endl;

    priority_queue<pair<char, int>> pqp; // pair를 요소로 갖는 priority_queue를 선언
    
    pqp.emplace('a', 24); // pair의 오브젝트를 만들지 않고 바로 값을 push한다. emplace : priority queue에 구조를 삽입한다.
    //오류 명령어 : pqp.push('b', 25);)
    pqp.push(make_pair('b', 25)); // push를 사용할 때에는 pair를 만들어 준 다음에 넣어야 한다. 이 과정에서 불필요한 복사가 일어난다.
        
    while (!pqp.empty()) // 우선순위 큐 출력, 출력 결과 : b 25 / a 24
    { 
        pair p =  pqp.top();
        cout << p.first << " " << p.second << endl;  //first : pair 중 첫번째 값, second : pair 중 두번째 값
        pqp.pop(); 
    } 

    //swap : 두개의 priority queue를 swap한다.(내부를 서로 바꾼다.)

    return 0;
}
