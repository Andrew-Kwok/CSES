#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Line {
    ll m, c;
    Line(ll _m = 0, ll _c = 0) : m(_m), c(_c) {}

    ll operator()(ll x) {
        return m * x + c;
    }

	bool operator<(const Line& o) const { return m < o.m; }
};

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	ll C = 0;
	vector<Line> v; v.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int y1, y2; cin >> y1 >> y2;
		int m = (y2 - y1) / M;
		if (m == 0) C = max(C, (ll)y1);
		else v.emplace_back(m, y1);
	}

	sort(v.begin(), v.end());

	{
		vector<Line> sk;
		for (auto l : v)
		{
			while (sk.size() >= 2)
			{
				auto& a = sk[(int)sk.size() - 2];
				auto& b = sk[(int)sk.size() - 1];

				if ((a.c - b.c) * (l.m - b.m) < (b.c - l.c) * (b.m - a.m))
					break;
				else sk.pop_back();
			}
			sk.emplace_back(l);
		}
		v = sk;
	}

	for (int x = 0, i = 0; x <= M; ++x)
	{
		while (i+1 < N && v[i](x) <= v[i+1](x))
			++i;
		cout << max(C, v[i](x)) << " \n"[x == M];
	}

	return 0;
}