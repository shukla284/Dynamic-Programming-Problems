
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Coin Change Ways
*/

uint64_t numberOfWays(vector<int>& a, int m) {
	vector<vector<int>> dp(m + 1, vector<int>(a.size() + 1));
	for (int i = 0; i <= a.size(); i++)
	    dp[0][i] = 1;

	for (int i = 1; i <= m; i++)
	    dp[i][0] = 0;
    
    for (int i = 1; i <= m; i++) {
    	for (int j = 1; j <= a.size(); j++){

    	  dp[i][j] = dp[i][j - 1];	
    	  if (i >= a[j - 1])	
    			dp[i][j] += dp[i - a[j - 1]][j];
    	}
    }
    return dp[m][a.size()];
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    
    int t; cin >> t;
    while (t--) {
    	int n, m; cin >> n;
        vector<int> coin(n);
        for (int i = 0; i < n; i++)
            cin >> coin[i];   

        cin >> m;
        
        cout << numberOfWays(coin, m) << endl;
    }
    return 0;		
}