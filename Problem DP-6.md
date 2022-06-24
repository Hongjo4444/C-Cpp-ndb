[page](https://www.acmicpc.net/problem/1463)

c++

    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int main()
    { 
      int n;
      cin >> n;
      int data[100001]={0};
      int a,b,c;

      for(int i=2;i<=n;i++)
      {
        a=b=c=1e7; //int a,b,c=1e7로 여기서 지정하면 안됨!
        if(i%3==0) a=data[i/3];
        if(i%2==0) b=data[i/2];
        c=data[i-1];
        data[i]=min({a,b,c})+1;
      }

      cout << data[n];
      return 0;
    }
