#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAX = 1 << 18;

int N, K;
int ar[MAX];

int main() 
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> ar[i];

	set<ii, greater<ii>> st;
	map<int, int> memo;
	for (int i = 0; i < K; ++i)
		memo[ar[i]]++;
	for (auto [x, fq] : memo) 
		st.insert({fq, -x});

	cout << -st.begin()->second;
	for (int i = K; i < N; ++i)
	{
		if (memo.count(ar[i])) {
			st.erase({memo[ar[i]], -ar[i]});
		}
		memo[ar[i]]++;
		st.insert({memo[ar[i]], -ar[i]});

		st.erase({memo[ar[i-K]], -ar[i-K]});
		memo[ar[i-K]]--;
		if (memo[ar[i-K]] > 0) st.insert({{memo[ar[i-K]], -ar[i-K]}});
		else memo.erase(ar[i-K]);

		cout << " " << -st.begin()->second;
	}

	return 0;
}