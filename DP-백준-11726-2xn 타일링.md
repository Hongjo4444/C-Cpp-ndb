[page](https://www.acmicpc.net/problem/11726)

    //길이 n의 타일을 만드는 방법은 길이 n-1일때 1개, n-2일때 1개(높이 2짜리인거까지 있으므로 변수 없음)이므로 점화식은 D[n]=D[n-1]+D[n-2]

    #include <iostream>

    using namespace std;

    int d[1001]={0};

    int dp(int x)
    {
        if(x==1) return 1;
        if(x==2) return 2;
        if(d[x]!=0) return d[x]; //값을 구한적 있으면 바로 그 값 반환
        return d[x]=(dp(x-1)+dp(x-2))%10007;
        //매 연산마다 나머지 연산을 해야 함(나머지 연산 없이 계산을 모두 해 버리면 이미 overflow 가 발생한 후라서 여기에 나머지 연산을 해도 소용없음)
    }

    int main()
    {
        int x;
        cin >> x;
        cout << dp(x);
    }
