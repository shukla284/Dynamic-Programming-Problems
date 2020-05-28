
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Permuatation Coefficient
*/


int permutationCoefficient(int n, int k) {
    vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(k + 1));

    for (int i = 0; i <= n; i++) {
    	for (int j = 0; j <= k; j++) {
    		
    		if (i >= j){
    			if (j == 0)
    		    	dp[i][j] = 1;
    		    else
    		        dp[i][j] = dp[i - 1][j] + (j * dp[i - 1][j - 1]);	
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
    cout << permutationCoefficient(n, k) << endl;   
    
    return 0;		
}