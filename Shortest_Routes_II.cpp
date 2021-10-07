#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define tc(t) ll t; cin >> t; while (t--)
#define ll long long
#define int long long
#define pb push_back
#define debug(x) cout<<x<<"\n";
#define Harsh_Srivastava ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define ini(a, i) memset(a, i, sizeof(a))
#define pii pair<int,int>
#define psi pair<string,int>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
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
const int N = 505;
const int len = 26;
const int INF = 1000000000000;
 
int dis[N][N];
 
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
 
    rep(i, 1, n + 1) rep(j, 1, n + 1) dis[i][j] = INF;
 
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][u] = 0, dis[v][v] = 0;
        dis[u][v] = min(dis[u][v], w), dis[v][u] = min(dis[u][v], w);
    }
 
    rep(k, 1, n + 1) {
        rep(i, 1, n + 1) {
            rep(j, 1, n + 1) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
 
    rep(i, 0, q) {
        int a, b; cin >> a >> b;
        if (dis[a][b] < INF)cout << dis[a][b] << "\n";
        else cout << -1 << "\n";
    }
 
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