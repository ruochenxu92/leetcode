#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int LCSubseq(string& a,string& b)
{
    int m = a.size(), n = b.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    int ans = 0;

    for (int i=1;i<=m;i++)
       for (int j=1;j<=n;j++)
        {
            if (a[i-1]==b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

    return dp[m][n];
}

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int ans = LCSubseq(str1,str2);
        cout << ans << endl;
    }

    return 0;
}
