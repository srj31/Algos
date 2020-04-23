int n;
vector<int> a(n);



// building the required array
int len = (int)sqrt(n + .0) + 1; // size of sqrt(n) adn also length of b vector
vector<int> b(len);

for(int i =0;i<n;i++){
	b[i/len]+=a[i];
}

while(q--){
	int l,int r;
	cin >> l >> r;
	int ans = 0;
	for(int i=l;i<=r;){
		if(i%len==0 && i+len - 1<=r ){
			// the whole sqrt block lies inside the given range;
			ans+=b[i/len];
			i+=len;
		}
		else{
			sum+=a[i];
			i++;
		}

	}
}
