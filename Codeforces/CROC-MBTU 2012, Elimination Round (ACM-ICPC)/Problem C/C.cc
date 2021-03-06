#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, a[111], ans;

int main(){
	sd(n);
	if(n < 3 or n%2 == 0){
		puts("-1");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	for(int i = n; i > 1; i--){
		if(i%2 == 1){
			a[i-1] -= a[i];
			a[(i-1)/2] -= a[i];
			a[i-1] = max(a[i-1],0);
			a[(i-1)/2] = max(a[(i-1)/2],0);
			ans += a[i];
			a[i] = 0;
		}
		else{
			a[i+1] -= a[i];
			a[i/2] -= a[i];
			a[i+1] = max(a[i+1],0);
			a[i/2] = max(a[i/2],0);
			ans += a[i];
			a[i] = 0;
		}
	}
	
	ans += a[1];
	
	tr(ans);	
		
	return 0;	
}
