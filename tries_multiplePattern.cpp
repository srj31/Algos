#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
	// int idx;
	bool isEnd;
	TrieNode* children[26];

	TrieNode(){
		isEnd= false;
		for(int i =0;i<26;i++)
			children[i] = NULL;
	}
};
// int num = 0;
TrieNode* root = new TrieNode();
int main(){
	// root->idx = 0;
	string t;
	cin >> t;
	int n;
	cin >> n;
	string pats[n];
	for(int i =0;i<n;i++)
		cin >> pats[i];
	
	// building the Trie for patterns
	for(int i =0;i<n;i++){
		TrieNode* cur = root;
		for(int j =0;j<pats[i].length();j++){
			int c = pats[i][j] -'A';
			if(cur->children[c] == NULL){
				// cur->idx = ++num;
				cur->children[c] = new TrieNode();
			}
			cur = cur->children[c];
		}
		cur->isEnd = true;
	}

	for(int i =0;i<t.length();i++){
		TrieNode* cur = root;
		int pos = i;
		int c = t[pos]-'A';
		if(cur->children[c]==NULL){
			continue;
		}
		while(pos<t.length() &&(cur->children[c]!=NULL && cur->isEnd==false)){
			cur = cur->children[c];
			pos++;
			c = t[pos]-'A';
		}
		if(cur->isEnd)
			cout << i << " ";
	}
	cout << endl;

}