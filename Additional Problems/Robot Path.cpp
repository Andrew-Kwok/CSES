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
const int MAX = 1e5 + 69;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
const ll inf = 1e18 + 69;

// 'L': 0
// 'R': 1
// 'U': 2
// 'D': 3

int N;
ii Xcomp[MAX], Ycomp[MAX];
pl X[MAX], Y[MAX];
int dir[MAX];

int bit[2 * MAX];
inline void add(int x, int val)
{
	for (++x; x < 2*MAX; x += (x & -x))
		bit[x] += val;
}

inline int sum(int x)
{
	int res = 0;
	for (++x; x > 0; x -= (x & -x))
		res += bit[x];
	return res;
}

inline bool check(vector<array<int, 3>> hor, vector<array<int, 3>> ver)
{
	sort(hor.begin(), hor.end());
	sort(ver.begin(), ver.end());

	if (hor.size() >= 2)
	{
		for (int i = 1, prv = hor[0][2]; i < (int)hor.size(); ++i)
		{
			if (hor[i][0] == hor[i-1][0])
			{
				if (hor[i][1] <= prv)
					return true;
				prv = max(prv, hor[i][2]);
			}
			else prv = hor[i][2];
		}
	}

	if (ver.size() >= 2)
	{
		for (int i = 1, prv = ver[0][2]; i < (int)ver.size(); ++i)
		{
			if (ver[i][0] == ver[i-1][0])
			{
				if (ver[i][1] <= prv)
					return true;
				prv = max(prv, ver[i][2]);
			}
			else prv = ver[i][2];
		}
	}

	memset(bit, 0, sizeof(bit));
	sort(ver.begin(), ver.end(), [](const array<int, 3> &x, const array<int, 3> &y){
		return x[1] < y[1];
	});

	int id = 0;
	priority_queue<ii> pq;
	for (auto &[y, x1, x2] : hor)
	{
		while (id < (int)ver.size() && y >= ver[id][1])
			add(ver[id][0], 1), pq.push({-ver[id][2], ver[id][0]}), id++;
		while (!pq.empty() && y > -pq.top().f1)
			add(pq.top().s2, -1), pq.pop();

		if (sum(x2) - sum(x1 - 1))
			return true;
	}

	return false;
}

inline pl isect(int i, int j)
{
	bool ihor = false, jhor = false;
	array<ll, 3> a, b;

	if (dir[i] <= 1) { ihor = true; a = {Y[i].f1, X[i].f1, X[i].s2}; }
	else a = {X[i].f1, Y[i].f1, Y[i].s2};
	if (dir[j] <= 1) { jhor = true; b = {Y[j].f1, X[j].f1, X[j].s2}; }
	else b = {X[j].f1, Y[j].f1, Y[j].s2};

	if (ihor == jhor)
	{
		if (a[0] != b[0] || a[1] > b[2] || a[2] < b[1])
			return {inf, inf};

		vector<ll> tmp = { a[1], a[2], b[1], b[2] };
		sort(tmp.begin(), tmp.end());

		ll x = a[0], y = inf;
		if (dir[j] == 1 || dir[j] == 2) //pick the minimum
			y = tmp[1];
		else y = tmp[2];

		if (jhor) swap(x, y);
		return {x, y};
	}
	else
	{
		if (b[1] <= a[0] && a[0] <= b[2] && a[1] <= b[0] && b[0] <= a[2])
		{
			if (ihor) 
				return {b[0], a[0]};
			return {a[0], b[0]};
		}
		return {inf, inf};
	}
}

void solve()
{
	cin >> N;

	for (ll x = 0, y = 0, i = 0; i < N; ++i)
	{
		char c; int len;
		cin >> c >> len;

		if (c == 'L') dir[i] = 0;
		else if (c == 'R') dir[i] = 1;
		else if (c == 'U') dir[i] = 2;
		else dir[i] = 3;

		if (i)
		{
			X[i].f1 = x + dx[dir[i]];
			Y[i].f1 = y + dy[dir[i]];
		}

		X[i].s2 = x + dx[dir[i]] * len;
		Y[i].s2 = y + dy[dir[i]] * len;

		x = X[i].s2; y = Y[i].s2;

		if (X[i].f1 > X[i].s2) swap(X[i].f1, X[i].s2);
		if (Y[i].f1 > Y[i].s2) swap(Y[i].f1, Y[i].s2);
	}

	{
		vector<ll> xcor, ycor;
		for (int i = 0; i < N; ++i)
		{
			xcor.pb(X[i].f1), xcor.pb(X[i].s2);
			ycor.pb(Y[i].f1), ycor.pb(Y[i].s2);
		}

		sort(xcor.begin(), xcor.end());
		sort(ycor.begin(), ycor.end());
		xcor.resize(unique(xcor.begin(), xcor.end()) - xcor.begin());
		ycor.resize(unique(ycor.begin(), ycor.end()) - ycor.begin());

		for (int i = 0; i < N; ++i)
		{
			Xcomp[i].f1 = (int)(lower_bound(xcor.begin(), xcor.end(), X[i].f1) - xcor.begin());
			Xcomp[i].s2 = (int)(lower_bound(xcor.begin(), xcor.end(), X[i].s2) - xcor.begin());
			Ycomp[i].f1 = (int)(lower_bound(ycor.begin(), ycor.end(), Y[i].f1) - ycor.begin());
			Ycomp[i].s2 = (int)(lower_bound(ycor.begin(), ycor.end(), Y[i].s2) - ycor.begin());
		}
	}


	int l = 1, r = N+1;
	while (l < r)
	{
		int mid = (l + r) >> 1;

		vector<array<int, 3>> hor, ver;
		for (int i = 0; i < mid; ++i)
		{
			if (dir[i] > 1) ver.pb({Xcomp[i].f1, Ycomp[i].f1, Ycomp[i].s2});
			else hor.pb({Ycomp[i].f1, Xcomp[i].f1, Xcomp[i].s2});	
		}

		if (check(hor, ver)) r = mid;
		else l = mid + 1;
	}

	ll res = -1;
	for (int i = 0; i < l-1; ++i)
		res += abs(X[i].f1 - X[i].s2) + abs(Y[i].f1 - Y[i].s2) + 1;

	if (l != N+1)
	{
		if (dir[l-1] != dir[l-2] && ((dir[l-1] <= 1 && dir[l-2] <= 1) || (dir[l-1] > 1 && dir[l-2] > 1)))
		{
			cout << res << '\n';
			return;
		}

		pl best = {inf, inf};
		if (dir[l-1] <= 1)
			best.s2 = X[l-1].s2;
		else best.f1 = X[l-1].f1;

		for (int i = 0; i < l-1; ++i)
		{
			pl pts = isect(i, l-1);
			if (pts.f1 == inf || pts.s2 == inf)
				continue;

			if (best.f1 == inf || best.s2 == inf)
				best = pts;

			if (dir[l-1] == 1 || dir[l-1] == 2)
				best = min(best, pts);
			else best = max(best, pts);


		}

		if (dir[l-1] == 1 || dir[l-1] == 2)
			res += abs(X[l-1].f1 - best.f1) + abs(Y[l-1].f1 - best.s2) + 1;
		else res += abs(X[l-1].s2 - best.f1) + abs(Y[l-1].s2 - best.s2 + 1);
	}

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
