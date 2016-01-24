string longestPalindrome(string s)
{
    int n = s.size();
    string ans;
    if (!n) return ans;
        
    int maxLen = 1;
    int start = 0;
    bool dp[n][n];
    memset(dp,0,sizeof(dp));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j <= n-1; j++)
        {
            if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))    // 看似会越界，实际上有j-i<2的短路求值保证
            {
                dp[i][j] = 1;
                if (j-i+1>maxLen)
                {
                    start = i;
                    maxLen = j-i+1;
                }
            }
        }
    }

    ans = s.substr(start,maxLen);
    return ans;
}