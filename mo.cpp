#include<bits/stdc++.h>
using namespace std;

vector<int> a,b;
const int blen = 700;
int cnt;
int freq[1000001];

struct query{
	int l,r,idx;
};

bool cmp(query a, query b){
	return (a.l/blen < b.l/blen)||((a.l/blen == b.l/blen) &&(a.r<b.r));
}

void add(int i){
	freq[a[i]]++;
	if(freq[a[i]]==1)
		cnt++;
}

void remove(int i){
	freq[a[i]]--;
	if(freq[a[i]]==0)
		cnt--;
}


int main(){
	int n;cin >> n;
	a= vector<int> (n);
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int q;
	cin>> q;
	vector<query> qs(q);

	for(int i =0;i<q;i++){
		cin >> qs[i].l >> qs[i].r;
		qs[i].l--,qs[i].r--;
		qs[i].idx = i;
	}
	int ans[q];
	sort(qs.begin(),qs.end(),cmp);
	int ml = 0,mr = -1;
	for(int i =0;i<q;i++){
		int l = qs[i].l;
		int r=  qs[i].r;
		//adding the elements for answering the queries
		while(ml>l)add(--ml);
		while(mr<r)add(++mr);

		//removing the elements
		while(ml<l)remove(ml++);
		while(mr>r)remove(mr--);

		ans[qs[i].idx] = cnt;
	}	
	for(int i =0;i<q;i++){
		cout << ans[i] << endl;
	}

}