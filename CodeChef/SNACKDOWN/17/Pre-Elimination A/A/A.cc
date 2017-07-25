#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int N = 100100;

ll h[N];
ll a[N];
ll b[N];
ll sum[N];

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
		sum[i] = sum[i-1] + h[i];
		a[i] = b[i] = 1;
	}
	
	int cur = 1;
	for(int i = 1; i <= n; i++){
		if(h[i] >= cur){
			a[i] = cur++;
		}
		else{
			cur = a[i] = h[i];
			cur++;
		}
	}
	
	cur = 1;
	for(int i = n; i > 0; i--){
		if(h[i] >= cur){
			b[i] = cur++;
		}
		else{
			cur = b[i] = h[i];
			cur++;
		}
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ll len = min(a[i], b[i]);
		ans = max(ans, len);
	}
	
	ans = sum[n] - ((ans-1) * (ans) + ans);
	assert(ans >= 0);
	cout << ans << endl;
	
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}