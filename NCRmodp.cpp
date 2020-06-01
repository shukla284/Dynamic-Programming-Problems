
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : nCr mod p 
*/

int C(int n, int r, int p) {

	if (r > n) 
		return 1;

	r = min(r, (n - r));

	vector<vector<int>> dp(n + 1, vector<int>(r + 1));
     
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= r; i++)
        dp[0][i] = 0;     

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) 
			 	 dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p;
	}
	return dp[n][r] % p;
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, r, p; cin >> n >> r >> p;  
    cout << C(n, r, p) << endl;

    return 0;		
}