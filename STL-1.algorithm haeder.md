1.Sort()함수 기본

    #include <iostream>
    #include <algorithm>

    using namespace std;

    int main()
    {
      int a[10]={9,3,5,4,1,10,8,6,7,2};
      sort(a,a+10); //시작 주소, 끝 주소 넣기(끝이 a+9가 아니고 a+10(원소 전체갯수)
      for(int i=0;i<10;i++)
      {
        cout << a[i] << " ";
      }
      return 0;
    }
    
2.Sort()함수 내림차순 정렬

    #include <iostream>
    #include <algorithm>

    using namespace std;

    int main()
    {
      int a[10]={9,3,5,4,1,10,8,6,7,2};
      sort(a,a+10,greater<int>()); //comapare함수 만드는것 대신 greater<int>() 사용
      for(int i=0;i<10;i++)
      {
        cout << a[i] << " ";
      }
      return 0;
    }
                    
3.Sort()함수 최댓값,최솟값 찾기
                    
    #include <iostream>
    #include <algorithm>

    using namespace std;

    int main()
    {
      int a[10]={9,3,5,4,1,10,8,6,7,2};

      cout << *max_element(a,a+10) << endl; //범위 내에서 최댓값 찾기
      cout << *min_element(a,a+10) << endl; //범위 내에서 최솟값 찾기
      return 0;
    }
    
4.unique함수와 erase함수를 이용한 중복 제거

    #include<iostream>
    #include<algorithm>
    #include<vector>

    using namespace std;

    int main()
    {
        vector<int> v;

        v.push_back(1);
        v.push_back(2);
        v.push_back(1);
        v.push_back(3);
        v.push_back(3);

        sort(v.begin(), v.end()); //unique함수 사용하려면 sort해야함
        for (int i = 0; i < v.size(); i++) //확인
        {
            cout << v[i] << " ";
        }
        cout << endl;

        // unique(v.begin(),v.end()); //unique함수
        // for (int i = 0; i < v.size(); i++) //확인(반복되는 값 쓰레기값되고 뒤에 붙여짐)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << endl;

        v.erase(unique(v.begin(), v.end()),v.end()); //unique함수를 사용한 반복부분 삭제
        for (int i = 0; i < v.size(); i++) //확인
        {
            cout << v[i] << " ";
        }
        return 0;
    }
