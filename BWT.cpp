#include<bits/stdc++.h>
using namespace std;

int main(){
	string t;
	cin >> t;
	int n = t.length();
	string BWT[n];
	for(int i =0;i<n;i++){
		string cur = "";
		int j = i;
		int l = 0;
		while(l<n){
			cur+=t[(j+l)%n];
			l++;
		}
		BWT[i] = cur;
	}
	sort(BWT,BWT+n);
	for(int i =0;i<n;i++)
		cout << BWT[i][n-1];
	cout << endl;
}