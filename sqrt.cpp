#include<bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;
const int INF= INT_MAX;
int len;

int getmin(int l,int r){
	int lb = l/len;
	int rb = r/len;
	int ans = INF;
	if(lb==rb){
		for(int i =l;i<=r;i++){
			ans = min(ans,a[i]);
		}
		return ans;
	}
	else{
		for(int i =l;i<len*(lb+1);i++)
			ans=min(ans,a[i]);
		for(int i =lb+1;i<rb;i++){
			ans=min(ans,b[i]);
		}
		for(int i=rb*len;i<=r;i++)
			ans=min(ans,a[i]);

		return ans;
	}
}


int main(){
	int n;
	cin >> n;
	a=vector<int> (n);
	len = sqrt(n)+1;
	b=vector<int>(len,INF);
	for(int i =0;i<n;i++){
		cin >> a[i];
		b[i/len] = min(b[i/len],a[i]);
	}

	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << getmin(l,r) << endl;
	}
}