1.Sort()함수 기본

    #include <iostream>
    #include <algorithm>

    using namespace std;

    int main(void)
    {
      int a[10]={9,3,5,4,1,10,8,6,7,2};
      sort(a,a+10); //시작 주소, 끝 주소 넣기(끝이 a+9가 아니고 a+10(원소 전체갯수)
      for(int i=0;i<10;i++)
      {
        cout << a[i] << " ";
      }
    }
    
2.
