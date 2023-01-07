#include <bits/stdc++.h>
using namespace std;

#define pb push_back

using ld = double;
using cd = complex<ld>;

const ld PI = 4 * atan((ld)1);
const int LG = 19;
const int MAX = 1 << LG;

// inline void fft(vector<cd> &P, bool inv = false)
// {
// 	int n = (int)P.size();
// 	if (n == 1)
// 		return;

// 	vector<cd> Pe(n/2), Po(n/2);
// 	for (int i = 0; i < n/2; ++i)
// 	{
// 		Pe[i] = P[i << 1];
// 		Po[i] = P[i << 1 | 1];
// 	}

// 	fft(Pe, inv);
// 	fft(Po, inv);

// 	ld theta = 2*PI/n * (inv ? -1 : 1);
// 	cd w = 1, wn(cos(theta), sin(theta));
// 	for (int i = 0; i < n/2; ++i)
// 	{
// 		P[i] = Pe[i] + w * Po[i];
// 		P[i + n/2] = Pe[i] - w * Po[i];
// 		if (inv)
// 		{
//             P[i] /= 2;
//             P[i + n/2] /= 2;
//         }
// 		w *= wn;
// 	}
// }

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
		ld theta = 2 * PI / len * (inv ? -1 : 1);
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

	int k, n, m;
	cin >> k >> n >> m;

	vector<cd> a(MAX, 0), b(MAX, 0);
	for (int i = 0, x; i < n; ++i)
	{
		cin >> x;
		a[x] += 1;
	}

	for (int i = 0, x; i < m; ++i)
	{
		cin >> x;
		b[x] += 1;
	}

	fft(a, false);
	fft(b, false);
	for (int i = 0; i < MAX; ++i)
		a[i] *= b[i];
	fft(a, true);

	for (int i = 2; i <= 2*k; ++i)
		cout << llround(a[i].real()) << " \n"[i == 2*k];
	
	return 0;
}