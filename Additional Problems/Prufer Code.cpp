#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

ld const PI = 4*atan((ld)1);
int const MAX = 2e5 + 7;

int indegree[MAX];
int ar[MAX];
int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n-2; ++i)
	{
		cin >> ar[i];
		indegree[ar[i]]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq; 
	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i] == 0)
			pq.push(i);
	}

	for (int i = 0; i < n-2; ++i)
	{
		cout << pq.top() << " " << ar[i] << '\n';
		pq.pop();

		indegree[ar[i]]--;
		if (indegree[ar[i]] == 0)
			pq.push(ar[i]);
	}

	cout << pq.top() << " " << n << '\n';
	return 0;
}
