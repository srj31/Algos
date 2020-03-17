#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5;
const int inf = 1e9;


struct edge{
	int u,v,w;
};

int n,m,start,end;
vector<edge> edges;

void solve(){

	vector<int> d(n,INF);	
	d[start] = 0;


// to make it more efficient if no changes can be made in the current iteration then 
//break out of the loop.
	for(int i =0;i<n-1;i++){
		for(auto e:edges){
			d[e.v] = min(d[e.v],d[e.u]+e.w);
		}
	}

	//to get the path use a parent vector and every time you reduce an edge 
	//make the current vertex the parent in p'	

	//if it was run for n iterations and in the nth iteration it still changes then 
	// there is a negative cycle in the graph
}