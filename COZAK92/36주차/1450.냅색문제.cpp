#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define debug(x) cerr << #x << " is " << x << "\n"
using ll = long long;
using pii = pair<int,int>;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int MX = 50;

ll arr[MX];
unordered_map<ll,ll> s1;
vector<ll> l,r;

int n,c,h;
int ans = 0;
void searchLeft(int index, int sum){
    if(sum > c) return;
    if( index == h){
        l.push_back(sum);
        return;
    }

    searchLeft(index + 1, sum + arr[index]);
    searchLeft(index + 1, sum);
}
void serachRight(int index, int sum){
    if(sum > c) return;
    if( index == n){
        r.push_back(sum);
        return;
    }

    serachRight(index + 1, sum + arr[index]);
    serachRight(index + 1, sum);
}

void solve(){
    cin >> n >> c;
    h = n/2;
    REP(i,n) cin >> arr[i];
    s1[0] = 1;
    searchLeft(0,0);
    serachRight(h,0);
    sort(ALL(l));
    sort(ALL(r));

    for(auto a : l){
        int R = upper_bound(ALL(r), c - a) - r.begin();
        ans += R;
    }

    cout << ans;
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}