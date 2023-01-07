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

void solve()
{
	int a, b, n;
	cin >> a >> b >> n;

	vector<ii> v(n);
	for (auto &[A, B] : v)
		cin >> A >> B;

	ll sumA = 0, sumB = 0;
	multiset<int> pickedA, pendA;
	priority_queue<int, vector<int>, greater<int>> pickedB;

	// pick all A
	sort(v.begin(), v.end(), greater<ii>());
	for (int i = 0; i < a; ++i)
		pickedA.insert(v[i].f1), sumA += v[i].f1;
	for (int i = a; i < n; ++i)
		pendA.insert(v[i].f1);

	// sort by largest B-A
	sort(v.begin(), v.end(), [](const ii &x, const ii &y){
		return x.s2 - x.f1 > y.s2 - y.f1;
	});

	for (int i = 0; i < b; ++i)
	{
		if (pendA.count(v[i].f1))
			pendA.erase(pendA.lower_bound(v[i].f1));

		else
		{
			assert(pickedA.count(v[i].f1));
			pickedA.erase(pickedA.lower_bound(v[i].f1)); sumA -= v[i].f1;
			
			auto it = prev(pendA.end());
			pickedA.insert(*it);  sumA += *it;
			pendA.erase(it);
		}
		pickedB.push(v[i].s2);
		sumB += v[i].s2;
	}

	ll res = sumA + sumB;
	for (int i = b; i < n-a; ++i)
	{
		if (pendA.count(v[i].f1))
			pendA.erase(pendA.lower_bound(v[i].f1));

		else
		{
			assert(pickedA.count(v[i].f1));
			pickedA.erase(pickedA.lower_bound(v[i].f1)); sumA -= v[i].f1;
			
			auto it = prev(pendA.end());
			pickedA.insert(*it);  sumA += *it;
			pendA.erase(it);
		}
		pickedB.push(v[i].s2);
		sumB += v[i].s2;

		sumB -= pickedB.top();
		pickedB.pop();

		res = max(res, sumA + sumB);
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
