#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second
 
#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << "[" << #x << "]: " << x << "\n";
 
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;
 
const ld PI = 4*atan((ld)1);
const int MAX = 2e5 + 69;
const ll inf = 1e18 + 69;
 
struct fenwick
{
    int bit[MAX] = {};
    inline void reset() { memset(bit, 0, sizeof(bit)); }
    inline void add(int x, int val)
    {
        for (int i = x+1; i < MAX; i += (i & -i))
            bit[i] += val;
    }
 
    inline int sum(int x)
    {
        int res = 0;
        for (int i = x+1; i > 0; i -= (i & -i))
            res += bit[i];
        return res;
    }
} bit;
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> v(n);
    for (int &x : v)
        cin >> x;
 
    {
        vector<int> comp = v;
        sort(comp.begin(), comp.end());
        comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
 
        for (int &x : v)
            x = (int)(lower_bound(comp.begin(), comp.end(), x) - comp.begin());
    }
 
    vector<int> pfx, sfx;
    {
        int ctr = 0;
        bit.reset();
        for (int x : v)
        {
            pfx.pb(ctr++ - bit.sum(x));
            bit.add(x, 1);
        }
    }
 
    {
        int ctr = 0;
        bit.reset();
        reverse(v.begin(), v.end());
        for (int x : v)
        {
            sfx.pb(ctr++ - bit.sum(x));
            bit.add(x, 1);
        }
        reverse(sfx.begin(), sfx.end());
    }
 
    ll res = 0;
    for (int i = 0; i < n; ++i)
        res += min(pfx[i], sfx[i]);
 
    cout << res << '\n';
}
 
int main()
{
    fastio;
 
    int TC = 1;
    //cin >> TC;
 
    while (TC--)
        solve();
 
    return 0;
}
