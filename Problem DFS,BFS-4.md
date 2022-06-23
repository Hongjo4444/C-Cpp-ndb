[page](https://codeup.kr/problem.php?id=4024&rid=0)

    #include <iostream>

    using namespace std;

    int w,h;
    char map[100][100];
    int dx[8]={-1,-1,0,1,1,1,0,-1}; //12시부터 시계모양으로(방향 부호 잘 생각!!)
    int dy[8]={0,1,1,1,0,-1,-1,-1};

    void dfs(int x,int y)
    {
        if(x<0 || x>=h || y<0 || y>=w) return; //범위 잘생각(x(행)범위가 h, y(열)범위가 w)
        if(map[x][y]=='.') return; //행렬 검토할때 '.'나오면 종료
        map[x][y]='.'; //방문처리랑 비슷한것
        for(int i=0;i<8;i++)
        {
            dfs(x+dx[i],y+dy[i]); //상하죄우 검색하면서 dfs
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
