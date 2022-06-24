[page](https://codeup.kr/problem.php?id=2605&rid=0)

    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>

    int answer=0;
    int data[9][9]={0};
    int visited[9][9]={0};
    int count=0;

    void check(int i,int j)
    {
        if(visited[i+1][j]==0 && data[i+1][j]==data[i][j])
        {
            visited[i+1][j]=1;
            count+=1;
            check(i+1,j);
        }
        if(visited[i-1][j]==0 && data[i-1][j]==data[i][j])
        {
            visited[i-1][j]=1;
            count+=1;
            check(i-1,j);
        }
        if(visited[i][j+1]==0 && data[i][j+1]==data[i][j])
        {
            visited[i][j+1]=1;
            count+=1;
            check(i,j+1);
        }
        if(visited[i][j-1]==0 && data[i][j-1]==data[i][j])
        {
            visited[i][j-1]=1;
            count+=1;
            check(i,j-1);
        }   

    }

    int main()
    {
        // printf("입력 : ");
        for(int i=1;i<8;i++)
        {
            for(int j=1;j<8;j++)
            {
                scanf("%d",&data[i][j]);
            }
        }

        for(int i=1;i<8;i++)
        {
            for(int j=1;j<8;j++)
            {
                count=0;
                check(i,j);
                if(count>=3)
                {
                    answer+=1;
                }   
            }
        }
        printf("%d",answer);
        return 0;
    }
