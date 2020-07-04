#include<bits/stdc++.h>
using namespace std;


int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
// debugging ends here


struct TrieNode{
	int idx;
	bool isEnd;
	TrieNode* children[27];
	int start,length;

	TrieNode(){
		isEnd = false;
		start = length = 0;
		for(int i =0;i<27;i++)
			children[i] = NULL; 
	}
};

TrieNode* root = new TrieNode();
int num = 0;
int main(){

	string t;
	cin >> t;
	int n =t.length();
	root->length = n-1;
	function<void(TrieNode*)> dfs = [&](TrieNode* u){
        // if(u->isEnd)
        //     return;

        for(int i =0;i<27;i++)
        {   
            if(u->children[i]!=NULL){
                dfs(u->children[i]);
                cout << u->idx << " " << u->children[i]->idx << endl;
                for(int j =u->children[i]->start;j<u->children[i]->start + u->children[i]->length;j++)
                	cout << t[j];
                cout << endl;
            }
        }
    };

	// cout << root->length << endl;
	for(int i =0;i<n;i++){
		TrieNode* cur = root;
		int j =i;
		// cout << j << endl;
		while(j<n){
			int c;
			if(t[j]!='$')
				c = t[j] -'A';
			else
				c = 26;
			if(cur->children[c]==NULL){
				cur->children[c] = new TrieNode();
				cur->children[c]->idx = ++num;
				cur->children[c]->start = j;
				if(cur->idx == 0){
					cur->children[c]->length = (n-i);
					cur->children[c]->isEnd = true;
					// cur->length -= cur->children[c]->length;
				}
				else{
					cur->children[c]->length = (n-j);
					cur->children[c]->isEnd = true;
					// cur->length -= cur->children[c]->length;
				}
				
				break;
			}
			else{
				// keep on going until theres a troble
				int cnt = 1;
				int l = cur->children[c]->length;
				
				int c1;
				for(int k =0;k<l;k++){
					if(t[j]==t[cur->children[c]->start+k])
						j++;
					// if(j)
					else{
						// need to create two nodes now
						// dbg(j);
						c1 = 26;
						if(t[cur->children[c]->start+k]!='$')
							c1 = t[cur->children[c]->start+k]-'A';
						cur= cur->children[c];
						// cout << "add"<< endl;
						cur->children[c1] = new TrieNode();
						cur->children[c1]->start = cur->start+k;
						cur->children[c1]->idx = ++num;
						cur->children[c1]->length = (cur->length-(cur->start+k));
						cur->length -= cur->children[c1]->length;
					
						cur->children[c1]->isEnd = true;

						// cnt=-1;
						break;
					}
				}
				// if(cnt!=-1 && cur->children[c1]!=NULL)
				// 	cur = cur->children[c1];
			}
		}
		cout << i << " current start" << endl;
		dfs(root);
	}
	// function<void(TrieNode*)> dfs = [&](TrieNode* u){
 //        // if(u->isEnd)
 //        //     return;

 //        for(int i =0;i<27;i++)
 //        {   
 //            if(u->children[i]!=NULL){
 //                dfs(u->children[i]);
 //                cout << u->idx << " " << u->children[i]->idx << endl;
 //                for(int j =u->children[i]->start;j<u->children[i]->start + u->children[i]->length;j++)
 //                	cout << t[j];
 //                cout << endl;
 //            }
 //        }
 //    };
 //    dfs(root);
}