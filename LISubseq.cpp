#include <iostream>
#include <cstring>
using namespace std;

// [i,j]区间，LIS有多长
// 用pre数组回溯，见http://blog.csdn.net/joylnwang/article/details/6766317
int LISubseq(int arr[],int n)
{
    int dp[n];
    fill(dp,dp+n,1);
    int ans = 1;

    for (int i=0;i<n;i++)
        for (int j=0;j<i;j++)
        {
            if (arr[j]<arr[i])
            {
                dp[i] = dp[i]<=dp[j]+1 ?dp[j]+1 :dp[i];
                ans = max(ans,dp[i]);
            }
        }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++)
        cin >> arr[i];
    cout << LISubseq(arr,n) << endl;

    return 0;
}
