#include<bits/stdc++.h>
using namespace std;

vector<pair<long long int,long long int > > ans(2);
long long closestPairDistance2(vector<pair<long long,long long>  > pts){
	// using the two polong longer technique
	long long n =pts.size();
	sort(pts.begin(),pts.end());
	long long bestDist = 1e18;
	long long j=0;
	set<pair<long long,long long> > s;
	for(long long i =0;i<n;i++){
		// cout << i << endl;
		while(pts[j].first<=pts[i].first-bestDist){
			s.erase(make_pair(pts[j].second,pts[j].first));
			j++;
		}
		// cout << i << endl;

		auto it1 = s.lower_bound(make_pair(pts[i].second-bestDist,pts[i].first));
		auto it2 = s.upper_bound(make_pair(pts[i].second+bestDist,pts[i].first));

		for(auto it = it1;it!=it2;it++){
			long long dx = pts[i].first - it->second;
			// cout << dx << " dx " << endl;
			long long dy  = pts[i].second - it->first;
			// cout << dy << " dy " << endl;
			if(1LL*dx*dx + 1LL*dy*dy<bestDist){
				ans[0] = make_pair(pts[i].first,pts[i].second);
				ans[1] = make_pair(it->second,it->first);
			}
			bestDist = min(bestDist,1LL*dx*dx + 1LL*dy*dy);
			// cout << i << endl;

		}

		s.insert(make_pair(pts[i].second ,pts[i].first));

	}
	return bestDist;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// while(true){
		int n;
		cin >> n;
		if(n==0)
			exit(0);
		vector<pair<long long ,long long> > pts;
		for(int i =0;i<n;i++){
			long long x,y;
			cin >> x >> y;
			pts.push_back(make_pair(x,y));
		}
		// cout << 1 << endl;
		long long distsq = closestPairDistance2(pts);
		long double ansdist = sqrt(distsq);
		// sort(pts.begin(),pts.end);
		// int ans[2];
		int a,b;
		for(int i =0;i<n;i++){
			if(pts[i]==ans[0]){
				a = i;
				break;
			}
		}for(int i =0;i<n;i++){
			if(pts[i]==ans[1]){
				b = i;
				break;
			}
		}
		if(b<a)
			swap(a,b);
		cout << a << " " << b << " ";
		cout << fixed << setprecision(6) << ansdist << endl;
	// }
}