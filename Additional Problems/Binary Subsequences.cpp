#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << "[" << #x << "]: " << x << "\n";

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

const ld PI = 4*atan((ld)1);
const int inf = 1e9 + 69;

// https://oeis.org/A293722

void solve()
{
	// auto start = high_resolution_clock::now();

	int N; cin >> N; N++;

	int sz = 0; string cur = "";
	int bound = (int)log2(N);

	const auto rc = [&](const auto &self, int val, int a, int b) -> int
	{
		if (val > N)
			return sz;
		if (sz > bound)
			return inf;

		if (val == N)
		{
			cout << cur << '\n';

			// auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
			// cerr << "runtime: " << duration.count() << "milliseconds\n";

			exit(0);
		}

		bool lst = cur.back() == '1';
		vector<int> prv = {a, b};

		int res = inf;
		int L = -1; // lower bound of value, achieved after inserting same character
		int R = -1; // upper bound of value, achieved after inserting alternating characters

		{
			int len = sz; int val_ = val; vector<int> prv_ = {a, b};
			for (int x = !lst; val_ < N; x = !x, len++)
			{
				int tmp = val_;
				val_ = 2 * val_ - prv_[x];
				prv_[x] = tmp;
			}
			res = min(res, len);
		}
		{
			L = val; vector<int> prv_ = prv;
			for (int i = 0; i < bound - sz; ++i)
			{
				int tmp = L;
				L = 2 * L - prv_[lst];
				prv_[lst] = tmp;
			}
		}
		{
			R = val; vector<int> prv_ = prv;
			for (int i = 0, x = !lst; i < bound - sz; ++i, x = !x)
			{
				int tmp = R;
				R = 2 * R - prv_[x];
				prv_[x] = tmp;
			}
		}

		if (L <= N && N <= R)
		{ 
			vector<int> tmp = prv; tmp[!lst] = val;
			sz++; cur += (char)('0' + !lst);
			res = min(res, self(self, 2*val - prv[!lst], tmp[0], tmp[1]));
	 		sz--; cur.pop_back();

			tmp = prv; tmp[lst] = val;
			sz++; cur += (char)('0' + lst);
			res = min(res, self(self, 2*val - prv[lst], tmp[0], tmp[1]));
			sz--; cur.pop_back();
		}
		return res;
	};

	for (;;)
	{
		// debug(bound);
		sz = 1; cur = "1";
		if (700000 <= N && N <= 800000)
			bound = 30;

		bound = max(bound + 1, rc(rc, 2, 0, 1));
	}
}

int main()
{
	fastio;

	int TC = 1;
	//cin >> t;

	while (TC--)
		solve();

	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
 
// constexpr int inf = 0x3f3f3f3f;
 
// int check(int a, int b) {
//     // a < b always
//     if(b == 0) return 0;
//     if(a == b) return inf;
//     return check(b % (a+1), a) + b / (a+1);
// }
 
// void build(int a, int b, int d = 0) {
//     if(a > b)
//         swap(a, b), d ^= 1;
//     if(b == 0)
//         return;
//     printf("%d", d);
//     build(a, b-a-1, d);
// }
 
// int main() {
//     int n; scanf("%d", &n);
//     pair<int,int> ans = {inf, inf};
//     for(int i = 0; i < n-i; i++)
//         ans = min(ans, {check(i, n-i), i});
//     build(ans.second, n-ans.second);
//     puts("");
// }
