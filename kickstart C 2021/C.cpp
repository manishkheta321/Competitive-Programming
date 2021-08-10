#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[1005][1005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;

    ll k = 0, val = 1;
    while (k < 1005)
    {
        ll i = 0, j = k;
        while (i < 1005 && j >= 0)
        {
            dp[i][j] = val;
            val++;
            i++;
            j--;
        }
        k++;
    }

    for (int i = 0; i < 1005; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    while (t--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;

        ll sum = 0;
        for (ll i = x1; i <= x2; i++)
            sum += dp[i][y1];

        for (ll j = y1 + 1; j <= y2; j++)
            sum += dp[x2][j];

        cout << dp[999][999] << endl;
        cout << sum << endl;
    }
}