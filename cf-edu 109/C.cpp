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

void reverse(vi &a, ll l, ll r)
{

    while (l < r)
    {
        swap(a[l], a[r]);
        l++;
        r--;
    }
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
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, char>> e, o;
        map<ll, ll> h;
        ll a[n];
        rep(n)
        {
            ll x;
            cin >> x;
            a[i] = x;
            h[x] = i;
        }
        rep(n)
        {
            char c;
            cin >> c;
            if (a[i] % 2 == 0)
                e.pb(mp(a[i], c));
            else
                o.pb(mp(a[i], c));
        }

        ll ans[n] = {0};
        sort(all(e));
        sort(all(o));

        stack<ll> l, r;

        for (auto i : e)
        {
            char c = i.sc;
            ll x = i.fr;
            if (c == 'R')
            {
                r.push(x);
            }
            else
            {
                if (!r.empty())
                {
                    ll f = r.top();
                    r.pop();
                    ll co = (x - f) / 2;
                    ll in = h[f];
                    ans[in] = co;
                    ans[h[x]] = co;
                }
                else
                {
                    if (!l.empty())
                    {
                        ll f = l.top();
                        l.pop();
                        ll co = (f + x - 2) / 2;
                        ll in = h[f];
                        ans[in] = co;
                        ans[h[x]] = co;
                    }
                    else
                    {
                        l.push(x);
                    }
                }
            }
        }
        while (!r.empty())
        {
            ll x = r.top();
            r.pop();
            if (!r.empty())
            {
                ll f = r.top();
                r.pop();
                ll co = (m - x + m - f) / 2;
                ll in = h[f];
                ans[in] = co;
                ans[h[x]] = co;
            }
            else if (!l.empty())
            {

                ll f = l.top();
                l.pop();
                if ((f - 1) % 2 == (m - x) % 2)
                {
                    ll co = (m - x + f - 1 + m) / 2;
                    ll in = h[f];
                    ans[in] = co;
                    ans[h[x]] = co;
                }
            }
        }
    }

    return 0;
}