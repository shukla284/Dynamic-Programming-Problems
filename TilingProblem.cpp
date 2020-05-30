
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Tilling Problem
*/


int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);


    int t; cin >> t;

    while (t--) {
    	int n; cin >> n;
	    vector<int> dp(n + 1);
	    dp[0] = 1, dp[1] =1;
	    
	    for (int i = 2; i <= n; i++)
	    	dp[i] = dp[i - 1] + dp[i - 2];

	    cout << dp[n] << endl;
    }
    return 0;		
}