[page](https://www.acmicpc.net/problem/14852)

    // 길이 n의 타일을 만드는 방법은 길이 n-1일때 2개, n-2일때 3개, n-3일때 2개, n-4일때 2개...(높이2여도 타일 크기가 여러개라 배열을 바꿀 경우 변수 있음)이므로
    // 점화식은 D[n]=2*D[n-1]+3*D[N-2]+(2*D[N-3]+2*D[N-4]+...+2*D[0])

    #include <iostream>

    using namespace std;

    long long int d[1000001][2]={0};

    long long int dp(int x)
    {
        d[0][0]=0;
        d[1][0]=2;
        d[2][0]=7;
        d[2][1]=1;
        for(int i=3;i<=x;i++)
        {
            d[i][1]=(d[i-1][1]+d[i-3][0])%1000000007;
            d[i][0]=(3*d[i-2][0]+2*d[i-1][0]+2*d[i][1])%1000000007; //점화식
            //매 연산마다 나머지 연산을 해야 함(나머지 연산 없이 계산을 모두 해 버리면 이미 overflow 가 발생한 후라서 여기에 나머지 연산을 해도 소용없음)
        }
        return d[x][0];
    }

    int main()
    {
        int x;
        cin >> x;
        cout << dp(x);
    }
