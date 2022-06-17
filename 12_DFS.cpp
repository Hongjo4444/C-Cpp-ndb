#include <iostream>
#include <queue> //깊이 우선 탐색(최단거리 찾기(거리가 가까운 순서대로 출력됨))은 stack or 재귀함수 사용해야함
#include <vector>

using namespace std;

int number=7;
int c[7]; //방문처리를 위한 배열 생성
vector<int> a[8]; //1~7까지 인덱스를 다루기 위해 8짜리 만듬('<' 부호 생각)

void dfs(int x)
{
    if(c[x]) return; //방문했다면 바로 함수 끝내기
    c[x]=true; //처음 방문하는거면 방문 처리
    cout << x << " ";
    for(int i=0;i<a[x].size();i++) //해당 노드에 연결된 노드에 대해 재귀
    {
        int y=a[x][i];
        dfs(y);
    }
}
//stack으로 구현할때: s가 빌때까지 '1스택 최상단 노드에서, 2해당 노드에 연결된 노드 중 3방문하지 않은 노드 확인, 4방문 처리하고, 스택에 삽입, 5방문하지 않은 연결된 노드가 없으면 스택에서 최상단 노드 빼기 반복

int main()
{
    a[1].push_back(2); //간선의 정보 입력
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[4].push_back(7);
    a[7].push_back(4);

    dfs(1); //방문 경로:1-2-3-6-7-4-5
    return 0;
}
