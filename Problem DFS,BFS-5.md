[page](https://codeup.kr/problem.php?id=4697&rid=0)

c

    #include <stdio.h>

    int n;
    int map[101][101]={0};
    int visited[101][101]={0};
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int cnt=0;

    void check(int xx,int yy)
    {
        visited[xx][yy]=1;
        for(int l=0;l<4;l++)
        {
            int xx_now=xx+dx[l];
            int yy_now=yy+dy[l];
            if(xx_now>=0 && xx_now<n && yy_now>=0 && yy_now<n)
            {
                if(visited[xx_now][yy_now]==0) check(xx_now,yy_now);
            }
        }   
    }

    int main()
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }

        for(int k=1;k<101;k++)
        {
            for(int i=0;i<101;i++) //초기화
            {
                for(int j=0;j<101;j++)
                {
                   visited[i][j]=0;
                }
            }

            for(int i=0;i<n;i++) //높이이하인곳 체크
            {
                for(int j=0;j<n;j++)
                {
                    if(map[i][j]<=k)
                    {
                        visited[i][j]=1;
                    }
                }
            }

            int now=0; //안전한 땅덩이 갯수 체크
            for(int o=0;o<n;o++)
            {
                for(int p=0;p<n;p++)
                {
                    if(visited[o][p]==0)
                    {
                        check(o,p);
                        now+=1;
                    }
                }
            }
            if(now>=cnt) cnt=now;
        }

        if(cnt==0) cnt=1;
        printf("%d",cnt);
        return 0;
    }
