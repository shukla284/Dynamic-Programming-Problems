
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Subset Sum Problem
*/

bool existSum(vector<int>& a, int m) {
	vector<vector<bool>> dp(m + 1, vector<bool>(a.size() + 1, false));
    
    for (int i = 0; i <= a.size(); i++)
    	dp[0][i] = true;
    for(int i = 1; i <= m; i++)
    	dp[i][0] = false;

    for (int i = 1; i <= m; i++) {
    	for (int j = 1; j <= a.size(); j++)  {
 			dp[i][j] = dp[i][j - 1];
 			if (i >= a[j - 1])
 				 dp[i][j] = dp[i][j] || dp[i - a[j - 1]][j - 1];
    	}
    }
    return dp[m][a.size()];
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int t; cin >> t;
    while (t--){
    	int n, m; cin >> n >;
        vector<int> a(n); 
        for (int i = 0; i < n; i++)
           cin >> a[i];
    
        cout << existSum(a, m) << endl;
    }
    return 0;		
}