#include <bits/stdc++.h>
using namespace std;

#define pb push_back

using cd = complex<double>;

const int LG = 19;
const int MAX = 1 << LG;
const double PI = 4 * atan((double)1);

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

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char s[MAX];
	vector<cd> A(MAX), B(MAX);

	cin >> s;
	int N = (int)strlen(s);

	for (int i = 0; i < N; ++i)
	{
		if (s[i] == '1')
		{
			A[i] += 1;
			B[N-i-1] += 1;
		}
	}

	fft(A, false);
	fft(B, false);
	for (int i = 0; i < MAX; ++i)
		A[i] *= B[i];
	fft(A, true);

	for (int i = N; i < 2*N-1; ++i)
		cout << llround(A[i].real()) << " \n"[i == 2*N-2];

	return 0;
}