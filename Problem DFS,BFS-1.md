[page](https://codeup.kr/problem.php?id=4714&rid=0)

c

    #include <stdio.h>

    int matrix_up[501][501]={0};
    int matrix_down[501][501]={0};
    int visited[501]={0};
    int n,m;

    void dfs_up(int u)
    {
        visited[u]=1;
        for(int k=1;k<=n;k++)
        {
            if(matrix_up[u][k]==1 && visited[k]==0) dfs_up(k);
        }
    }

    void dfs_down(int d)
    {   
        visited[d]=1;
        for(int k=1;k<=n;k++)
        {
            if(matrix_down[k][d]==1 && visited[k]==0) dfs_down(k);
        }
    }

    int main()
    {
        scanf("%d",&n);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            matrix_up[a][b]=1; //작은데서 큰데 연결
            matrix_down[a][b]=1;
        }

        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int l=1;l<=n;l++)
            {
                visited[l]=0;
            }
            dfs_up(i);
            dfs_down(i);
            int check_visited=0;
            for(int j=1;j<=n;j++)
            {
                if(visited[j]!=1) check_visited=1;
            }
            if(check_visited==0) cnt+=1;
        }

        printf("%d",cnt);
        return 0;
    }
