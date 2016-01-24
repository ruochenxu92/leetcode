#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int LCSubstring(string& a,string& b)
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
                ans = max(ans,dp[i][j]);
            }
        }

    return ans;
}

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int ans = LCSubstring(str1,str2);
        cout << ans << endl;
    }

    return 0;
}
