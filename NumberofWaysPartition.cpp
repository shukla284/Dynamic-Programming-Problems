
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Number of ways to partition a set
*/

int numberOfWays(int n) {
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
            	 dp[i][j] = 0;
            else if (j == 1 || i == j)
                 dp[i][j] = 1;
            else
                 dp[i][j] = (j * dp[i - 1][j] + dp[i - 1][j - 1]);     	
		}
	}
	return accumulate(dp[n].begin(), dp[n].end(), 0);
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    cout << numberOfWays(n) << endl;   
    
    return 0;		
}