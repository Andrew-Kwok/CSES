#include <iostream>
#include <vector>
#include <cstring>
#include <array>
#include <algorithm>
using namespace std;

#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
 
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define f1 first
#define s2 second
 
constexpr int MAX = 1e6 + 69;
 
int len;
char s[2 * MAX];
// int Rank[MAX];
 
 	
//  int best = -1;
//  vector<array<int, 3>> v;
// 	for (int jump = 1; jump < len; jump <<= 1)
// 	{
// 		v.clear();
// 		for (int i = 0; i < len; ++i)
// 			v.pb({Rank[i], Rank[(i + jump) % len], i});
// 		counting_sort(v);
 	
//  		best = v[0][2];
// 		for (int i = 0, ctr = 1; i < len; ++i)
// 		{
// 			if (i) ctr += (v[i][0] != v[i-1][0] || v[i][1] != v[i-1][1]);
// 			Rank[v[i][2]] = ctr;
// 		}
// 	}
//   	return best;
// }

inline int booth_algo()
{
	for (int i = 0; i < len; ++i)
		s[i+len] = s[i];
	len = len + len;

	int best = 0;
	vector<int> f(len, -1);

	for (int j = 1; j < len; ++j)
	{
		int i = f[j - best - 1];
		while (i != -1 && s[j] != s[best + i + 1])
		{
			if (s[j] < s[best + i + 1])
				best = j - i - 1;
			i = f[i];
		}

		if (s[j] != s[best + i + 1])
		{
			if (s[j] < s[best])
				best = j;
			f[j - best] = -1;
		}
		else f[j - best] = i+1;
	}

	return best;
}
 
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin >> s;
	len = (int) strlen(s);
 
	int idx = booth_algo();
	for (int i = 0; i < len/2; ++i)
		cout << s[i + idx];
	cout << '\n';
 
	return 0;
}
