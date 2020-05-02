int n;
vector<int> adj[mxN];
const inf = 1e9;

struct edge{
	int weight= inf,to=-1;
}

//for dense graphs O(n^2)

void prim(){
	int total_weight = 0;
	vector<bool>sel(n,false);
	vector<edge> min_edge(n);
	min_edge[0].w =0;

	forn(i,0,n){
		int v=-1;
		forn(j,0,n){
			if(!sel[j]&&(v==-1||min_edge[j].w<min_edge[v].w))
				v=j;
		}

		if(min_edge[v]==INF){
			cout << "ERROR NO MST" << endl;return;
		}

		sel[v]=true;
		total_weight+=min_edge[v].w;
		if(min_edge[v].to!=-1){
			//v and to are the edges in the MST
		}

		for(int i=0;i<n;i++){
			if(adj[v][i]<min_edge[i].w){
				min_edge[i].w = {adj[v][i] , v};
			}
		}

	}
	cout << total_weight << endl;
}


// for sparse graphs

struct edge{
	int w=INF,to = -1;

	bool operator<(edge const& next) const{
		return make_pair(w,to) < make_pair(other.w,other.to);
	}
}
vector<vector<edge> > adj;
void prim2(){
	int total_weight = 0;
    vector<edge> min_e(n); // the edge that starts from node i to some selected node with min weight
    min_e[0].w = 0;
    set<edge> q; // the minimum edges that have only one of the nodes selected 
    q.insert({0, 0});
    vector<bool> selected(n, false);
    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
        	cout << "ERROR NO MST" << endl;return;
		}													

        int v = q.begin()->to; // the next node to be added
        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (edge e : adj[v]) {
            if (!selected[e.to] && e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        }
    }

    cout << total_weight << endl;
}