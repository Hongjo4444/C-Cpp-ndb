[참고](https://hwan-shell.tistory.com/119)

1.vector 초기화

    #include <iostream>
    #include <vector>

    using namespace std;

    int main()
    {
      vector<int> a; //int형 백터 생성

      vector<int> b(4); //int형 백터 생성 후 크기를 4로 할당(모든 백터요소 0으로 초기화)

      vector<int> c = { 1, 2, 3}; //int형 백터 생성 후 1, 2, 3 으로 초기화

      vector<int> d[] = {{ 1, 2}, {3, 4}}; //int형 백터 배열 생성(행은 가변이지만 열은 고정)

      vector<vector<int> > d; //2차원 백터 생성(행과 열 모두 가변)

      vector<int> e = { 1, 2, 3, 4, 5}; //백터 범위를 5로 지정하고 정수 10으로 초기화(output : 10 10 10 10 10)
      e.assign(5, 10);

      return 0;
    }

2.vector의 iterator
v.begin() : 백터 시작점의 주소 값 반환
v.end() : 백터 (끝부분 + 1) 주소값 반환
v.rbegin() : revers begin, 백터의 끝 지점을 시작점으로 반환 
v.rend() : revers end, 백터의 (시작 + 1) 지점을 끝 부분으로 반환 

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <functional> //함수자 less<>,greater<> 쓸때 필요

    using namespace std;

    int main()
    {
        vector<int> v(5);
        cout << v.size() << ":" << v.capacity() << endl; //size는 저장된 데이터 요소의 수, capacity는 할당된 메모리 공간의 크기
        for(int i=0;i<v.size();i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        for(int i=0;i<v.size();i++) //원소 추가
        {
            v[i]=i+1;       
        }
        for(int i=0;i<5;i++)
        {
            v.push_back(10-i);
        }
        for(int i=0;i<v.size();i++) //출력
        {
            cout << v[i] << " ";
        }
        cout << endl;

        sort(v.begin(),v.end(),greater<int>()); //greater 사용
        for(int i=0;i<v.size();i++) //출력
        {
            cout << v[i] << " ";
        }
        cout << endl;

        vector<int>::iterator iter; //iterator(주소값) 사용
        for(iter=v.begin();iter!=v.end();iter++) //*iter가 가르키는  원소 출력
        {
            cout << *iter << " ";
        }
        return 0;
    }
   
4.vector의 요소 접근

    #include <iostream>
    #include <vector>

    using namespace std;

    int main()
    {
        vector<int> v = { 1, 2, 3, 4};

        cout << v.front() << endl; //output : 1
        cout << v.back() << endl; //output : 4
        cout << v.at(1) << endl; //output : 2, at은 범위를 검사하여 범위 밖의 요소에 접근 시 예외처리를 발생시킵니다. (std::out_of_range)
        cout << v[2] << endl; //output : 3​, [](operator [])는 범위검사를 하지 않으며 예외처리르 발생시키지 않습니다. 보통 []를 권장

        return 0;
    }
    
3.vector에 요소 삽입,삭제(삽입과 삭제가 빈번히 일어날경우 vector보단 list나 deque를 사용하는 것이 바람직함)
    
    #include <iostream>
    #include <vector>

    using namespace std;

    int main()
    {
        vector<int> v;

        v.push_back(10);
        v.push_back(20); //백터의 마지막 부분에 새로운 요소 추가, v = { 10, 20 }

        v.inset(v.begin() + 1, 100); //사용자가 원하는 위치에 요소 삽입, v = { 10, 100, 20 }

        v.pop_back(); //백터의 마지막 부분 제거, v = { 10, 100 }


        v.emplace_back(1); //백터의 마지막 부분에 새로운 요소 추가(move로 인해 복사생성자 X), v = { 10, 100, 1 }
        v.emplace_back(2); //v = { 10, 100, 1, 2 }
        v.emplace(v.begin() + 2, -50); //사용자가 원하는 위치에 요소 삽입(move로 인해 복사생성자 X), v = { 1, 100, -50, 1, 2 }

        v.erase(v.begin() + 1); // 사용자가 원하는 index값의 요소를 삭제, v = { 1, -50, 1, 2 }
        v.resize(6);    //  백터의 사이즈를 조정(범위 초과시 0으로 초기화), v = { 1, -50, 1, 2, 0, 0 }
        v.clear();    // 백터의 모든 요소를 삭제(return size = 0), v = empty()

        // v.swap(백터 변수):백터와 백터를 스왑

        return 0;
    }

5.벡터의 용량
    
    #include <iostream>
    #include <vector>

    using namespace std;

    int main()
    {
        vector<int>v = { 1, 2, 3, 4 };

        cout << v.size() << endl;    //백터의 크기 반환, output : 4
        cout << v.capacity() << endl; //heap에 할당된 백터의 실제크기(최대크기) 반환, output : 10 (컴파일 환경에 따라 달라질 수 있음)

        v.reserve(6); //백터의 크기 설정
        cout << v.capacity() << endl; //output : 6
        cout << v.max_size() << endl; //백터가 system에서 만들어 질 수 있는 최대 크기 반환, output : 1073741823(시스템 성능에 따라 달라질 수 있음)

        v.shrink_to_fit(); //capacity의 크기를 백터의 실제 크기에 맞춤
        cout << v.capacity() << endl; //output : 4

        cout << v.empty() << endl; //백터가 빈공간이면 true 값이 있다면 false, output : false
        v.clear();
        cout << v.empty() << endl; //output : true​

        return 0;
    }
