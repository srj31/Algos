#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	// int idx;
	TreeNode* lnode;
	TreeNode* rnode;
	int key;
	TreeNode(){
		lnode = rnode = NULL;
	}
};

// TreeNode* root = new TreeNode();

int main(){
	int n;
	cin >> n;
	TreeNode* nodes[n];
	vector<int> ans;
	if(n==0){
		cout << "CORRECT" << endl;
		return 0;
	}
	for(int i =0;i<n;i++)
		nodes[i] = new TreeNode();
	for(int i =0;i<n;i++){
		cin >> nodes[i]->key;
		ans.push_back(nodes[i]->key);
		int l,r;
		cin >> l >> r;
		if(l!=-1){
			nodes[i]->lnode = nodes[l];
		}
		
		if(r!=-1)
			nodes[i]->rnode = nodes[r];
	}
	sort(ans.begin(),ans.end());
	vector<int> check;
	function<void(TreeNode* )> in = [&](TreeNode* u){
		if(u->lnode!=NULL && u->lnode->key < u->key)
			in(u->lnode);
		check.push_back(u->key);
		if(u->rnode!=NULL && u->rnode->key>=u->key)
			in(u->rnode);
	};
	// function<void(TreeNode* )> pre = [&](TreeNode* u){
	// 	cout << u->key << " ";
	// 	if(u->lnode!=NULL)
	// 		pre(u->lnode);
	// 	if(u->rnode!=NULL)
	// 		pre(u->rnode);
	// };
	// function<void(TreeNode* )> post = [&](TreeNode* u){
	// 	if(u->lnode!=NULL)
	// 		post(u->lnode);
	// 	if(u->rnode!=NULL)
	// 		post(u->rnode);
	// 	cout << u->key << " ";
	// };
	in(nodes[0]);
	if(ans!=check){
		cout << "INCORRECT" << endl;
	}
	else
		cout << "CORRECT" << endl;
	// pre(nodes[0]);cout << endl;
	// post(nodes[0]);cout << endl;
}