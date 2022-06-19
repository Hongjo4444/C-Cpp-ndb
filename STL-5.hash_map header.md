1.데이터 추가, auto와 iterator로 접근

    #include <iostream>
    #include <map> //map 헤더파일 사용

    using namespace std;

    int main()
    {
        map<string,int> m; //선언, map의 기본 구조는 map <key type, value type>, 기본적으로 key값 기준 오름차순으로 정렬
        
        m.insert({"Cam", 300}); //데이터 삽입, key가 중복되면 insert가 수행되지 않음
        m.insert({"Alice", 200});
        m["Hong"] = 10; //operator [] 를  사용하여 원소를 추가 시킴
        m["Jo"]++; //key : 4인 원소가 없으므로 생성한뒤 기본값 : 0 에서 1을 더해준다.
        m["Alice"]=400; //value값 변경

        for (auto iter = m.begin() ; iter !=  m.end(); iter++) //반복자, auto+인덱스 기반 반복문 활용(iterator 활용)
        {
            cout << iter->first << " " << iter->second << endl; //first,second로 key,value 접근
        }
        
        cout << m.size() << endl; //크기
        cout << endl;

        return 0;
    }
    
2.key값의 value 조회, find

    #include <iostream>
    #include <map>

    using namespace std;

    int main()
    {
        map<string,int> m;

        m.insert({"Cam", 300});
        m.insert({"Alice", 200});
        m["Hong"] = 10;
        m["Jo"]++;
        m["Alice"]=400;

        cout << m["Alice"] << endl; //해당 key의 value값 조회

        if (m.find("Alice") != m.end()) // 찾고자 하는 데이터가 있는 지 확인하기(문자열을 찾았다면 해당 문자열의 시작 위치를 리턴하고, 그렇지 않을 경우 npos 를 리턴)
        {
          cout << "find" << endl;
        }
        else
        {
          cout << "not find" << endl;
        }

        cout << m.find("Alice")->first << endl; //찾아서 key값 출력하기
        cout << m.find("Alice")->second << endl; //찾아서 value값 출력하기
        cout << endl;

        return 0;
    }
    
3.데이터 삭제

    #include <iostream>
    #include <map>

    using namespace std;

    int main()
    {
        map<string,int> m;

        m.insert({"Cam", 300});
        m.insert({"Alice", 200});
        m["Hong"] = 10;
        m["Jo"]++;
        m["Alice"]=400;

        m.erase(m.begin()); //특정 위치 데이터 삭제
        for (auto iter = m.begin() ; iter !=  m.end(); iter++)
        {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << endl;

        m.erase("Cam"); //특정 key값 삭제
        for (auto iter = m.begin() ; iter !=  m.end(); iter++)
        {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << endl;

        m.clear(); //모든 데이터 삭제
        for (auto iter = m.begin() ; iter !=  m.end(); iter++)
        {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << endl;

        return 0;
    }
    
4.정렬(디폴트는 Key 오름차순 정렬)

    #include <iostream>
    #include <map>
    #include <vector>

    using namespace std;

    bool compare(pair<string, int> a, pair<string, int> b)
    {
        return a.second > b.second; //Value로 정렬(부호로 오름차순, 내림차순 정렬)
    }

    int main()
    {
        map<string,int> m; //디폴트는 Key 오름차순 정렬

        m["Hong"] = 10;
        m["Jo"]++;
        m["Alice"]=400;
        for (auto iter = m.begin() ; iter !=  m.end(); iter++)
        {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << endl;

        map<string,int,greater<string>> mg; // Key 내림차순 정렬(greater 사용)
        mg["Hong"] = 10;
        mg["Jo"]++;
        mg["Alice"]=400;
        for (auto iter = mg.begin() ; iter !=  mg.end(); iter++)
        {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << endl;

        map<string,int,greater<string>> mv; // Value 오름차순 정렬(pair를 원소로 가지는 vector로 복사한 후 Value(second) 기준으로 정렬)
        mv["Hong"] = 10;
        mv["Jo"]++;
        mv["Alice"]=400;

        vector<pair<string,int>> mvv(mv.begin(), mv.end()); // map mv를 vector mvv에 복사(vector 헤더 필요)
        sort(mvv.begin(),mvv.end(),compare); //Value 기준으로 정렬(compare 함수로 오름차순 or 내림차순 정렬)
        for(int i=0;i<mvv.size();i++)
        {
            cout << mvv[i].first << " " << mvv[i].second << endl;
        }

        return 0;
    }

