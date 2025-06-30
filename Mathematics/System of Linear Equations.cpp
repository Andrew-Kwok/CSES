#include <bits/stdc++.h>
using namespace std;

template<int MOD>
struct Mint
{
    int val;

    Mint() : val(0) {}
    Mint(int64_t _val) : val((int)(_val % MOD)) { if (val < 0) val += MOD; }

    Mint& operator+= (const Mint &rhs) { val += rhs.val; if (val >= MOD) val -= MOD; return *this; }
    Mint& operator-= (const Mint &rhs) { val -= rhs.val; if (val < 0) val += MOD; return *this; }
    Mint& operator*= (const Mint &rhs) { val = (int)(1ll * val * rhs.val % MOD); return *this; }

    friend Mint fpow(Mint x, int64_t y)
    {
        Mint res = 1;
        for (; y > 0; y >>= 1, x *= x)
        {
            if (y & 1)
                res *= x;
        }
        return res;
    }
    friend Mint inverse(Mint x) { return fpow(x, MOD-2); }
    Mint& operator/= (const Mint &rhs) { return *this *= inverse(rhs); }

    friend Mint operator+ (Mint a, const Mint &b) { return a += b; }
    friend Mint operator- (Mint a, const Mint &b) { return a -= b; }
    friend Mint operator- (Mint a) { return 0 - a; }
    friend Mint operator* (Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/ (Mint a, const Mint &b) { return a /= b; }
    friend ostream& operator<< (ostream &os, const Mint &a) { return os << a.val; }
    friend bool operator== (const Mint &a, const Mint &b) { return a.val == b.val; }
    friend bool operator!= (const Mint &a, const Mint &b) { return a.val != b.val; }
};

const int MAX = 1 << 9;
const int ModC = 1e9 + 7;

using MintC = Mint<ModC>;


struct Equation
{
	// Ax = B
	vector<MintC> A;
	MintC B;

	bool zero() const
	{
		if (B != 0) return false;
		for (auto x : A) if (x != 0)
			return false;
		return true;
	}

	bool bad() const
	{
		for (auto x : A) if (x != 0)
			return false;
		return B != 0;
	}

	Equation& operator+=(const Equation& rhs) {
		for (int i = 0; i < (int)A.size(); ++i)
			A[i] += rhs.A[i];
		B += rhs.B;
		return *this;
	}

	Equation& operator-=(const Equation& rhs) {
		for (int i = 0; i < (int)A.size(); ++i)
			A[i] -= rhs.A[i];
		B -= rhs.B;
		return *this;
	}

	Equation& operator*=(const MintC C) {
		for (int i = 0; i < (int)A.size(); ++i)
			A[i] *= C;
		B *= C;
		return *this;
	}

	Equation& operator/=(const MintC C) {
		MintC div = 1 / C;
		for (int i = 0; i < (int)A.size(); ++i)
			A[i] *= div;
		B *= div;
		return *this;
	}
	
	Equation& normalize()
	{
		for (auto x : A) if (x != 0)
		{
			*this /= x;
			break;
		}
		return *this;
	}

	friend Equation operator+ (Equation a, const Equation &b) { return a += b; }
    friend Equation operator- (Equation a, const Equation &b) { return a -= b; }
    friend Equation operator* (Equation a, const MintC &c) { return a *= c; }
    friend Equation operator/ (Equation a, const MintC &c) { return a /= c; }


} eq[MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		eq[i].A.resize(M);
		for (int j = 0, x; j < M; ++j)
		{
			cin >> x;
			eq[i].A[j] = x;
		}
		int x; cin >> x;
		eq[i].B = x;
	}


	int rref = 0;
	for (int j = 0; j < M && rref < N; ++j)
	{
		for (int i = rref; i < N; ++i) if (eq[i].A[j] != 0)
		{
			swap(eq[i], eq[rref]);
			break;
		}

		if (eq[rref].A[j] == 0)
			continue;

		eq[rref].normalize();
		for (int i = rref+1; i < N; ++i)
		{
			eq[i] -= eq[rref] * eq[i].A[j];
		}
		rref++;
	}

	for (int i = rref; i < N; ++i) if (eq[i].bad())
	{
		cout << "-1\n";
		return 0;
	}

	vector<MintC> X(M, 0);
	for (int i = rref-1; i >= 0; --i)
	{
		int k = -1;
		for (int j = 0; j < M; ++j) if (eq[i].A[j] != 0) 
		{
			k = j;
			break;
		}
		assert(k != -1 && eq[i].A[k] == 1);
	
		X[k] = eq[i].B;
		for (int j = k+1; j < M; ++j)
			X[k] -= X[j] * eq[i].A[j];
	}

	for (int i = 0; i < M; ++i)
		cout << X[i] << " \n"[i+1 == M];

	return 0;
}