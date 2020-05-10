
#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

const long long int modi = 1e9+7;

long long int** mul(long long int **mat1,long long int **mat2){
    lli** ans = 0;
    ans = new lli*[2];
    for(int i =0;i<2;i++){
        ans[i] = new lli[2];
        for(int j =0;j<2;j++){
            ans[i][j] = mat1[i][0]*mat2[0][j]%modi + mat1[i][1]*mat2[1][j]%modi;
            ans[i][j]%=modi;
        }
    }

    return ans;
}

void disp(lli ** mat){
    for(int i =0;i<2;i++){
        for(int j =0;j<2;j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
}

lli ** matrixmul(long long int ** mat,lli ** c,long long int n){
    while(n>0){
        if(n&1){
            mat = mul(mat,c);
        }
        c = mul(c,c);
        n>>=1;
        // cout << "mat" << endl;
        // disp(mat);
        // // cout << "c" << endl;
        // disp(c);

    }
    return mat;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n,m;
        cin >> n >> m;
        if(n==1){
            cout << m%modi << endl;continue;
        }
        long long int dp[2];
        dp[0] = m%modi;
        dp[1] = 0;
        lli ** mat = new lli*[2];
        mat[0] = new lli[2];
        mat[1] = new lli[2];
        mat[0][0] =1 ,mat[0][1] = 0;
        mat[1][0] = 0, mat[1][1] = 1;
        lli ** c = new lli*[2];
        c[0] = new lli[2];
        c[1] = new lli[2];
        c[0][0] = c[0][1] = (m-1)%modi;
        c[1][0] = 1, c[1][1] = 0;
        // disp(mat);

        mat = matrixmul(mat,c,n-1);
        // disp(mat);

        lli ans = (mat[0][0]%modi)*dp[0]%modi + (mat[1][0]%modi)*dp[0]%modi;
        ans%=modi;
        cout << ans << endl;
    }
}
