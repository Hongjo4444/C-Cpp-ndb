[참고](https://ansohxxn.github.io/stl/string/)

1.substr:원래 문자열에서 해당하는 범위의 부분 문자열을 리턴한다.

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string a="abcdefghijklmnopqrstuwxyz";

        cout << a.substr(10) << endl; // a 문자열의 인덱스10 ~ 끝까지
        cout << a.substr(5, 3); // a 문자열의 인덱스 5 ~ 인덱스 8 (=5+3) 리턴

        return 0;
    }

2.find:원래 문자열이 해당하는 문자열을 포함하는지 찾는다.

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string a="abcdefghijklmnopqrstuwxyz";

        int n;
        n = a.find("cd");  // a 문자열 중 부분적으로 "is"를 포함하는지 찾고 찾았다면 그 문자열의 시작 위치를 리턴한다.(못찾으면 -1 리턴)
        cout << n << endl;
        n = a.find("cd", 5); // a 문자열 중 부분적으로 "is"를 포함하는지를 5번째 인덱스부터 찾는다. 찾았다면 그 문자열의 시작 위치를 리턴한다.
        cout << n;

        return 0;
    }

3.stoi:문자열을 정수로 변환한다.(변환이 가능한 부분까지만 변환,부호 알아서 처리). 
(atoi:정수를 문자열 변환, stoul:절댓값으로 변환, to_string:정수나 실수를 문자열 변환)

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string str1 = "123 안녕";
        int a = stoi(str1);  // 정수 123 까지만 들어감.
        cout << a <<endl;

        string str2 = "0012";
        int b = stoi(str2);  // 문자열 0012 를 정수로 변환하면 12
        cout << b;

        return 0;
    }

4.front,back:맨 앞글자 출력, 맨 뒷글자 출력

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string s = "Hello, World!";
        
        cout << s.front() << endl;  // 맨 앞글자인 'H' 출력
        cout << s.back() << endl;  // 맨 뒷글자인 '!' 출력

        return 0;
    }

5.'+':문자열끼리 이어붙이기

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string a = "Hello";
        string b = "World!";
        
        string c = a + ", " + b; // "Hello, World!"
        cout << c;

        return 0;
    }

6.append:호출하는 문자열의 뒤에 인수로 들어온 문자열을 붙인다.('+'연산자보다 빠르다)

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string a = "Hello";
        string b = "World";
        string c = "Hi";
        string d = "H";
        
        a.append(b, 0, 3);  // "HelloWor"가 된다. 문자열 b 의 0 인덱스로부터 3 개 ("Wor")를 a 뒤에 붙이기 
        cout << a << endl;
        c.append(b, 2);  // "Hirld"가 된다. 문자열 b의 처음부터 2 개를 제외한 ("rld")를 c 뒤에 붙이기
        cout << c << endl;
        d.append(3, '*'); // "H***" 가 된다. char c 문자를 num 개수만큼 반복해서 뒤에 붙여라
        cout << d;

        return 0;
    }

7.push_back:문자 1개만 append와 같이 뒤에 덧붙인다.

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string str="abcdefghijklmnopqrstuwxyz";
        
        str.push_back('A');
        cout << str;

        return 0;
    }

8.insert:호출한 문자열의 인수로 넘기는 인덱스에, 인수로 넘기는 문자 혹은 문자열을 삽입

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string alp="abc";

        alp.insert(1,2,'k'); //"akkbc"가 된다. 인덱스 1에 2번 반복해서 문자 'k' 삽입
        cout << alp << endl;

        alp.insert(2,"fc"); //"akfckbc"가 된다. 인덱스 2에 문자열 "fc" 삽입
        cout << alp << endl;

        alp.insert(0,"wxyz",2); //"wxakfckbc"가 된다. 인덱스 0에 문자열 "wxyz"의 2개만큼 삽입
        cout << alp << endl;

        alp.insert(0,"asss",1,2); //"sswxakfckbc"가 된다. 인덱스 0에 문자열 "asss"의 인덱스 1부터 2개를 삽입
        cout << alp;

        return 0;
    }

9.swap:서로 string 문자열 값을 교환

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string str1="abc";
        string str2="wxyz";

        str1.swap(str2);
        cout << str1;

        return 0;
    }

10.max_size:최대한으로 메모리를 할당했을 경우 저장할 수 있는 문자열의 길이

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string str="abc";

        cout << str.max_size();

        return 0;
    }

11.copy(c언어 처럼 마지막에 '\0'써야함)

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string my_str("abcdefg");
        char buf[20];

        my_str.copy(buf, 5, 1); //buf 빈 문자열 배열에 my_str string 문자열 중 5글자를 복사. 1번째 인덱스부터 복사 시작.
        buf[5] ='\0'; //‘\0’은 복사해주지 않으므로 직접 마지막에 붙여준다. (std::string은 ‘\0’가 없다)
        cout << buf << endl;

        return 0;
    }

12.string 에 char 붙이기(str.push_back(msg[2]); 도 가능)

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string msg="dsadasd";
        string str = "";

        str += msg[2];
        cout << str;

        return 0;
    }
