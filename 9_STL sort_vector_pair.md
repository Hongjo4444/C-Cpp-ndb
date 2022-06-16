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
   

2.Sort()함수 정렬 기준 설정

    #include <iostream>
    #include <algorithm>

    using namespace std;

    bool compare(int a,int b) //true,false 값을 통해 정렬기준 설정
    {
      return a<b; //a<b일때를 우선적으로 정렬(더 작은값이 앞으로 가는 오름차순 정렬)
    }

    int main(void)
    {
      int a[10]={9,3,5,4,1,10,8,6,7,2};
      sort(a,a+10,compare);
      for(int i=0;i<10;i++)
      {
        cout << a[i] << " ";
      }
    }
    
    
3.특정한 변수를 기준으로 정렬(모든 데이터들이 객체로 정리되어있는 실무에서 사용)-코딩테스트에서는 사용X

    #include <iostream>
    #include <algorithm>

    using namespace std;

    class Student //class 사용(새로운 자료형을 만든다고 생각)
    {
      public:
      string name;
      int score;
      Student(string name,int score) //학생의 이름,점수 입력받는 생성자 만들기(특정한 객체를 초기화 하기위해서 사용)
      {
        this -> name = name;
        this -> score = score;
      }
      bool operator<(const Student&student)const //점수가 작은 순서로 정렬 기준 설정
      {
        return this -> score<student.score;
      }
    };

    int main(void)
    {
      Student students[]=
      {
        Student("홍",90),
        Student("지",91),
        Student("호",92),
        Student("홍지",93),
        Student("지호",94)
      };
      sort(students,students+5);
      for(int i=0;i<5;i++)
      {
        cout << students[i].name << " ";
      }
    }


4.변수가 2개일때 pair 라이브러리를 이용한 특정한 변수를 기준으로 정렬-코딩테스트에서 사용O

    #include <iostream>
    #include <algorithm>
    #include <vector> //연결리스트 형태로 표현되는 vector 헤더파일(단순 배열과 vector는 큰 차이가 없음)

    using namespace std;

    int main(void)
    {
        vector<pair<int,string> > v; //한 쌍(2개)의 데이터를 다루기위해 사용하는 라이브러리
        v.push_back(pair<int,string>(95,"홍")); //push_back():리스트의 마지막 부분에 삽입하는 vector에 붙어있는 함수
        v.push_back(pair<int,string>(94,"지"));
        v.push_back(pair<int,string>(93,"호"));
        v.push_back(pair<int,string>(92,"홍지"));
        v.push_back(pair<int,string>(91,"지호"));

        sort(v.begin(),v.end()); //begin():첫번째 값, end():마지막 값

        for(int i=0;i<v.size();i++) //size():vector의 크기를 가져오는데 사용하는 vector에 붙어있는 함수
        {
            cout << v[i].second << " "; //second:두번째 값(여기에선 string)을 의미
        }
    }


5.변수가 3개일때 pair 라이브러리를 이용한 특정한 변수를 기준으로 정렬-코딩테스트에서 사용O

