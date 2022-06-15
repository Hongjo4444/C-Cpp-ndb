#include <stdio.h> //삽입 정렬:각 숫자를 적절한 위치에 보낸다(왼쪽과 비교해서 적절한 위치로 이동). 시간 복잡도 O(N^2),거의 정렬된 상태라면 가장 빠름

int main()
{
    int i,j,temp;
    int array[10]={10,2,5,1,8,7,6,4,3,9};
    for(int i=0;i<9;i++)
    {
        j=i;
        while(array[j]>array[j+1])
        {
            {
                temp=array[j]; //스와핑
                array[j]=array[j+1];
                array[j+1]=temp;
                j--;
            }
        }
    }

    for(int i=0;i<10;i++) //정렬된 원소 출력
    {
        printf("%d ",array[i]);
    }
    return 0;
}
