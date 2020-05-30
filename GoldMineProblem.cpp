
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : 
*/


int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
 
    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
	    vector<vector<int>> a(n, vector<int>(m)), dp(n, vector<int>(m));

	    for (int i = 0; i < n; i++) 
	    	for (int j = 0; j < m; j++)
	    		cin >> a[i][j];
	 
	    for (int i = 0; i < n; i++)
	        dp[i][0] = a[i][0];
	    
	    int mx = -1;
	    for (int j = 0; j < m; j++) {
	    	for (int i = 0; i < n; i++) {
	    		
	    		if (j > 0)
	    			dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
	    		if (i > 0)
	    			 dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
	    		if (i < n - 1)
	    		     dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + a[i][j]);
	    	    
	    	    mx = max(mx, dp[i][j]);
	    	}
	    }      

	    cout << mx << endl;	

    }
    return 0;		
}	