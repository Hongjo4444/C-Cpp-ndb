[page](https://codeup.kr/problem.php?id=3120)

    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    int main()
    {
      int degree[3]={1,5,10};
      int a,b;
      int cnt=0;
      cin >> a >> b;

      while(a!=b)
      {
        if(a<b)
        {
          int tmp=a;
          a=b;
          b=tmp;
        }
        int result=a-b;
        int index;
        for(int i=0;i<3;i++)
        {
          if(abs(a-b-degree[i])<result)
          {
            result=abs(a-b-degree[i]);
            index=i; //차이가 클경우 10으로 먼저 다 줄여주기
          }
        }
        a-=degree[index];
        cnt+=1;
      }

      cout << cnt;
      return 0;
    }
