[page](https://www.acmicpc.net/problem/1431)

    #include <iostream>
    #include <algorithm>

    using namespace std;

    string a[20000];
    int n;

    int getSum(string a)
    {
      int length=a.length(),sum=0;
      for(int i=0;i<length;i++)
      {
        if(a[i]-'0'>=0 && a[i]-'0'<=9)
        {
          sum+=a[i]-'0';
        }
      }
      return sum;
    }

    bool compare(string a,string b)
    {
      if(a.length()<b.length()) //길이가 짧은 순서로 정렬
      {
        return 1;
      }
      else if(a.length()>b.length())
      {
        return 0;
      }
      else //길이가 같은경우 글자에 포함된 숫자의 합 비교
      {
        int aSum=getSum(a);
        int bSum=getSum(b);
        if(aSum!=bSum) //글자에 포함된 숫자의 합이 다를때 숫자의 합의크기가 작은순서로 정렬
        {
          return aSum<bSum;
        }
        else //글자에 포함된 숫자의 합이 같을때 사전순으로 정렬
        {
          return a<b;
        }
      }
    }

    int main(void)
    {
      cin >> n;
      for(int i=0;i<n;i++)  //n개만큼 입력 받기
      {
        cin >> a[i];
      }
      sort(a,a+n,compare); //주소값 a부터 끝(a+n)까지(포인터로 접근한것) compare 함수 조건으로 정렬
      for(int i=0;i<n;i++)
      {
        if(i>0 && a[i]==a[i-1]) //동일한 값인경우 패스
        {
          continue;
        }
        else
        {
          cout << a[i] << " ";
        }
      }
    }
