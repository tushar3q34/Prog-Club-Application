#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[200005][64];
int set_bit(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n % 2 != 0)
            count++;
        n /= 2;
    }
    return count;
}
long long solve(int arr[], int n, int andsum, int k)
{
    if (n == 0)
    {
        if (set_bit(andsum) == k)
            return dp[n][andsum] = 1;
        else
            return dp[n][andsum] = 0;
    }
    else
    {
        if (dp[n][andsum] != -1)
            return dp[n][andsum];
        else
        {
            dp[n][andsum] = solve(arr, n - 1, andsum, k) % MOD + solve(arr, n - 1, andsum & arr[n - 1], k) % MOD;
            dp[n][andsum] %= MOD;
            return dp[n][andsum];
        }
    }
}
int main()
{
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i <= n + 2; i++)
        {
            for (int j = 0; j <= 63; j++)
            {
                dp[i][j] = -1;
            }
        }
        if (k != 6)
            cout << solve(arr, n, 63, k) << '\n';
        else
            cout << solve(arr, n, 63, k) - 1 << '\n';
    }
}
