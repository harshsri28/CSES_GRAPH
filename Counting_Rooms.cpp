#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define tc(t) ll t; cin >> t; while (t--)
#define ll long long
#define pb push_back
#define debug(x) cout<<x<<"\n";
#define Harsh_Srivastava ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define ini(a, i) memset(a, i, sizeof(a))
#define fi first
#define pii pair<int,int>
#define psi pair<string,int>
#define sc second
#define fr first
#define ll long long
typedef long double lld;
 
 
ll gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
ll LCM(ll a, ll b) { return (a / gcd(a, b)) * b; }
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
void pr(int x) {cout << x;}
void prl(int x) {cout << x << "\n";}
// Function to find the nCr
void printNcR(int n, int r)
{   long long p = 1, k = 1;
    if (n - r < r) r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    cout << p << endl;
}
// expo
lld expo1(lld a, ll b)
{
    lld res = 1.0;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int mod = 1e9 + 7;
const int N = 100010;
const int len = 26;
const int INF =  1e9;
 
int n, m, ans = 0;
char grid[1010][1010];
int vis[1010][1010];
 
 
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
 
bool isValid(int x, int y) {
    if (y < 0 || x < 0 || x >= n || y >= m || grid[x][y] == '#')return false;
 
    return true;
}
 
void dfs(int x, int y) {
    vis[x][y] = 1;
 
    for (int i = 0; i < 4; ++i) {
        int X = x + dirx[i];
        int Y = y + diry[i];
 
        if (isValid(X, Y)) {
            if (!vis[X][Y])
                dfs(X, Y);
        }
    }
}
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            vis[i][j] = 0;
        }
    }
 
 
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }
 
    cout << ans << "\n";
}
 
signed main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
 
    Harsh_Srivastava;
    // ll t; cin >> t;
    // for (int i = 1; i <= t; ++i) {
    //     solve();
    //     cout << "Case #" << i << ":" << " " << x << "\n";
    // }
    // tc(t)
    solve();
}