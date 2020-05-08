#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,long long int> > > adj;
vector<long long int> d;
vector<int> vis;
const long long int INF = 1e15+99;

void dfs(int u){
	// cout << u << endl;
	vis[u] = 1;
	d[u] = -INF;
	for(auto v:adj[u]){
		if(!vis[v.first])
		dfs(v.first);
	}
}

vector<int> vis2;
bool dfs2(int s, int t){
	vis2[s] = 1;
	// cout << s << endl;
	if(s==t)return true;
	for(auto v:adj[s]){
		int to = v.first;
		if(!vis2[to]){
			if(dfs2(to,t))
				return true;
		}
	}
	return false;
}

void dfs3(int u){
	// cout << u <<endl;
	vis[u] = 1;
	d[u]=INF;

}
int main(){
	int n,m;
	cin >> n >> m;
	adj = vector<vector<pair<int,long long int > > >(n);
	d  = vector<long long int> (n,INF);
	vis = vector<int> (n,0);
	for(int i =0;i<m;i++){
		int u,v;
		long long int d;
		cin >> u >> v >> d;
		--u,--v;
		adj[u].push_back(make_pair(v,d));
	}
	int s = 0;
	cin >> s;
	--s;
	d[s] = 0;
	for(int i =0;i<n-1;i++){
		for(int j =0;j<n;j++){
			for(auto edges: adj[j]){
				int to = edges.first;
				long long int len  = edges.second;
				if(d[j]!=INF && d[to]>d[j]+len){
					d[to] = d[j]+len;
				}
			}
		}
	}

	//doing it for the nth time to check for negative cycles
	vector<int> incycle;
	vector<int> notcon;
	for(int j =0;j<n;j++){
		for(auto edges:adj[j]){
			int to =edges.first;
			long long int len = edges.second;
			if(d[j]!=INF && d[to]>d[j]+len){
				// d[to] = d[j]+len;
				incycle.push_back(j);
			}
		}
		vis2=vector<int> (n,0);
		if(!dfs2(s,j)){
			// d[j]=INF;
			notcon.push_back(j);
		}
	}

	for(auto e:incycle){
		// cout << e << endl;
		if(!vis[e])
			dfs(e);
	}
	vis = vector<int> (n,0);
	for(auto e:notcon){
		// cout << e << endl;
		if(!vis[e]){
			dfs3(e);
			// cout << e << endl;
		}
	}
	// cout << 0 << endl;
	for(int i =0;i<n;i++){
		if(d[i]==INF)
			cout << '*' << endl;
		else if(d[i]==-INF)
			cout << '-' << endl;
		else
			cout << d[i] << endl;
	}

}
