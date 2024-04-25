#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<long long> change(n);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        long long x;
        cin >> x;
        change[l] += x;
        if (r < n)
            change[r] -= x;
    }
    for (int i = 1; i < n; i++)
    {
        change[i] += change[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] += change[i];
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
