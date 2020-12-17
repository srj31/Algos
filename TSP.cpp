#include <bits/stdc++.h>
using namespace std;

struct pt {
	int x,y,z;
};

int d(pt a, pt b) {
	return abs(a.x - b.x) + abs(a.y - b.y) + max(0,b.z - a.z);
}

int dp[17][1000001];


int main() {
	int n;
	cin >> n;
	pt pts[n];
	for(int i =0;i<n;i++) {
		cin >> pts[i].x >> pts[i].y >> pts[i].z;
	}
	int dis[n][n];
	for(int i =0;i<n;i++) {
		for(int j =0;j<n;j++) {
			dis[i][j] = d(pts[i],pts[j]);
		}
	}

	memset(dp,-1,sizeof(dp));
	dp[0][1] = 0;
	for(int s = 2 ;s < (1<< n) ; s++) {
		// cout << s << endl;
		for(int i =0;i<n;i++) {
			if((s&(1<<i))==0) continue;
			for(int j =0;j<n;j++) {
				if(i==j || (s&(1<<j))==0) continue;
				if(dp[j][(s-(1<<i))]==-1)continue;
				if(dp[i][s]==-1) {
					dp[i][s] = dp[j][s-(1<<i)] + dis[j][i];
				} else {
					dp[i][s] = min(dp[i][s] , dp[j][s-(1<<i)] + dis[j][i]);
				}
			}
		}

		for(int i=0;i<n;i++){
			if((s&(1<<i))==0) continue;
			for(int j=0;j<n;j++){
				if(dp[j][s]!=-1) {
					if(dp[i][s]==-1) dp[i][s] = dp[j][s]+dis[j][i];
					else dp[i][s] = min(dp[i][s] ,dp[j][s]+dis[j][i] );
				}

			}
		}
	}

	cout << dp[0][(1<<n)-1] << endl;
}