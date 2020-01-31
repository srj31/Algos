int n;
vector<vector<int > > graph;

vector<bool> visited;
vector<int> low;
vector<int> tin;

int timer;

int dfs(int s,int p=-1){
	visited[s] = true;
	tin[s] = low[s] = timer++;

	for(int child: graph[s]){
		if(child==p) continue;

		if(visited[child])
			low[s] = min(low[s],tin[child]);
		else{
			dfs(child,s);
			low[s] = min(low[s],low[child]);
			if(low[to]>tin[s])
				//it is a bridge
		}
	}
}


void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

