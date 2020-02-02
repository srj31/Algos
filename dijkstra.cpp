const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s,vector<int>& d, vector<int>& p){
	int n = adj.size();
	d.assign(n,INF);
	p.assign(n,-1);
	vector<bool>u(n,false);

	d[s] = 0;
	for(int i =0;i<n;i++){
		int v = -1;
		for(int j=0;j<n;j++){
			if(!u[j]&&(v==-1||d[j]<d[v]))
				v=j;
		}	

		if(d[v]==INF)
			break;

		u[v] = true;
		for(auto edge:adj[v]){
			int to = edge.first;
			int dist = edge.second;

			if(d[v]+dist<d[to]){
				d[to] = d[v]+dist;
				p[to] = v;
			}
		}
	}
}


vector<int> restore(int s, int t, vector<int> p){
	vector<int> path;

	for(i=t;i!=s;i=p[i]){
		path.push_back(i);
	}

	path.push_back(s);
	reverse(path.begin(),path.end());
	return path;
}