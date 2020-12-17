
vector<int> par;
// works for trees using dfs

//for graohs need to use bfs 
pair<int,int> dfs(int u,int p =-1,int d=0){
	pair<int,int> res = make_pair(d,u);
	for(auto child:adj[u]){
		if(child==p)continue;
		par[child] = u;
		res = max(res,dfs(v,u,d+1));
	}
	return res;
}

int main(){
	//input for the graph ;
	pair<int,int> da = dfs(0);
	pair<int,int> db= dfs(da,second);
	//da and db are the end points of the diameter
}