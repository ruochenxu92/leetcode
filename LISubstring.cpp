#include <iostream>
using namespace std;

int LISubstring(int arr[], int len)
{
    int ans = 1;

    int start = 0;
    while (start<len)
    {
        int i = start;
        int j = start+1;
        if (j==len)
            break;

        while (arr[i]<=arr[j])
        {
            i++;
            j++;
            ans = max(ans,i-start+1);
            if (j==len)
                break;
        }

        start = j;
    }

    return ans;
}

int main()
{
    int len;
    cin >> len;

    int arr[len];
    for (int i=0;i<len;i++)
        cin >> arr[i];

    int ans = LISubstring(arr,len);
    cout << ans << endl;

    return 0;
}
