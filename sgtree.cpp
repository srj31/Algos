#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false)
using namespace std;

int tree[4*mxn];
 
void build(int a[],int tl,int tr,int tv) {
	if(tl == tr) {
		tree[tv] = a[tl];
		return;
	}
 
	int tm = (tl+tr)/2;
	build(a,tl,tm,tv<<1);
	build(a,tm+1,tr,tv<<1|1);
 
	tree[tv] = tree[tv<<1] ^ tree[tv<<1|1]; // chnage this 
}
 
void update(int a[],int tl,int tr,int tv, int idx , int val) {
	if(tl == tr) {
		a[idx] ^= val;
		tree[tv] = a[idx];
 
		return;
	}
 
	int tm = (tl+tr)/2;
	if(idx<=tm) {
		update(a,tl,tm,tv<<1,idx,val);
	} else {
		update(a,tm+1,tr,tv<<1|1,idx,val);
	}
 
	tree[tv] = tree[tv<<1] ^ tree[tv<<1|1]; // change this 
}
 
int query(int tl,int tr, int tv, int l, int r) {
	if(tl > r || tr < l)
		return 0;
 
	if(tl>=l && tr<=r) {
		return tree[tv];
	}
	int tm = (tl+tr)/2;
	return query(tl,tm,tv<<1,l,r) ^ query(tm+1,tr,tv<<1|1,l,r); // change this 
 
}

int main(){
	fast;
	cin.tie(0);
	string s;
	cin >> s;
	int q;
	cin >> q;
	int n = s.length();
	build(s,1,0,n-1);
	while(q--){
		int x,y;
		cin >> x >> y , --x,--y;
		brack ans = queryt(1,0,n-1,x,y);
		cout << 2*ans.first << endl;

	}

}