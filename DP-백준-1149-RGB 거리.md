[page](https://www.acmicpc.net/problem/1149)

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
      int cost[3][1000];

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<3;j++)
        {
          cin >> cost[i][j];
        }
      }

      for(int i=1;i<n;i++)
      {
        for(int j=0;j<3;j++)
        {
          if(j==0) cost[i][0]+=min(cost[i-1][1],cost[i-1][2]);
          if(j==1) cost[i][1]+=min(cost[i-1][0],cost[i-1][2]);
          if(j==2) cost[i][2]+=min(cost[i-1][0],cost[i-1][1]);
        }
      }

      cout << min({cost[n-1][0],cost[n-1][1],cost[n-1][2]});

      return 0;
    }
