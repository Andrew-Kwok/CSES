#include <iostream>
#include <vector>
using namespace std;

vector<int> z_function(string s) {
    int n = (int)s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> pi_function(string s)
{
	int n = (int)s.size();
	vector<int> pi(n, 0);
	for (int i = 1; i < n; ++i)
	{
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] ==  s[j])
			j++;

		pi[i] = j;
	}
	return pi;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	vector<int> z = z_function(s);
	vector<int> pi = pi_function(s);

	for (int x : z)
		cout << x << " ";
	cout << '\n';

	for (int x : pi)
		cout << x << " ";
	cout << '\n';

	return 0;
}