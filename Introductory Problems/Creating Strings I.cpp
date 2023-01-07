#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int main()
{
	fastio;

	string s;
	cin >> s;

	sort(s.begin(), s.end());

	vector<string> res;
	do
	{
		res.pb(s);
	} while(next_permutation(s.begin(), s.end()));

	cout << res.size() << '\n';
	for (auto s : res)
		cout << s << '\n';

	return 0;
}
