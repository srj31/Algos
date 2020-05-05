#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<vector<int> > adjr;
vector<int> vis;
vector<int> order_of_out;

void dfs1(int u){
	vis[u] = 1;
	for(auto v:adj[u])
		if(!vis[v])
			dfs1(v);

	order_of_out.push_back(u); // topo sort in reverse order
}

void dfs2(int u){
	vis[u] = 1;
	for(auto v:adjr[u])
		if(!vis[v])
			dfs2(v);
}
int main(){
	int n,m;
	cin >> n >> m;
	adj = vector<vector<int> > (n);
	adjr = vector<vector<int> > (n);
	vis = vector<int> (n,0);
	for(int i =0;i<m;i++){
		int u,v;
		cin >> u >> v;
		--u,--v;
		adj[u].push_back(v);
		adjr[v].push_back(u);
	}
	for(int i =0;i<n;i++){
		if(!vis[i])
			dfs1(i);
	}
	int comps = 0;
	vis.assign(n,0);
	for(int i=0;i<n;i++){
		int v = order_of_out[n-1-i];
		if(!vis[v]){
			dfs2(v);comps++;
		}
	}
	cout << comps << endl;
}