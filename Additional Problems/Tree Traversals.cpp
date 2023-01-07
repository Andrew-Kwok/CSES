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

int N;
int pre[MAX], in[MAX], inpos[MAX];

int lt[MAX], rt[MAX];
inline void dfs(int node)
{
	if (lt[node])
		dfs(lt[node]);
	if (rt[node])
		dfs(rt[node]);
	cout << node << " ";
}

void solve()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> pre[i];
	for (int i = 1; i <= N; ++i)
		cin >> in[i], inpos[in[i]] = i;

	int lst = -1;
	vector<int> sk;
	for (int i = 1, j = 1; i < N; ++i)
	{
		sk.pb(pre[i]);
		while (!sk.empty() && sk.back() == in[j])
			lst = sk.back(), sk.pop_back(), j++;

		if (!sk.empty() && sk.back() == pre[i])
			lt[pre[i]] = pre[i+1];
		else rt[lst] = pre[i+1];
	}

	dfs(pre[1]);
	cout << '\n';
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
