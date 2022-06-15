#include <stdio.h> //퀵 정렬:특정한 값을 기준으로 큰 숫자와 작은 숫자를 다른 그룹으로 나눈다. 시간 복잡도 O(N*logN),피벗값 잘못 선택하면 시간 복잡도 O(N^2)

int number=10;
int data[10]={10,2,5,1,8,7,6,4,3,9};

void quickSort(int *data,int start,int end)
{
    if(start>=end) //원소가 1개인 경우
    {
        return;
    }
    int pivot=start; //가장 앞에있는 값을 피벗값으로 사용
    int i=start+1; //왼쪽 끝에서 이동하면서 피벗값보다 작은 값 찾기
    int j=end; //오른쪽 끝에서부터 이동하면서 피벗값보다 큰 값 찾기
    int temp;
    while(i<=j) //엇갈리지 않을때까지 반복
    {
        while(data[i]<=data[pivot]) //왼쪽 값이 피벗값보다 작을경우 반복
        {
            i++;
        }
        while(data[j]>=data[pivot] && j>start) //오른쪽 값이 피벗값보다 클경우 반복(start보다 더 가지않게 설정)
        {
            j--;
        }
        if(i>j) //엇갈릴경우 왼쪽값과 피벗값 바꾸기
        {
            temp=data[j];
            data[j]=data[pivot];
            data[pivot]=temp;
        }
        else //엇갈리지 않을 경우 큰값과 작은값 바꾸기
        {
            temp=data[j];
            data[j]=data[i];
            data[i]=temp;
        }
    }
    quickSort(data,start,j-1); //그룹을 나눠서 그룹별로 피벗값 다시 선정하고 재실행
    quickSort(data,j+1,end);
}

int main()
{
    quickSort(data,0,number-1);

    for(int i=0;i<10;i++) //정렬된 원소 출력
    {
        printf("%d ",data[i]);
    }
    return 0;
}
