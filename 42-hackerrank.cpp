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

/*
 *      x = n * (n + 1) / 2
 * =>   n = (-1 + sqrt(1 + 8x)) / 2   -> solution of quadratic equation
 * =>   n must be an integer, that means sqrt(1 + 8x) is also integer
 *
 *  check whether (1 + 8x) is integer
*/

void altSolve (void) {
    ll x; cin >> x;

    ll y = sqrt(1 + 8 * x);

    if (y * y == 1 + 8 * x)
        cout << (y-1) / 2;
    else cout << -1 ;

    cout << '\n';
}

// ll x = 1e12;
// x * (x + 1) -> doesn't overflow, 1e13 will overflow

void solve(void) {
    ll x; cin >> x;

    ll lo = 1, hi = 1e10, mid, ans = -1;

    while (lo <= hi) {
        mid = lo + (hi-lo) / 2;

        if (mid * (mid + 1) / 2 == x) {
            ans = mid;
            break;
        }

        if (mid * (mid + 1) / 2 < x)
            lo = mid + 1;
        else hi = mid - 1;
    }

    cout << ans << '\n';
}

int main(void) {
     ios::sync_with_stdio(0); cin.tie(0);
     
    int test_cases = 1; cin >> test_cases;
    while (test_cases-- > 0) {
           altSolve();
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}