#include <bits/stdc++.h>
using namespace std;

#define f1 first
#define s2 second
#define pb push_back

using ii = pair<int, int>;


const int MAX = 1 << 17;

int N, Q;
int H[MAX], up[MAX][17];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
		cin >> H[i];

	vector<ii> v; v.reserve(N);
	for (int i = 1; i <= N; ++i) {
		v.pb(make_pair(H[i], -i));
	}
	
	sort(v.rbegin(), v.rend());

	set<int> st;
	for (auto [h, i] : v)
	{
		i = -i;
		auto it = st.lower_bound(i);

		if (it == st.end()) up[i][0] = N+1;
		else up[i][0] = *it;
		st.insert(i);
	}
	up[N+1][0] = N+1;

	for (int j = 1; j < 17; ++j)
	{
		for (int i = 1; i <= N+1; ++i)
			up[i][j] = up[up[i][j-1]][j-1];
	}

	for (; Q--;)
	{
		int a, b; cin >> a >> b;

		int Z = 1;
		for (int j = 16; j >= 0; --j)
		{
			if (up[a][j] <= b) {
				Z += 1 << j, a = up[a][j];
			}
		}
		cout << Z << '\n';
	}


	return 0;
}