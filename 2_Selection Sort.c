#include <stdio.h> //선택 정렬:가장 작은것을 선택해서 제일 앞으로 보낸다(앞부터 가장 작은값 정렬). 시간 복잡도 O(N^2)

int main()
{
    int i,j,min,index,temp;
    int array[10]={10,2,5,1,8,7,6,4,3,9};
    for(int i=0;i<10;i++)
    {
        min=1e7; //다 포함할 수 있는 가장 큰 값 넣기
        for(j=i;j<10;j++)
        {
            if(min>array[j]) //제일 작은 값의 index 기억
            {
                min=array[j];
                index=j;
            }
        }
        temp=array[i]; //스와핑
        array[i]=array[index];
        array[index]=temp;
    }

    for(int i=0;i<10;i++) //정렬된 원소 출력
    {
        printf("%d ",array[i]);
    }
    return 0;
}
