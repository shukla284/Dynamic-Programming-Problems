
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Subset Sum
*/

bool isPartitionPossible(vector<int>& a) {
	int sum = accumulate(a.begin(), a.end(), 0);
	if (sum & 1)
		 return false;
    
	vector<vector<int>> dp((sum >> 1) + 1, vector<int>(a.size() + 1));

	for (int i = 0; i <= a.size(); i++) 
		dp[0][i] = true;
	
	for (int i = 1; i <= (sum >> 1); i++)
		dp[i][0] = false;
	
	    
	for (int i = 1; i <= (sum >> 1); i++) {
		for (int j = 1; j <= a.size(); j++){
			dp[i][j] = dp[i][j - 1];

			if (i >= a[j - 1])
				dp[i][j] = dp[i][j] || dp[i - a[j - 1]][j - 1];
		}
	}
	return dp[(sum >> 1)][a.size()];
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    
    int t; cin >> t;

    while (t--) {
	    int n; cin >> n;
	    vector<int> a(n); 
	    for (int i = 0; i < n; i++)
	       cin >> a[i];   
	     
	    cout << (isPartitionPossible(a) ? "YES" : "NO") << endl;
    }
    
    return 0;		
}