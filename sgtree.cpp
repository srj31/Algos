#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false)
using namespace std;

const int mxN = 1e6;

typedef pair<int, int > pii;
typedef pair<int,pii> brack;

int t[4*mxN];
int o[4*mxN];
int c[4*mxN];

void build(string s,int v,int tl,int tr){

	if(tl==tr){
		if(s[tl]=='(')
			o[v] = 1;
		else
			c[v] = 1;

		return;
	}
	int mid = (tl+tr) >> 1;
	build(s,2*v,tl,mid);// for left child
	build(s,2*v+1,mid+1,tr);//for right child
	//now combine
	int tmp = min(o[2*v],c[2*v + 1]);
	t[v] = t[2*v] + t[2*v+1] + tmp;
	o[v] = o[2*v] + o[2*v + 1] - tmp;
	c[v] = c[2*v] + c[2*v + 1] - tmp;
}

brack queryt(int v,int tl,int tr,int l, int r){
	if(l>r)
		return brack(0,pii(0,0));
	if(tl==l && tr==r){
		return brack(t[v],pii(o[v],c[v]));
	}

	int tm = (tl+tr)>>1;
	brack left = queryt(2*v,tl,tm,l,min(r,tm));
	brack right = queryt(2*v+1, tm+1,tr,max(l,tm+1),r);

	int T,O,C,temp;
	temp = min(left.second.first,right.second.second);
	T = left.first + right.first + temp;
	O =  left.second.first + right.second.first - temp;
	C = left.second.second + right.second.second - temp;

	return brack(T,pii(O,C));

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