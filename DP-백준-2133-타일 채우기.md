[page](https://www.acmicpc.net/problem/2133)

    // 길이 n의 타일을 만드는 방법은 길이 n-2일때 3개, n-4일때 2개, n-6일때 2개, n-8일때 2개...(높이 3이므로 타일의 배열을 바꿀 경우 변수 있음)이므로
    // 점화식은 D[n]=3*D[n-2]+(2*D[N-4]+2*D[N-6]+...+2*D[0])

    #include <iostream>

    using namespace std;

    int d[1001]={0};

    int dp(int x)
    {
        if(x==0) return 1;
        if(x==1) return 0;
        if(x==2) return 3;
        if(d[x]!=0) return d[x]; //값을 구한적 있으면 바로 그 값 반환

        int result=3*dp(x-2); //점화식에서 맨앞 값
        for(int i=3;i<=x;i++)
        {
            if(i%2==0) //짝수인 경우에 한해 맨앞 값에 더하기
            {
                result+=2*dp(x-i);
            }
        }
        return d[x]=result;
    }

    int main()
    {
        int x;
        cin >> x;
        cout << dp(x);
    }
