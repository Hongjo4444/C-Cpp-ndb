[page](https://codeup.kr/problem.php?id=4787)

c++

    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int n,c;
    int m;
    int truck[2001]; //마을별로 트럭에 싣은 택배개수 저장
    int cnt;
    vector <pair<pair<int,int>,int>> list;

    bool compare(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b) //받는마을 기준으로 오름차순 정렬(같을경우 보내는마을이 빠른 순으로)
    {
      if(a.first.second==b.first.second) return a.first.first<b.first.first;
      else return a.first.second<b.first.second;
    }

    int main()
    { 
      cin >> n >> c >> m;

      for(int i=0;i<m;i++)
      {
        int x, y, z;
        cin >> x >> y >> z;
        list.push_back({{x,y},z}); //이중 pair 벡터에 넣는것이므로 양식 지켜서 넣어야함
      }

      sort(list.begin(),list.end(),compare);

      for(int i=0;i<list.size();i++)
      {
        int from=list[i].first.first;
        int to=list[i].first.second;
        int box=list[i].second;

        int max_truck=0; //현재 택배가 지나가야할 트럭 배열값 중 가장 큰 것
        for(int j=from;j<to;j++)
        {
          max_truck=max(truck[j],max_truck);
        }

        int capa=min(box,c-max_truck); //가져갈 수 있는 택배수

        for(int j=from;j<to;j++)
        {
          truck[j]+=capa; //출밟퉈 도착까지 가능한 택배수 할당
        }

        cnt+=capa;
      }

      cout << cnt;  
      return 0;
    }
