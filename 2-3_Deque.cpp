#include <iostream>
#include <deque> //deque는 앞,뒤 원소를 모두 추가/제거할 수 있어서 좋음

using namespace std;

int main()
{
    deque<int> d; //int 자료형 deque 생성
    // deque<int> d(5); //0으로 초기화된 size 5인 int 자료형 deque
    // deque<int> d(5,10); //10으로 초기화된 size 5인 int 자료형 deque
    // deque<int> d={1,2,3,4,5};
    // deque<int> dcopy(d); //d의 복사본 int 자료형 deque

    d.push_back(10); //뒤에서 원소 추가
    for(int i=0;i<d.size();i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    d.push_front(30); //앞에서 원소 추가
    for(int i=0;i<d.size();i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    d.pop_back(); //뒤에서 원소 제거
    for(int i=0;i<d.size();i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    
    d.pop_front(); //앞에서 원소 제거
    for(int i=0;i<d.size();i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;


    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    
    d.insert(d.begin()+2,100); //begin()+2 위치에 100 삽입
    for(int i=0;i<d.size();i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    d.erase(d.begin()+2); //begin()+2 위치 원소 삭제
    for(int i=0;i<d.size();i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    cout << d.front() << endl; //맨 앞의 값 접근

    cout << d.back() << endl; //맨 뒤의 값 접근

    cout << d[2] << endl; //2번째 값 접근

    cout << d.at(3) << endl; //3번째 값 접근
    return 0;
}
