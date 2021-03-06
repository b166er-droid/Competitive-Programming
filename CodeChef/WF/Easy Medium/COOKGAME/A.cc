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
const int MOD = 1e9 + 7;

int a[N];
int p[N];

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = n-1; i >= 0; i--){
		if(a[i] == -1){
			if(a[i+1] > 1) a[i] = a[i+1] - 1;
		}
		else{
			if(abs(a[i+1]) != 1 and a[i+1] != a[i] + 1){
				cout << "0\n";
				return;
			}
		}
	}

	if(a[1] == -1) a[1] = 1;
	
	if(a[1] != 1){
		cout << "0\n";
		return;
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt += a[i] == -1;
	}
	
	cout << p[cnt] << '\n';
		
}

int main(){ _
	p[0] = 1;
	for(int i = 1; i < N; i++){
		p[i] = p[i-1] + p[i-1];
		if(p[i] >= MOD) p[i] -= MOD;
	}
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
