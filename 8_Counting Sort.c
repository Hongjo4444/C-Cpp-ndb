#include <stdio.h> //계수 정렬:크기를 기준으로 갯수를 세는 방법. 시간 복잡도 O(N), 작은 범위 조건이 있는경우 매우 빠름

int main()
{
    int temp;
    int count[5];
    int array[30]={1,2,3,5,3,2,4,5,4,1,2,3,4,5,1,2,3,4,1,2,3,4,5,3,4,1,2,1,3,2};

    for(int i=0;i<5;i++) //배열 초기화
    {
        count[i]=0;
    }

    for(int i=0;i<30;i++) //갯수 세기
    {
        count[array[i]-1]++;
    }

    for(int i=0;i<5;i++) //갯수만큼 원소 출력
    {
        if(count[i]!=0)
        {
            for(int j=0;j<count[i];j++)
            {
                printf("%d ",i+1);
            }
        }
    }
    return 0;
}
