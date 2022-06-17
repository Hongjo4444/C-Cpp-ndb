#include <stdio.h> //버블 정렬:옆에 있는 값과 비교해서 더 작은 값을 앞으로 보낸다(=뒤부터 가장 큰값 정렬). 시간 복잡도 O(N^2)

int main()
{
    int i,j,temp;
    int array[10]={10,2,5,1,8,7,6,4,3,9};
    for(int i=0;i<10;i++)
    {
        for(j=0;j<9-i;j++)
        {
            if(array[j]>array[j+1]) //제일 작은 값의 index 기억
            {
                temp=array[j]; //스와핑
                array[j]=array[j+1];
                array[j+1]=temp;    
            }
        }
    }

    for(int i=0;i<10;i++) //정렬된 원소 출력
    {
        printf("%d ",array[i]);
    }
    return 0;
}
