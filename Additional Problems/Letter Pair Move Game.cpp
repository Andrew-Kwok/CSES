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

const ld PI = 4*atan((ld)1);

int n;
vector<string> sk;
set<string> vst;
inline void rc(string s)
{
	if (vst.count(s))
		return;
	vst.insert(s);

	int id = -1;
	{
		bool sorted = true, bfound = false;
		for (int i = 0; i < 2*n; ++i)
		{
			if (s[i] == 'B') bfound = true;
			if (bfound && s[i] == 'A') sorted = false;
			if (s[i] == '.' && id == -1) id = i;
		}

		if (sorted)
		{
			cout << sk.size() << '\n';
			for (const string &x : sk)
				cout << x << '\n';
			exit(0);
		}
	}

	// (AB) A..
	//      B..  (BA)
	// (BA)  ..A
	//       ..B (AB)

	if (id)
	{
		if (s[id-1] == 'A')
		{
			int pos = 0;
			for (; pos+1 < id; ++pos)
			{
				if (s[pos] == 'A' && s[pos+1] == 'B')
					break;
			}

			if (pos+1 < id)
			{
				string nxt = s;
				swap(nxt[pos], nxt[id]);
				swap(nxt[pos + 1], nxt[id + 1]);
				sk.pb(nxt);

				swap(nxt[pos], nxt[id-1]);
				swap(nxt[pos+1], nxt[id]);
				sk.pb(nxt);
				
				rc(nxt);
				sk.pop_back(); sk.pop_back();
			}
		}
		else
		{
			int pos = id + 2;
			for (; pos+1 < 2*n; ++pos)
			{
				if (s[pos] == 'B' && s[pos+1] == 'A')
					break;
			}

			if (pos+1 < 2*n)
			{
				string nxt = s;
				swap(nxt[pos], nxt[id]);
				swap(nxt[pos + 1], nxt[id + 1]);
				sk.pb(nxt);

				swap(nxt[pos], nxt[id-1]);
				swap(nxt[pos+1], nxt[id]);
				sk.pb(nxt);
				
				rc(nxt);
				sk.pop_back(); sk.pop_back();
			}
		}
	}
	
	if (id+2 < 2*n)
	{
		if (s[id+2] == 'A')
		{
			int pos = 0;
			for (; pos+1 < id; ++pos)
			{
				if (s[pos] == 'B' && s[pos+1] == 'A')
					break;
			}

			if (pos+1 < id)
			{
				string nxt = s;
				swap(nxt[pos], nxt[id]);
				swap(nxt[pos + 1], nxt[id + 1]);
				sk.pb(nxt);

				swap(nxt[pos], nxt[id + 1]);
				swap(nxt[pos+1], nxt[id + 2]);
				sk.pb(nxt);
				
				rc(nxt);
				sk.pop_back(); sk.pop_back();
			}
		}
		else
		{
			int pos = id + 2;
			for (; pos+1 < 2*n; ++pos)
			{
				if (s[pos] == 'A' && s[pos+1] == 'B')
					break;
			}

			if (pos+1 < 2*n)
			{
				string nxt = s;
				swap(nxt[pos], nxt[id]);
				swap(nxt[pos + 1], nxt[id + 1]);
				sk.pb(nxt);

				swap(nxt[pos], nxt[id + 1]);
				swap(nxt[pos+1], nxt[id + 2]);
				sk.pb(nxt);
				
				rc(nxt);
				sk.pop_back(); sk.pop_back();
			}
		}
	}

	// if ((id && s[id-1] == 'A') || (id+2 < 2*n && s[id+2] == 'A'))
	{
		for (int pos = 0; pos+1 < 2*n; ++pos)
		{
			if (s[pos] == s[pos+1] && pos != id)
			{
				string nxt = s;
				swap(nxt[pos], nxt[id]);
				swap(nxt[pos + 1], nxt[id + 1]);
				sk.pb(nxt);

				rc(nxt);
				sk.pop_back();
			}
		}
	}
}

void solve()
{
	cin >> n;
	string s; cin >> s;
	rc(s);
	cout << -1 << '\n';	
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
