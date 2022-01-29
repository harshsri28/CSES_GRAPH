#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define tc(t) ll t; cin >> t; while (t--)
#define ll long long
#define pb push_back
#define rep(i,a,b) for (ll i=a; i<b; ++i)
#define rev(i,a,b) for (ll i=a; i>b; --i)
#define debug(x) cout<<x<<"\n";
#define H_S ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define ini(a, i) memset(a, i, sizeof(a))
#define pii pair<int,int>
#define psi pair<string,int>
#define vi vector<ll>
#define vii vector<pair<int, int>>
#define s second
#define f first
using namespace __gnu_pbds;
#define X real()
#define Y imag()
#define PI 3.14159265359
typedef long double lld;
typedef pair<int, int> node;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a);}
ll LCM(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll max(ll a, ll b) {if (a > b) return a; else return b;}
ll min(ll a, ll b) {if (a < b) return a; else return b;}
ll expo(ll a, ll b) {ll res = 1; while (b > 0) { if (b & 1)res = res * a % mod; a = a * a % mod; b >>= 1; } return res;}
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
const int N = 2e5 + 10;
const int logk = 20;
const ll INF =  2e18 + 10;
const double eps = 0.001;
const int MOD = 1000000007;
const int nmax = 2e5;

char ar[1001][1001];
char br[1001][1001];
bool vis[1001][1001];
int n , m;
vector<char> path;


bool isValid(int x , int y) {

    if (x < 1 || x > n || y < 1 || y > m) return false;

    if (ar[x][y] == '#' || vis[x][y] == true) return false;

    return true;
}

bool bfs(int x , int y)
{
    queue<pair<int, int> > q;
    q.push({x , y});
    vis[x][y] = true;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (ar[a][b] == 'B') {
            while (1) {
                path.push_back(br[a][b]);

                if (path.back() == 'L') b++;
                if (path.back() == 'R') b--;
                if (path.back() == 'U') a++;
                if (path.back() == 'D') a--;

                if (a == x && b == y)
                    break;
            }
            return true;
        }

        //left
        if (isValid(a , b - 1)) br[a][b - 1] = 'L' , q.push({a , b - 1}) , vis[a][b - 1] = true;

        //right
        if (isValid(a , b + 1)) br[a][b + 1] = 'R' , q.push({a , b + 1}) , vis[a][b + 1] = true;

        //up
        if (isValid(a - 1, b)) br[a - 1][b] = 'U' , q.push({a - 1 , b}) , vis[a - 1][b] = true;

        //down
        if (isValid(a + 1, b)) br[a + 1][b] = 'D' , q.push({a + 1 , b}) , vis[a + 1][b] = true;

    }

    return false;
}
void solve() {
    cin >> n >> m;
    ll x, y;

    rep(i , 1, n + 1) rep(j, 1 , m + 1) {
        cin >> ar[i][j];
        if (ar[i][j] == 'A') x = i , y = j;
    }

    if (bfs(x , y) == true) {
        cout << "YES" << endl << path.size() << endl;
        while (path.size() > 0) cout << path.back() , path.pop_back();
    }
    else {
        cout << "NO";
    }

}



signed main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    H_S;
    // tc(t)
    solve();
}


