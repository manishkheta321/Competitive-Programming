#include <bits/stdc++.h>

using namespace std;

/************************Pre processors & typedefs************************/

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()

//loop
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
//for selecting all of a vector or something
#define all(v) v.begin(), v.end()

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))

//all array
#define alla(a, n) a, a + n

//ignore extra line while taking input
#define clrbuf cin.ignore(numeric_limits<streamsize>::max(), '\n');

//precision
#define preciset(x) cout << setprecision(x) << fixed;

// datatypes
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define FastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
/*********************DEBUGGG*******************************************/
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
    std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}
const ll INF = 0xFFFFFFFFFFFFFFFL;

/**********************CHECK RUN TIME*********************************/
clock_t time_p = clock();
void timedekhlo()
{
    time_p = clock() - time_p;
    cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
ll seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());

inline ll rnd(ll l = 0, ll r = INF) { return uniform_int_distribution<ll>(l, r)(rng); }

/*************************CONSTANTS***************************************/

const int mod = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

/*********************USER DEFINED FUNCTIONS****************************/
//Modulo power
ll modpow(ll x, ll y, ll m)
{
    ll res = 1;
    x = x % m;
    while (y > 0)
    {
        if (y & 1)
            res = ((res % m) * (x % m)) % m;
        y = y >> 1;
        x = ((x % m) * (x % m)) % m;
    }
    return res % m;
}

// modulo inverse
ll modinv(ll x, ll m)
{
    return modpow(x, m - 2, m);
}

//GCD
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

/****************MAIN*****************************************************/

ll cal(ll a, ll b, char c)
{
    if (c == '*')
    {
        return a * b;
    }
    else if (c == '-')
    {
        return a - b;
    }
    return a + b;
}
ii minmax1(vector<vector<ll>> Ma, vector<vector<ll>> Mi, vector<char> op, ll i, ll j)
{
    ll mi, ma;
    mi = LONG_MAX;
    ma = LONG_MIN;
    for (ll k = i; k <= j - 1; k++)
    {
        ll a = cal(Ma[i][k], Mi[k + 1][j], op[k]);
        ll b = cal(Ma[i][k], Ma[k + 1][j], op[k]);
        ll c = cal(Mi[i][k], Mi[k + 1][j], op[k]);
        ll d = cal(Mi[i][k], Ma[k + 1][j], op[k]);
        // db(a,b,c,d);
        ma = max(ma, max(a, max(b, max(c, d))));
        mi = min(mi, min(a, min(b, min(c, d))));
    }
    return mp(mi, ma);
}

signed main()
{
    FastIO
        ll t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    t = 1;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        unordered_map<ll, vi> s;
        ll sum = 0;
        rep(n) cin >> a[i];
        rep(n)
        {
            ll x;
            cin >> x;
            s[a[i]].pb(x);
            sum += x;
        }
        for (auto i : s)
        {
            vi v = i.sc;
            sort(all(v), greater<ll>());
            s[i.fr] = v;
        }
        for (auto i : s)
        {
            if (i.sc.size() >= 2)
                for (ll j = i.sc.size() - 2; j >= 0; j--)
                {
                    s[i.fr][j] += s[i.fr][j + 1];
                }
        }

        ll dp[n + 1];
        rep(n + 1) dp[i] = 0;
        for (auto i : s)
        {

            vi v = i.sc;
            ll siz = v.size();
            for (ll j = 1; j <= i.sc.size(); j++)
            {
                ll index = siz - siz % j;
                ll val = v[index];
                if (siz % j == 0)
                    dp[j] += v[0];
                else
                    dp[j] += v[0] - val;
            }
        }

        for (ll i = 1; i <= n; i++)
            cout << dp[i] << " ";
        cout << endl;
    }

    return 0;
}