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
using cd = complex<double>;

const double PI = 4*atan((double)1);
const int LG = 19;
const int MAX = 1 << LG;

inline void fft(vector<cd> &P, bool inv)
{
	const auto rev = [&](int x) -> int
	{
		int res = 0;
		for (int i = 0; i < LG; ++i, x >>= 1)
			res = res << 1 | (x & 1);
		return res;
	};

	int n = (int)P.size();
	for (int i = 0; i < n; ++i)
	{
		int j = rev(i);
		if (i < j) 
			swap(P[i], P[j]);
	}

	for (int len = 2; len <= n; len <<= 1)
	{
		double theta = 2 * PI / len * (inv ? -1 : 1);
		cd wn(cos(theta), sin(theta));
		for (int i = 0; i < n; i += len)
		{
			cd w(1);
			for (int j = 0; j < len/2; ++j)
			{
				cd e = P[i+j], o = P[i+j + len/2] * w;
				P[i+j] = e + o;
				P[i+j + len/2] = e - o;
				w *= wn;
			}
		}
	}


	if (inv)
	{
		for (cd &z : P)
			z /= n;
	}
}

void solve()
{
	char s[MAX];
	cin >> s;

	vector<cd> A(MAX, 0), B(MAX, 0);

	int len = (int)strlen(s);
	A[0] += 1, B[len] += 1;
	for (int i = 0, sum = 0; i < len; ++i)
	{
		sum += s[i] == '1';
		A[sum] += 1;
		B[len - sum] += 1;
	}

	fft(A, 0);
	fft(B, 0);
	for (int i = 0; i < MAX; ++i)
		A[i] *= B[i];
	fft(A, 1);

	ll res = 0;
	for (int i = 0, sum = 0; i < len; ++i)
	{
		if (s[i] == '0') sum++;
		else sum = 0;
		res += sum;
	}	

	cout << res;
	for (int i = 1; i <= len; ++i)
		cout << " " <<  llround(A[len + i].real());
	cout << '\n';
}


int main()
{
	fastio;

	int TC = 1;
	//cin >> TC;

	while (TC--)
		solve();

	return 0;
}
