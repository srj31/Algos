#include<bits/stdc++.h>
using namespace std;
const double INF = 1e12 + 0.1;
const double eps = 1e-7;

struct pt{
	int x,y;
};

double dist(pt a, pt b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y))*1.0;
}

int main(){
	int n;
	cin >> n;
	vector<pt> pts(n);
	for(int i=0;i<n;i++){
		cin >> pts[i].x >> pts[i].y ;
 	}
 	int k;
 	cin >> k;
 	vector<double> distancestaken;
 	vector<int> taken(n,0);
 	vector<double> d(n,INF);
 	d[0] = 0;
 	for(int i =0;i<n;i++){
 		int curr = -1;
 		for(int j=0;j<n;j++){
 			if(!taken[j] && (curr==-1 || d[j]<d[curr]))
 				curr =j;
 		}

 		taken[curr] = 1;
 		distancestaken.push_back(d[curr]);
 		for(int j =0;j<n;j++){
 			if(taken[j])continue;
 			if(d[j]-dist(pts[j],pts[curr])>eps)
 				d[j] = dist(pts[j],pts[curr]);
 		}
 	}
 	// cout << 1 << endl;
 	sort(distancestaken.begin(),distancestaken.end(),greater<double>());
 	for(int i =0;i<n-1;i++){
 		// cout << distancestaken[i] << endl ;
 	}
 	double ans = distancestaken[k-2];
 	cout << fixed << setprecision(12) << ans << endl;
}