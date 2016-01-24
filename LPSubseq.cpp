#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

// 相当于与逆序求LCS
// 得出的长度肯定对，但是答案不一定对
// 截取前len/2，再次一定对
// 注意len的奇偶判断
void LPSubseq(string& a,string& b)
{
    int m = a.size(), n = b.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));

    char dir[m+1][n+1];
    dir[0][0] = 's';
    for (int i=1;i<=m;i++)
        dir[i][0] = '|';
    for (int i=1;i<=n;i++)
        dir[0][i] = '-';

    for (int i=1;i<=m;i++)
       for (int j=1;j<=n;j++)
        {
            if (a[i-1]==b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                dir[i][j] = '\\';
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if (dp[i][j]==dp[i-1][j])
                    dir[i][j] = '|';
                else
                    dir[i][j] = '-';
            }
        }

    cout << dp[m][n] << endl;

    string tmp;
    int x = m, y = n;
    while (dir[x][y]!='s')
    {
        char c = dir[x][y];
        if (c=='|')
            x--;
        else if (c=='-')
            y--;
        else
        {
            string t = "1";
            t[0] = a[x-1];
            tmp+=t;
            x--; y--;
        }
    }

    int len = tmp.size();
    cout << tmp << endl;
    if (len%2)
    {
        cout << tmp.substr(0,len/2+1);
        tmp = tmp.substr(0,len/2);
        reverse(tmp.begin(),tmp.end());
        cout << tmp << endl;
    }
    else
    {
        cout << tmp.substr(0,len/2);
        tmp = tmp.substr(0,len/2);
        reverse(tmp.begin(),tmp.end());
        cout << tmp << endl;
    }
}

int main()
{
    string str1, str2;
    while (cin >> str1)
    {
        str2 = str1;
        reverse(str2.begin(),str2.end());

        LPSubseq(str1,str2);
    }

    return 0;
}
