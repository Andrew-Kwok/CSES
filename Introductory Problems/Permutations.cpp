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

	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 1 << '\n';
		return 0;	
	}

	if (n == 2 || n == 3)
	{
		cout << "NO SOLUTION\n";
		return 0;
	}

	cout << 2;
	for (int i = 4; i <= n; i += 2)
		cout << " " << i;
	for (int i = 1; i <= n; i += 2)
		cout << " " << i;
	cout << '\n';

	return 0;
}
