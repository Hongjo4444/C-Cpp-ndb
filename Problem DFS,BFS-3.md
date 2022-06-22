[page](https://codeup.kr/problem.php?id=4781&rid=0)

    #include <iostream>
    #include <queue>

    using namespace std;

    int box[1001][1001];
    int visited[1001][1001];
    int dx[4]={-1,1,0,0}; //행에서 좌우
    int dy[4]={0,0,-1,1}; //열에서 상하
    int days=-1;

    queue<pair<int,int>> q;

    int main()
    {
        int m,n=0;
        cin >> m >> n;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> box[i][j];
            }
        }

        int check_box=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(box[i][j]==1)
                {
                    visited[i][j]=1;
                    q.push({i,j});
                } 
                if(box[i][j]==-1) visited[i][j]=1;
                if(box[i][j]!=0) check_box+=1;
            }
        }
        if(check_box==m*n) days=0;
        else
        {
           while(!q.empty()) //x,y 방향 잘보기
           {
                days+=1;
                int size_q=q.size();
                while(size_q!=0) //날마다 익은것들 갯수 체크한 만큼만 반복
                {
                    pair<int,int> now=q.front();
                    q.pop();
                    for(int i=0;i<4;i++)
                    {
                        int qx=now.second+dx[i];
                        int qy=now.first+dy[i];

                        if(qx>=0 && qx<m && qy>=0 && qy<n)
                        {
                            if(visited[qy][qx]!=1 && box[qy][qx]==0)
                            {
                                visited[qy][qx]=1;
                                q.push({qy,qx});
                            }
                        }
                    }
                    size_q-=1;
                }
            }
        }

        bool check_possi=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(visited[i][j]!=1)
                {
                    check_possi=false;
                } 
            }
        }
        if(check_possi==false) days=-1;

        cout << days;
        return 0;
    }
