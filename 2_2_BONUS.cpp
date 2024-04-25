#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x = max((int)log2(n) + 1, 1);
    long long values[x + 1][2][2];
    values[0][0][0] = 1;
    values[0][0][1] = 1;
    values[0][1][0] = 1;
    values[0][1][1] = 0;
    for (int i = 1; i < x + 1; i++)
    {
        values[i][0][0] = values[i - 1][0][0] * values[i - 1][0][0] + values[i - 1][0][1] * values[i - 1][1][0];
        values[i][0][1] = values[i - 1][0][0] * values[i - 1][0][1] + values[i - 1][0][1] * values[i - 1][1][1];
        values[i][1][0] = values[i - 1][0][0] * values[i - 1][1][0] + values[i - 1][1][0] * values[i - 1][1][1];
        values[i][1][1] = values[i - 1][1][0] * values[i - 1][0][1] + values[i - 1][1][1] * values[i - 1][1][1];
    }
    // values[i] -> Matrix ^ 2 ^ i
    if (n >= 2)
    {
        long long arr[2][2];
        arr[0][0] = 1;
        arr[0][1] = 0;
        arr[1][0] = 0;
        arr[1][1] = 1;
        int i = 0;
        n--;
        while (n != 0)
        {
            if (n % 2 != 0)
            {
                long long val1 = arr[0][0];
                long long val2 = arr[0][1];
                long long val3 = arr[1][0];
                long long val4 = arr[1][1];
                arr[0][0] = val1 * values[i][0][0] + val2 * values[i][1][0];
                arr[0][1] = val1 * values[i][0][1] + val2 * values[i][1][1];
                arr[1][0] = val3 * values[i][0][0] + val4 * values[i][1][0];
                arr[1][1] = val3 * values[i][0][1] + val4 * values[i][1][1];
            }
            n /= 2;
            i++;
        }
        cout << arr[0][0] << '\n';
    }
    else if (n == 0)
        cout << 0 << '\n';
    else if (n == 1)
        cout << 1 << '\n';
}
