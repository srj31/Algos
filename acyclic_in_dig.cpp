#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> state;

bool dfs(int u){
	state[u] = 1;
	for(auto v:adj[u]){
		if(state[v]==1)
			return true;
		else if(state[v]==0){
			if(dfs(v))
				return true;
		}
	}
	state[u] = 2;
	return false;
}


int main(){
	int n,m;
	cin >> n >> m;
	adj=vector<vector<int> > (n);
	state = vector<int> (n,0);
	for(int i =0;i<m;i++){
		int u,v;
		cin >> u >> v;
		--u,--v;
		adj[u].push_back(v);
	}
	int pos = 0;
	for(int i =0;i<n;i++){
		if(state[i]==0){
			pos|=dfs(i);
		}
	}

	cout << pos << endl;
}