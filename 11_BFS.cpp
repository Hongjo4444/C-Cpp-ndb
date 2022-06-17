#include <iostream>
#include <queue> //너비 우선 탐색(최단거리 찾기(거리가 가까운 순서대로 출력됨))은 queue 사용해야함
#include <vector>

using namespace std;

int number=7;
int c[7]; //방문처리를 위한 배열 생성
vector<int> a[8]; //1~7까지 인덱스를 다루기 위해 8짜리 만듬('<' 부호 생각)

void bfs(int start)
{
    queue<int> q;
    q.push(start); //시작 노드를 큐에 삽입
    c[start]=true; //방문 처리
    while(!q.empty()) //q가 빌때까지 '1큐에서 맨앞 노드를 꺼내기, 2해당 노드에 연결된 노드 중 3방문하지 않은 노드 확인, 4방문 처리하고, 큐에 삽입' 반복
    {
        int x=q.front(); //1
        q.pop(); 
        printf("%d ",x);
        for(int i=0;i<a[x].size();i++)
        {
            int y=a[x][i]; //2
            if(!c[y]) //3
            {
                q.push(y); //4
                c[y]=true;
            }
        }
    }
}

int main(void)
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

    bfs(1); //방문 경로:1-2-3-4-5-6-7
    return 0;
}
