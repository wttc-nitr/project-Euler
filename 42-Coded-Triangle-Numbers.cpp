/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vb vector<bool>
#define vi vector<int>
#define vc vector<char>
#define INF (1LL << 60)
#define inf (1 << 30)

vector<int> arr;

int wordValue (string const& str) {
	int sum = 0;

	for (auto c : str)
		sum += c - 'A' + 1;

	return sum;
}

void generateTriangleNum (void) {
	for (int i=1; i <= 27; i++)
		arr.push_back(i * (i+1) / 2);
}

bool isTriangleNum (int x) {
	return binary_search(arr.begin(), arr.end(), x);
}

void solve(void) {
	generateTriangleNum();

	int res = 0, temp;

	string str;
	char c;

	while (cin >> c) {

		if ('A' <= c && c <= 'Z')
			str += c;
		else {
			if (str.empty())
				continue;

			temp = wordValue(str);

			if (isTriangleNum(temp))
				res++;

			str.clear();
		}
	}

	cout << res;
}

int main(void) {
     ios::sync_with_stdio(0); cin.tie(0);

    freopen("/home/animesh/Desktop/0042_words.txt", "r", stdin);

    solve();

    return 0;
}