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
#define vi vector<int>
#define vii vector<pii>
typedef long double lld;
#define INF (1<<30)
 
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
const int N = 1005;
const int len = 26;
 
 
int vis[100005] = {0};
int col[100005];
vi adj[100005];
queue<int> q;
 
bool bfs(int s) {
    vis[s] = 1;
 
    q.push(s);
    col[s] = 1;
 
    while (!q.empty()) {
        int s = q.front();
        q.pop();
 
        for (auto x : adj[s]) {
            if (col[x] == col[s]) return 0;
            if (vis[x]) continue;
            vis[x] =  1;
            col[x] = (col[s] == 1 ? 2 : 1);
            q.push(x);
        }
    }
    return 1;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
 
    for (int i = 1; i < n + 1; ++i) {
        if (!vis[i]) {
            if (!bfs(i)) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
 
    for (int i = 1; i < n + 1; ++i)
        cout << col[i] << " ";
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