#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back

const int MAX = 1e6 + 69;

struct Node
{
	int l, r;
	int len, occ = 0;

	int ch[26]; //adding a character
	int slink; //suffix link
};

int sz, cur;
Node tree[MAX]; //eertree

string s;
void addChar(int idx)
{
	int tmp = cur;
	while (1)
	{
		if (idx - tree[tmp].len >= 1 && s[idx] == s[idx - tree[tmp].len - 1])
			break;
		tmp = tree[tmp].slink;
	}

	if (tree[tmp].ch[s[idx] - 'a'] != 0)
	{
		cur = tree[tmp].ch[s[idx] - 'a'];
		return;
	}

	sz++;
	tree[tmp].ch[s[idx] - 'a'] = sz;
	tree[sz].len = tree[tmp].len + 2;
	tree[sz].r = idx;
	tree[sz].l = idx - tree[sz].len + 1;

	// getting suffix link
	tmp = tree[tmp].slink;
	cur = sz;
	if (tree[cur].len == 1)
	{
		tree[cur].slink = 2;
		return;
	}

	while (1)
	{
		if (idx - tree[tmp].len >= 1 && s[idx] == s[idx - tree[tmp].len - 1])
			break;
		tmp = tree[tmp].slink;
	}

	tree[cur].slink = tree[tmp].ch[s[idx] - 'a'];
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	tree[1].len = -1;
	tree[1].slink = 1;
	tree[2].len = 0;
	tree[2].slink = 1;
	sz = 2; cur = 1;

	cin >> s;
	for (int i = 0; i < (int)s.size(); ++i)
	{
		addChar(i);
		tree[cur].occ++;
	}

	int res = 3;
	for (int i = 4; i <= sz; ++i)
		if (tree[res].len < tree[i].len)
			res = i;

	cout << s.substr(tree[res].l, tree[res].len) << '\n';

	return 0;
}