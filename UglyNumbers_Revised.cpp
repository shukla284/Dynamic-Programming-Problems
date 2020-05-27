
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Ugly Numbers
*/

int uglyNumber(int n) {
	vector<uint64_t> dp(n), ptr(3, 0), curr(3), prime({2, 3, 5});

	//Since with initial number all the numbers will be at 1 multiple (2,3,5)
	// This is single state dp in which the nth number can be determined using the minimum 
	// of the values of the ugly numbers and multiplication with the primes.,

	// dp[i] = min(dp[i3] * 3, dp[i2] * 2, dp[i5] * 5)
	dp[0] = 1;
   
	for (int i = 1; i < n; i++){
       
       uint64_t mn = -1;
       for (int j = 0; j < 3; j++) 
         curr[j] = dp[ptr[j]] * prime[j], mn = min(curr[j], mn);
        
       dp[i] = mn;

       for (int j = 0; j < 3; j++)
       	   if (curr[j] == mn)
       	   	   ptr[j]++;
	}
	return dp[n - 1];
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    cout << uglyNumber(n) << endl;   
    
    return 0;		
}