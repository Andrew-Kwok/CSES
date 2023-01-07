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

int const N = 1e6 + 7;

int len;
char s[N];
int main()
{
	fastio;

	cin >> s;
	len = strlen(s);

	int ctr = 0;
	int res = 0;
	for (int i = 0; i < len; ++i)
	{
		ctr++;
		if (i+1 == len || s[i] != s[i+1])
		{
			res = max(res, ctr);
			ctr = 0;
		}
	}
	cout << res << '\n';

	return 0;
}
