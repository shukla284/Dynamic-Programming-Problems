
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Is Sum Modulo m exists (https://www.geeksforgeeks.org/subset-sum-divisible-m/)
*/

bool isSumModuloExists(vector<int>& a, int m) {
    if (a.size() > m)
    	 return true;

	vector<int> dp(m, false);
	for (int i = 0; i < a.size(); i++) {
		if (dp[0])
			return true;
        
        vector<bool> temp(m, false);
        for (int j = 0; j < m; j++) 
        	if (dp[j] && !dp[(j + a[i]) % m])
        		 temp[(j + a[i]) % m] = true;
        
        for (int j = 0; j < m; j++)
        	 if (temp[(j + a[i]) % m]) 
        	 	dp[(j + a[i]) % m] = true;

        dp[a[i] % m] = true; 
  
	}

	return dp[0];
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, m; cin >> n >> m;   
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    	cin >> a[i];
    
    cout << (isSumModuloExists(a, m) ? "YES" : "NO" ) << endl;
    return 0;		
}