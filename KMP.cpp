#include<bits/stdc++.h>
using namespace std;


vector<int> prefix_function(string s){
	int n = (int)s.length();
	vector<int> pf(n);
	pf[0] = 0;
	for(int i=1;i<n;i++){
		int j=pf[i-1];
		while(j>0&&s[i]!=s[j])
			j=pf[j-1];
		if(s[i]==s[j])
			j++;
		pf[i] = j;
	}
	return pf
}