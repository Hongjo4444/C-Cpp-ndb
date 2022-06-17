[참고](https://ansohxxn.github.io/stl/string/)

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a="abcdefghijklmnopqrstuwxyz";
    
    //substr:원래 문자열에서 해당하는 범위의 부분 문자열을 리턴한다.
    a.substr(10);  // a 문자열의 인덱스10 ~ 끝까지
    a.substr(5, 3); // a 문자열의 인덱스 5 ~ 인덱스 8 (=5+3) 리턴

    //find:원래 문자열이 해당하는 문자열을 포함하는지 찾는다.
    int n;
    n = a.find("is");  // a 문자열 중 부분적으로 "is"를 포함하는지 찾고 찾았다면 그 문자열의 시작 위치를 리턴한다.
    n = a.find("is", 5); // a 문자열 중 부분적으로 "is"를 포함하는지를 5번째 인덱스부터 찾는다. 찾았다면 그 문자열의 시작 위치를 리턴한다.

    //stoi:문자열을 정수로 변환한다.(변환이 가능한 부분까지만 변환,부호 알아서 처리)
    string str1 = "123 안녕";
    int a = stoi(str1);  // 정수 123 까지만 들어감.
    string str2 = "0012";
    int b = stoi(str2);  // 문자열 0012 를 정수로 변환하면 12
    //atoi:정수를 문자열 변환, stoul:절댓값으로 변환, to_string:정수나 실수를 문자열 변환

    //front,back:맨 앞글자 출력, 맨 뒷글자 출력
    string s = "Hello, World!";
    cout << s.front() << endl;  // 맨 앞글자인 'H' 출력
    cout << s.back() << endl;  // 맨 뒷글자인 '!' 출력

    //'+':문자열끼리 이어붙이기
    string a = "Hello";
    string b = "World!";
    string c = a + ", " + b; // "Hello, World!"

    //append:호출하는 문자열의 뒤에 인수로 들어온 문자열을 붙인다.('+'연산자보다 빠르다)
    string a = "Hello";
    string b = "World";
    string c = "Hi";
    string d = "H";
    a.append(b, 0, 3);  // "HelloWor"가 된다. 문자열 b 의 0 인덱스로부터 3 개 ("Wor")를 a 뒤에 붙이기 
    c.append(b, 2);  // "HiWo"가 된다. 문자열 b의 처음부터 2 개 ("Wo")를 a 뒤에 붙이기
    d.append(3, '*'); // "H***" 가 된다. char c 문자를 num 개수만큼 반복해서 뒤에 붙여라

    //push_back:문자 1개만 append와 같이 뒤에 덧붙인다.
    str.push_back('A');

    // //insert:호출한 문자열의 인수로 넘기는 인덱스에, 인수로 넘기는 문자 혹은 문자열을 삽입
    // basic_string& insert(size_type index, size_type count, CharT ch);  // ch를 count만큼 반복하여 이를 호출한 문자열의 index 인덱스에 삽입
    // basic_string& insert(size_type index, const CharT* s);  // s 문자열을 호출한 문자열의 index 인덱스에 삽입
    // basic_string& insert(size_type index, const CharT* s, size_type count);  // s 문자열의 count 문자 개수만큼 호출한 문자열의 index 인덱스에 삽입
    // basic_string& insert(size_type index, const basic_string& str);  
    // basic_string& insert(size_type index, const basic_string& str, size_type index_str, size_type count = npos);  // s 문자열의 index_str count 문자 개수만큼 호출한 문자열의 index 인덱스에 삽입인덱스로부터 

    //swap:서로 string 문자열 값을 교환
    str1.swap(str2);

    //max_size:최대한으로 메모리를 할당했을 경우 저장할 수 있는 문자열의 길이
    str.max_size();

    //copy(c언어 처럼 써야함)
    string my_str("abcdefg");
    char buf[20];
    my_str.copy(buf, 5, 1); //buf 빈 문자열 배열에 my_str string 문자열 중 5글자를 복사. 1번째 인덱스부터 복사 시작.
    buf[5] ='\0'; //‘\0’은 복사해주지 않으므로 직접 마지막에 붙여준다. (std::string은 ‘\0’가 없다)
    cout << buf << endl;

    //string 에 char 붙이기(str.push_back(msg[2]); 도 가능)
    string msg="dsadasd";
    string str = "";
    str += msg[2];
    
    return 0;
}
