#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e6+1;
	pair<char,int> fcol[mxn];
	int lasttofirst[mxn];

int main(){
	string bwt;
	cin >> bwt;
	int n = bwt.length();
	for(int i =0;i<n;i++)
		fcol[i] = {bwt[i],i};

	sort(fcol,fcol+n,[](pair<char,int> a, pair<char,int> b){ return (a.first<b.first || (a.first==b.first && a.second<b.second));});
	for(int i =0;i<n;i++){
		lasttofirst[fcol[i].second] = i;
	}

	string ans = "";
	int j = 0;
	while(true){
		ans+=fcol[j].first;
		j = lasttofirst[j];
		if(j==0)
			break;
	}
	reverse(ans.begin(),ans.end());
	cout << ans << endl;
}