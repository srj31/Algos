
const int mod = 1e9 + 7;

int inv[mxn],fact[mxn],ifact[mxn];

void pre() {
	fact[0] = fact[1] = inv[0] = inv[1] = ifact[0] = ifact[1];

	for(int i =2;i<mxn;i++){
		fact[i] = fact[i-1]*i%mod;
		inv[i] = mod - (mod/i)*inv[mod%i]%mod;
		ifact[i] = ifact[i-1]*inv[i]%mod;
	}
}

int ncr(int a, int b) {
	if(b>a)
		return 0;
	return (fact[a]*ifact[b]%mod)*ifact[a-b]%mod;
}