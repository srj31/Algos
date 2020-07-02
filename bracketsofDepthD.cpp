#include<bits/stdc++.h>
using namespace std;

int main(){
	// cnt[0][j] = 1
	for(int i =1;i<pairs;i++){
		for(int j =0;j<=maxD;j++){
			for(int k = 0;k<i;i++){
				cnt[i][j]+= cnt[k][j-1]*cnt[i-k-1][j];
			}
		}
	}

	ans = cnt[n/2][d] - cnt[n/2][d-1];
}