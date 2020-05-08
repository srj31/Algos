#include<bits/stdc++.h>
using namespace std;
const long long int INF = 1e12+7;
vector<vector<pair<int, long long int> > > adj(1000000);
int n;
void dijkstra(int s,vector<long long int> &d, vector<int> &p){
	vector<bool>u(n,false);

	set<pair<long long int,int> > q;
	q.insert(make_pair(0,s));

	d[s] = 0;
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());

		for(auto edge: adj[v])
		{
			int to = edge.first;
			long long int dist = edge.second;
			if(d[v]+dist<d[to]){
				d[to] = d[v] + dist;
				p[to] = v;
				q.insert(make_pair(d[to],to));
			}
		}
	}
}


vector<int> restore(int s, int t, vector<int>const& p){
	vector<int> path;

	for(int i=t;i!=s;i=p[i]){
		path.push_back(i);
		if(i==-1){
			cout << "-1 " << endl;
			exit(0);
		}
		// cout << i << endl;
	}

	path.push_back(s);
	reverse(path.begin(),path.end());
	return path;
}

int main(){
	int m;
	cin >> n >> m;
	for(int i =0;i<m;i++){
		long long int x,y,d;
		cin >> x >> y >> d;
		x--;y--;
		adj[x].push_back(make_pair(y,d));
	}
	int s,e;
	cin >> s >> e;--s,--e;
	vector<long long int> dl(n,INF);
	vector<int> p(n,-1);
	dijkstra(s,dl,p);
	vector<int> path = restore(s,e,p);
	// cout << n << endl;
	if(dl[e]==INF) cout << -1 << endl;
	else{
		cout << dl[e] << endl;
	}
	// cout << endl;
}