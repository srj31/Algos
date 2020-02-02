const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s,vector<int>& d, vector<int>& p){
	int n = adj.size();
	d.assign(n,INF);
	p.assign(n,-1);
	vector<bool>u(n,false);

	set<pair<int,int> > q;
	q.insert({0,s});

	d[s] = 0;
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());

		for(auto edge: adj[v])
		{
			int to = edge.first;
			int dist = edge.second;
			if(d[v]+dist<d[to]){
				d[to] = d[v] + dist;
				p[to] = v;
				q.insert({d[to],to});
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