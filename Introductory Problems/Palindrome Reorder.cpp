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
int const N =  1e6 + 7;

int fq[26] = {};
int len;
char s[N];

int main()
{
	fastio;

	cin >> s;
	len = strlen(s);

	for (int i = 0; i < len; ++i)
		fq[s[i] - 'A']++;

	int odd = 0;
	for (int i = 0; i < 26; ++i)
		odd += (fq[i] & 1);

	if (odd > 1 || (odd == 1 && len % 2 == 0))
	{
		cout << "NO SOLUTION\n";
		return 0;
	}

	string res;
	res.resize(len);


	if (odd)
	{
		for (int i = 0; i < 26; ++i)
			if (fq[i] & 1)
		{
			res[len/2] = (char) ('A' + i);
			fq[i]--;
			break;
		}
	}

	for (int i = 0, j = 0; i < len/2; ++i)
	{
		while (fq[j] == 0) ++j;
		res[i] = res[len-i-1] = (char) ('A' + j);
		fq[j] -= 2;	
	}

	cout << res << '\n';
	return 0;
}
