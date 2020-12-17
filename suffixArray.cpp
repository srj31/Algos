#include<bits/stdc++.h>
using namespace std;

vector<int> sorted_cyclic(string s){
	int n=s.size();
	int alpha = 256;
	vector<int> p(n),c(n),cnt(max(n,alpha),0); // the permutation, the classes, the count array
	for(int i =0;i<n;i++){
		cnt[s[i]]++;
	}
	for(int i =1;i<alpha;i++)
		cnt[i]+=cnt[i-1];
	for(int i =0;i<n;i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for(int i =1;i<n;i++)
	{
		if(s[p[i]]!=s[p[i-1]])
			classes++;
		c[p[i]] = classes-1;
	}

	vector<int> pn(n),cn(n); // temporary permutations and classes
	for(int h = 0;(1<<h)<n;h++){
		 for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
	} 
	return p;
}

int main(){
	string t;
	cin >> t;
	vector<int> sorted = sorted_cyclic(t);
	// sorted.erase(sorted.begin());
	for(auto e: sorted){
		cout << e << " ";
	}
	cout << endl;
}