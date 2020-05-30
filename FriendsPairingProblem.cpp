
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Friends Pairing Problem
*/

int pairFriends(int n) {
	vector<uint64_t> dp(n + 1);
	dp[0] = dp[1] = 1;
    
    const int MOD = 1e9 + 7;
	for (int i = 2; i <= n; i++)
		 dp[i] = ((dp[i - 1] % MOD) + ((i - 1) * dp[i - 2]) % MOD) % MOD;

	return dp[n];	
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    
    int t; cin >> t;
    while (t--) {
    	int n; cin >> n;
        cout << pairFriends(n) << endl;  
    }
     
    return 0;		
}