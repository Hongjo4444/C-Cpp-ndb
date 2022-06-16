#include <stdio.h> //힙 정렬:최솟값이나 최댓값을 빠르게 찾아내기 위해 완전 이진 트리를 기반으로 하는 힙을 이용한 정렬. 시간 복잡도 O(N*logN)

int number=9;
int heap[9]={7,6,5,8,3,5,9,1,6};

int main()
{
    for(int i=1;i<number;i++) //전체 트리 구조를 최대 힙 구조로 바꾸기
    {
        int c=i; //자식 노드
        do
        {
            int root=(c-1)/2; //부모 노드
            if(heap[root]<heap[c]) //부모 값<자식 값이면 위치 바꾸기
            {
                int temp=heap[root];
                heap[root]=heap[c];
                heap[c]=temp;
            }
            c=root; //자식의 부모로 이동해서 반복적으로 수행
        } while(c!=0);
    }
    
    for(int i=number-1;i>=0;i--) //크기(i)를 줄여가며 반복적으로 힙 구성하여 정렬(루트 노드(가장 큰 값)와 맨뒤 값과 바꾸고 크기 줄이기)
    {
        int temp=heap[0];
        heap[0]=heap[i];
        heap[i]=temp;
        int root=0;
        int c;
        do //반복적으로 힙구조 만들기
        {
            c=(2*root)+1; //자식 노드
            if(heap[c]<heap[c+1] && c<i-1) //범위 안에서 자식 중에 더 큰값 찾기
            {
                c++;
            }
            if(heap[root]<heap[c] && c<i) //범위 안에서 자식이 부모보다 크면 값 바꾸기
            {
                int temp=heap[root];
                heap[root]=heap[c];
                heap[c]=temp;
            }
            root=c;
        } while(c<i);
    }

    for(int i=0;i<number;i++) //정렬된 원소 출력
    {
        printf("%d ",heap[i]);
    }
    return 0;
}
