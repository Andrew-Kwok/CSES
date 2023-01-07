#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define f1 first
#define s2 second

constexpr int MAX = 1e5 + 69;

int len;
char s[MAX];
int suffix_array[MAX];

vector<array<int, 3>> fq[MAX];
inline void counting_sort(vector<array<int, 3>> &v)
{
	int sz = (int)v.size();
 
	for (int j = 1; j >= 0; --j)
	{
		int mx = 0;
		for (int i = 0; i < sz; ++i)
		{
			fq[v[i][j]].pb(v[i]);
			mx = max(mx, v[i][j]);
		}
		v.clear();
 
		for (int i = 1; i <= mx; ++i)
		{
			for (auto x : fq[i])
				v.pb(x);
			fq[i].clear();
		}
	}
}

void build_suffix_array()
{
	vector<int> ranks(len);
	{
		ranks[len-1] = 1;

		int C[26] = {};
		for (int i = 0; i < len-1; ++i)
			C[s[i] - 'a'] = 1;
		for (int i = 1; i < 26; ++i)
			C[i] += C[i-1];
		for (int i = 0; i < len-1; ++i)
			ranks[i] = 1 + C[s[i] - 'a'];
	}

	vector<array<int, 3>> v(len);
	for (int jump = 1; jump < len; jump <<= 1)
	{
		for (int i = 0; i < len; ++i)
			v[i] = {ranks[i], i + jump < len ? ranks[i + jump] : 0, i};
		counting_sort(v);

		for (int i = 0, ctr = 1; i < len; ++i)
		{
			if (i) ctr += mp(v[i][0], v[i][1]) != mp(v[i-1][0], v[i-1][1]);
			ranks[v[i][2]] = ctr;
		}
	}

	vector<ii> tmp;
	for (int i = 0; i < len; ++i)
		tmp.pb({ranks[i], i});
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < len; ++i)
		suffix_array[i] = tmp[i].s2;
}

int lcp[MAX] = {};
void kasai()
{
	int invSuff[MAX];
	for (int i = 0; i < len; ++i)
		invSuff[suffix_array[i]] = i;

	for (int i = 0, k = 0; i < len; ++i)
	{
		if (invSuff[i] == len-1)
		{
			k = 0;
			continue;
		}

		int j = suffix_array[invSuff[i] + 1];

		while (i+k < len && j+k < len && s[i+k] == s[j+k])
			k++;

		lcp[invSuff[i]] = k;
		if (k > 0)
			k--;
	}
}

ll st[4*MAX] = {}, lazy[4*MAX] = {};
bool ty[4*MAX] = {}; //true: set, false: add

void propagate(int node, int l, int r)
{
	if (ty[node])
	{
		st[node] = (r - l + 1) * lazy[node];
		if (l < r)
		{
			lazy[node << 1] = lazy[node << 1 | 1] = lazy[node];
			ty[node << 1] = ty[node << 1 | 1] = true;
		}
		lazy[node] = ty[node] = 0;
		return;
	}

	if (lazy[node])
	{
		st[node] += (r - l + 1) * lazy[node];
		if (l < r)
		{
			lazy[node << 1] += lazy[node];
			lazy[node << 1 | 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void add(int p, int q, ll val, int node = 1, int l = 1, int r = len)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return;

	if (p <= l && r <= q)
	{
		st[node] += (r - l + 1) * val;
		if (l < r)
		{
			lazy[node << 1] += val;
			lazy[node << 1 | 1] += val;
		}
		return;
	}

	int mid = (l + r) >> 1;
	add(p, q, val, node << 1, l, mid);
	add(p, q, val, node << 1 | 1, mid+1, r);

	st[node] = st[node << 1] + st[node << 1 | 1];
}

void modify(int p, int q, ll val, int node = 1, int l = 1, int r = len)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return;
	
	if (p <= l && r <= q)
	{
		st[node] = (r - l + 1) * val;
		if (l < r)
		{
			lazy[node << 1] = lazy[node << 1 | 1] = val;
			ty[node << 1] = ty[node << 1 | 1] = true;
		}
		return;
	}

	int mid = (l + r) >> 1;
	modify(p, q, val, node << 1, l, mid);
	modify(p, q, val, node << 1 | 1, mid+1, r);

	st[node] = st[node << 1] + st[node << 1 | 1];
}


ll sum(int p, int q, int node = 1, int l = 1, int r = len)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return 0;
	if (p <= l && r <= q)
		return st[node];

	int mid = (l + r) >> 1;
	return sum(p, q, node << 1, l, mid) + sum(p, q, node << 1 | 1, mid+1, r);
}


int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll k;
	cin >> s >> k;

	len = (int)strlen(s);
	s[len++] = '$';
	k = 1ll * len * (len - 1) / 2 - k + 1;

	build_suffix_array();
	kasai();

	for (int i = len-1; i >= 1; --i)
	{
		// new distinct substring with length [(lcp[i-1] + 1) .. (len-1 - suffix_array[i])]
		int p = lcp[i-1] + 1;
		int q = len - 1 - suffix_array[i];

		add(1, q, 1);
		if (p > q)
			continue;

		if (k > sum(p, q))
		{
			k -= sum(p, q);
			modify(p, q, 0);
		}
		else
		{
			int l = p, r = q;
			while (l < r)
			{
				int mid = (l + r + 1) >> 1;
				if (sum(mid, q) >= k) l = mid;
				else r = mid - 1;
			}

			for (int j = 0; j < l; ++j)
				cout << s[suffix_array[i] + j];
			cout << '\n';

			break;
		}
	}


	return 0;
}