#include<bits/stdc++.h>
using namespace std;
const int mxn = 3e6;
vector<int> pf(mxn);
string t,p;

int main(){
	cin >> p >> t;
	int check = p.length();
	string s = p+'$'+t;
	int n = s.length();
	for(int i =1;i<n;i++){
		int j = pf[i-1];
		while(j>0 && s[i]!=s[j])
			j=pf[j-1];
		if(s[i]==s[j])
			j++;
		pf[i] = j;
	}
	vector<int> ans;
	for(int i=check+1;i<n;i++){
		if(pf[i]==check)
			ans.push_back(i-check-1);
	}

	for(auto e: ans)
		cout << (e-check+1) << " ";
	cout << endl;
}