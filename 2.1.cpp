#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
    ull a, n;
    cin >> a >> n;
    int x = max((int)log2(n) + 1, 1);
    ull arr[x + 1];
    arr[0] = 1;
    arr[1] = a;
    for (int i = 2; i < x + 1; i++)
    {
        arr[i] = arr[i - 1] * arr[i - 1];
    }
    ull ans = 1;
    int count = 1;
    while (n != 0)
    {
        if (n % 2 != 0)
        {
            ans *= arr[count];
        }
        n /= 2;
        count++;
    }
    cout << ans << '\n';
}
