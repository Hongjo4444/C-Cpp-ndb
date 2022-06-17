#include <stdio.h> //병합 정렬:크기가 1인 배열로 시작해서 단계별로 크기가 2의 배수인 배열로 합치는 순간 정렬하고 나중에 합쳐서 정렬. 시간 복잡도 O(N*logN)

int number=8;
int sorted[8]; //정렬 배열은 항상 전역 변수로 선언

void merge(int a[],int m,int middle,int n) //시작점,중간점,끝점 지정
{
    int i=m; //병합전 첫번째 그룹 첫 자리
    int j=middle+1; //병합전 두번째 그룹 첫 자리
    int k=m; //병합 후 생성된 그룹 첫 자리

    while(i<=middle && j<=n) //i,j를 비교해서 작은 순서대로 k에 삽입
    {
        if(a[i]<=a[j])
        {
            sorted[k]=a[i];
            i++;
        }
        else
        {
            sorted[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>middle) //i가 먼저 끝났을 경우 남은 j 데이터 삽입
    {
        for(int t=j;t<=n;t++)
        {
            sorted[k]=a[t];
            k++;
        }
    }
    else //j가 먼저 끝났을 경우 남은 i 데이터 삽입
    {
        for(int t=i;t<=middle;t++)
        {
            sorted[k]=a[t];
            k++;
        }
    }
    for(int t=m;t<=n;t++) //정렬된 a배열을 실제 sorted배열에 삽입
    {
        a[t]=sorted[t];
    }
}

void mergeSort(int a[],int m,int n)
{
    if(m<n) //크기가 1보다 큰 경우만 따지기
    {
        int middle=(m+n)/2;
        mergeSort(a,m,middle); //왼쪽 병합정렬 수행
        mergeSort(a,middle+1,n); //오른쪽 병합정렬 수행
        merge(a,m,middle,n); //합치기
    }
}

int main()
{
    int array[8]={7,6,5,8,3,5,9,1};
    mergeSort(array,0,number-1);
    for(int i=0;i<number;i++) //정렬된 원소 출력
    {
        printf("%d ",array[i]);
    }
    return 0;
}
