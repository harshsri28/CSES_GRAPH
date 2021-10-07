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
const int N = 1e5 + 1;
const int len = 26;
 
int n, m;
vector<string> v;
int dist[1001][1001];
int d[1001][1001];
 
int dx[4] = {0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};
 
void solve() {
    for (int i = 0; i < 1001; ++i)for (int j = 0; j < 1001; ++j)    dist[i][j] = -1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string x; cin >> x;
        v.pb(x);
    }
 
    int x, y, c1, c2;
    queue<vector<int>>q;
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'M') q.push({i, j, 0});
            if (v[i][j] == 'A') c1 = i, c2 = j;
        }
    }
 
    x = c1, y = c2;
 
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr[0], y = curr[1], steps = curr[2];
        if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y] == '#' || dist[x][y] != -1) continue;
        dist[x][y] = steps;
        for (int i = 0; i < 4; ++i) {
            int cx = x + dx[i], cy = y + dy[i];
            q.push({cx, cy, steps + 1});
        }
    }
 
    string ans;
    while (!q.empty()) q.pop();
    q.push({x, y, 0, 0});
    for (int i = 0; i < 1001; ++i)for (int j = 0; j < 1001; ++j)    d[i][j] = -1;
 
    bool c = false;
    int p[n + 1][m + 1];
    memset(p, 0, sizeof(p));
 
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr[0], y = curr[1], steps = curr[2], dir = curr[3];
        if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y] == '#' || d[x][y] != -1 || (dist[x][y] >= 0 and dist[x][y] <= steps))
            continue;
        if (x == n - 1 || y == m - 1 || x == 0 || y == 0) {
            p[x][y] = dir;
            while (x != c1 or y != c2) {
                if (p[x][y] == 0)    ans += 'L', y++; // path is from (x, y) to (x, y-1) so ans+='L' and (0=> {0, -1}) thats why y++.
                else if (p[x][y] == 1) ans += 'R', y--;
                else if (p[x][y] == 2)  ans += 'U', x++;
                else    ans += 'D', x--;
            }
            reverse(ans.begin(), ans.end());
            c = true;
            break;
        }
        d[x][y] = steps;
        p[x][y] = dir;
 
        for (int i = 0; i < 4; ++i) {
            int cx = x + dx[i], cy = y + dy[i];
            q.push({cx, cy, steps + 1, i});
        }
    }
 
    if (c) {
        cout << "YES" << endl << ans.size() << endl << ans;
    }
    else
        cout << "NO" << endl;
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