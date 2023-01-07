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
const ll inf = 1e18 + 69;

struct Big
{
	ll val;
	Big(ll _val = 0) : val(_val) { val = min(val, inf); }

	Big& operator+= (const Big &rhs) { val = min(inf, val + rhs.val); return *this; }
	Big& operator-= (const Big &rhs) { val = max(-inf, val - rhs.val); return *this; }
	Big& operator*= (const Big &rhs) { 
		__int128_t tmp = (__int128_t)val * rhs.val;
		if (tmp < -inf) val = -inf;
		else if (tmp > inf) val = inf;
		else val = (ll) tmp;
		return *this;
	}

	friend Big operator+ (Big a, const Big &b) { return a += b; }
    friend Big operator- (Big a, const Big &b) { return a -= b; }
    friend Big operator- (Big a) { return 0 - a; }
    friend Big operator* (Big a, const Big &b) { return a *= b; }
    friend ostream& operator<< (ostream &os, const Big &a) { return os << a.val; }
    friend bool operator== (const Big &a, const Big &b) { return a.val == b.val; }
    friend bool operator!= (const Big &a, const Big &b) { return a.val != b.val; }

};

Big pwr[20]; // power of 10
void solve()
{
	pwr[0] = 1;
	for (int i = 1; i < 20; ++i)
		pwr[i] = 10 * pwr[i-1];

	const auto getone = [&](ll val) -> Big
	{
		string s = to_string(val);
		Big res = 0, ctr = 0;
		for (int i = 0, sz = (int)s.size(); i < sz; ++i)
		{
			if (s[i] == '0') continue;
			else
			{
				// contribution of '1' from the prefix [0, i)
				res += ctr * ((s[i] - '0') * pwr[sz - i - 1]);

				// contribution of '1' from index [i]
				if (s[i] > '1')
					res += pwr[sz - i - 1];

				// contribution of '1' from the suffix [i, sz)
				if (i + 1 < sz)	
				{
					res += (s[i] - '0') * (sz - i - 1) * (pwr[sz - i - 2]);
				}

				ctr += s[i] == '1';
			}
		}
		return res + ctr;
	};
	
	ll N; cin >> N;

	ll l = 0, r = 1e18;
	while (l < r)
	{
		ll mid = (l + r + 1) >> 1;
		if (getone(mid).val <= N) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
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
