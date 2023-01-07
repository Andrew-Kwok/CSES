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

/*
 * https://oeis.org/A036685
 */

const int lose[] = { 1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346, 359, 362, 365, 386, 389, 392, 566, 630, 633, 636, 639, 673, 676, 682, 685, 923, 926, 929, 932, 1222 };

int main()
{
	fastio

	set<int> st;
	for (int x : lose)
		st.insert(x);

	int t;
	cin >> t;
	
	while (t--)
	{
		int n;
		cin >> n;

		if (st.count(n)) cout << "second\n";
		else cout << "first\n";
	}

	return 0;
}
