[page](https://codeup.kr/problem.php?id=4024&rid=0)

    #include <iostream>

    using namespace std;

    int w,h;
    char map[100][100];
    int dy[8]={-1,-1,0,1,1,1,0,-1}; //12시 방향부터 시계모양으로(방향 부호 잘 생각!!)
    int dx[8]={0,1,1,1,0,-1,-1,-1}; //dy,dx 잘생각(행 바뀌는걸 dy로 생각!!)

    void dfs(int y,int x) //행값 먼저 들어옴
    {
        if(y<0 || y>=h || x<0 || x>=w) return; //범위 밖은 종료
        if(map[y][x]=='.') return; //행렬 검토할때 '.'나오면 종료
        map[y][x]='.'; //방문처리랑 비슷한것
        for(int i=0;i<8;i++)
        {
            dfs(y+dy[i],x+dx[i]); //상하죄우 검색하면서 dfs
        }
    }   

    int main()
    {
        cin >> w >> h;
        char c;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin >> map[i][j];
            }
        }

        int cnt=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(map[i][j]=='L')
                {
                    dfs(i,j);
                    cnt+=1;
                }
            }
        }

        cout << cnt;
        return 0;
    }
