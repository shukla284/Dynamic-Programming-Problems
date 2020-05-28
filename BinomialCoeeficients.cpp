
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Binomial Coeefficients
*/

int binomialCoefficient(int n, int k) {
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
		   if (i >= j) {
	           if (i == 0 || j == 0 || i == j)
	              dp[i][j] = 1;
	          
	           else 
	              dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];        
           }	
		}
	}	
    
    return dp[n][k];
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, k; cin >> n >> k;
    cout << binomialCoefficient(n, k) << endl;
    
    return 0;		
}