#include <iostream>
#include <cassert>
using namespace std;

struct TrieNode
{
	int val;
	TrieNode *ar[2];
	TrieNode() : val(0) { ar[0] = ar[1] = NULL; }
};

void insert(TrieNode *root, int x)
{
	TrieNode *tmp = root;
	for (int i = 30; i >= 0; --i)
	{
		bool on = x & (1 << i);
		if (tmp -> ar[on] == NULL)
			tmp -> ar[on] = new TrieNode();
		tmp = tmp -> ar[on];
	}
	tmp -> val = x;
}

int query(TrieNode *root, int x)
{
	TrieNode *tmp = root;
	for (int i = 30; i >= 0; --i)
	{
		bool on = x & (1 << i);
		if (tmp -> ar[1 - on] != NULL)
			tmp = tmp -> ar[1 - on];
		else tmp = tmp -> ar[on];
	}
	return tmp -> val;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	TrieNode *root = new TrieNode();
	insert(root, 0);

	int n, x, xsum = 0;
	int res = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x; xsum ^= x;
		res = max(res, xsum ^ query(root, xsum));
		insert(root, xsum);
	}
	cout << res << '\n';

	return 0;
}