struct edge{
	int u,v,w;
	bool operator<(edge const& next){
		return w<next.w;
	}
};


int n;
vector<edge> edges;


void find(int v){
	if(v==tree_id[v])
		return v;

	return tree_id[v] = find(tree_id[v]); 
}

void uni(int a,int b){
	a= find(a);
	b= find(b);
	if(size[a]>size[b]){
		swap(a,b);
	}
	tree_id[a]=b;
	size[b]+=size[a];
}

void kruskal(){
	int cost = 0;
	vector<int> tree_id(n);//DSU 
	vector<edge>res;
	for(int i =0;i<n;i++){ //initialization for the DSU
		tree_id[i]=i;
	}

	sort(edges.begin(),edges.end()); // will sort in terms of lowest weight

	for(edge e:edges){
		if(tree_id[e.u]!=tree_id[e.v]){
			//not in the same disjoint set
			cost+=e.weight;
			res.push_back(e);

			union(e.u , e.v);
		}

	}
}