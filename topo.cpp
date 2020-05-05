#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> vis;
vector<int> topo;

void dfs(int u){
	vis[u]= 1;
	for(auto v:adj[u])
		if(!vis[v])
			dfs(v);

	topo.push_back(u);
}

int main(){
	int n,m;
	cin >> n >> m;
	adj=vector<vector<int> > (n);
	vis = vector<int> (n,0);
	for(int i =0;i<m;i++){
		int u,v;cin >> u >> v;--u,--v;
		adj[u].push_back(v);
	}

	for(int i =0;i<n;i++){
		if(!vis[i])
			dfs(i);
	}
	reverse(topo.begin(),topo.end());
	for(auto e:topo)
	{
		cout << e+1 << " ";
	}cout << endl;
}