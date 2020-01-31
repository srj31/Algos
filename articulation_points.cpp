int n;
vector<vector<int> > graph;


vector<bool> visited;
vector<int> tin,low; 
int timer; 
void dfs(int v, int p = -1){
	visited[v] = true;
	tin[v] = low[v] = timer++;
	int children = 0;
	for(int child:graph[v]){
		if(child==p) continue;
		if(visited[child])
			low[v] = min(low[v],tin[child]);
		else{
			dfs(child,v);
			low[v] = min(low[v],low[child]);
			if(low[child]>=tin[v]&&p!=-1)
				//it is an articulation point
			children++;
		}
	}

	if(p==-1 && children>1)
		//articulation point
}