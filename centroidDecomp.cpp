#include <bits/stdc++.h>
const int mxn = 2e5;

int size[mxn],par[mxn];// size --> subtree size ,,, par --> parent of nodes in the centroid decomposition
set<int> adj[mxn]; // set used since removal of edges is required 


void dfs1(int u ,int p){ // storing the subtree sizes
	size[u] = 1;
	for(auto v:adj[u]){
		if(v==p)continue;
		dfs1(v,u);
		size[u]+=size[v];
	}
}

int dfs2(int u , int p, int n){ // finding the centroid of the tree

	for(int v : adj[u]){
		if(v == p) continue;
		if(size[v]>n/2)
			return dfs2(v,u,n);
	}
	return u;
}

void decompose(int u , int p){
	dfs1(u,-1);
	int subTreeSize = size[u];

	int centroid = dfs2(u,p,subTreeSize);

	par[centroid] = p;
	for(auto v: adj[u]){
		adj[v].erase(centroid), decompose(v, centroid); 
	}
}

int main(){
	
}