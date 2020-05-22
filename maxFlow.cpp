#include<bits/stdc++.h>
using namespace std;

struct Tedge{
	int from,to,cap,fl;

};


Tedge make_edge(int u,int v,int c,int f){
	Tedge res;
	res.from = u;
	res.to =v;
	res.cap = c;
	res.fl= f;
	return res;
}
vector<Tedge> edges;
vector<vector<int> > adj;

const int INF = 1e5;

int aug(int s, int t, vector<int> &par){
	fill(par.begin(),par.end(),-1);
	int n = par.size();
	par[s] = -2;
	queue<pair<int,int > > q;
	q.push(make_pair(s,INF));
	while(!q.empty()){
		int cur = q.front().first;
		int flow = q.front().second;
		// cout << cur << " cur " << flow << " flow " << endl;
		q.pop();

		for(int idx: adj[cur]){
			// cout << idx << " idxes of the edges" << endl;
			Tedge edge = edges[idx];
			int to = edge.to;
			// cout << to << " to " << " edge cap " << edge.cap << " flow " << edge.fl << endl; 
			if(par[to]==-1 && edge.cap - edge.fl >0)
			{
				par[to] = idx;
				int new_flow = min(flow,edge.cap - edge.fl);
				if(to == t)
					return new_flow;
				q.push(make_pair(to,new_flow));
			}
		}
	}
	return 0;
}

void dis(Tedge a){
	cout << a.from << " " << a.to << " " << a.cap << " " << a.fl << endl; 
}

int main(){
	int t;
	cin >> t;
	while(t--){
		edges.clear();
		int n,m;
		cin >> n >> m;
		adj = vector<vector<int> > (n);
		for(int i =0;i<m;i++){
			int u,v,c;
			cin >> u >> v >> c;
			--u,--v;
			edges.push_back(make_edge(u,v,c,0));
			edges.push_back(make_edge(v,u,0,0));
			adj[u].push_back(2*i);
			adj[v].push_back(2*i+1);

		}
		// cout << "THE edges are: " << endl;
		// for(int i =0;i<m;i++){
		// 	dis(edges[i<<1]);
		// 	dis(edges[i<<1|1]);
		// }
		int s = 0;
		int t = n-1;

		int max_flow = 0;

		vector<int> par(n); // store the index of the edge used

		int inc;
		while((inc = aug(s,t,par))){
			int cur = t;
			max_flow += inc;
			while(cur!=s){
				Tedge e1 = edges[par[cur]];
				Tedge e2 = edges[par[cur]^1];
				// cout << cur << " ";
				e1.fl += inc;
				edges[par[cur]] = e1;
				e2.fl -= inc;
				edges[par[cur]^1] = e2;
				cur = e1.from;
			}
			// cout << endl;
		}
		cout << max_flow << endl;
	}
}