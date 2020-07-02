#include<bits/stdc++.h>
using namespace std;


struct TrieNode{
    int idx;
    bool isEnd;
    TrieNode* children[26];

    TrieNode(){
        for(int i =0;i<26;i++)
            children[i] = NULL;
        isEnd = false;
    }
};


int no_vertx=0;
TrieNode* make_node(){
    TrieNode* res = new TrieNode();
    for(int i =0;i<26;i++)
        res->children[i] = NULL;
    res->isEnd= false;
    return res;
}

TrieNode* root = new TrieNode();
int main(){
    int n;
    cin >> n;
    root->idx  = 0;
    string pats[n];
    for(int i =0;i<n;i++)
        cin >> pats[i];

    for(int i =0;i<n;i++){
        TrieNode* cur= root;
        for(int j = 0;j<pats[i].length();j++){
            if(cur->children[pats[i][j]-'A']==NULL){
                cur->children[pats[i][j]-'A'] = new TrieNode();
                cur = cur->children[pats[i][j]-'A'];
                cur->idx = ++no_vertx;
            }
            else
                cur = cur->children[pats[i][j]-'A'];

        }
        cur->isEnd = true;
    }

    function<void(TrieNode*)> dfs = [&](TrieNode* u){
        if(u->isEnd)
            return;

        for(int i =0;i<26;i++)
        {   
            if(u->children[i]!=NULL){
                dfs(u->children[i]);
                cout << u->idx << "->" << u->children[i]->idx << ":" << char('A' + i) << endl;
            }
        }
    };
    dfs(root);
}