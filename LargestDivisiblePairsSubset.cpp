
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Largest Pair Divisible Subset
*/

int largestDivisibleSubset(vector<int>& a) {
	sort(a.begin(), a.end());
    int mx = -1;

	vector<int> dp(a.size());

	dp[0] = 1;
	for (int i = 1; i < a.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[i] % a[j] == 0)
				dp[i] = max(dp[i], dp[j] + 1);	
        mx = max(mx, dp[i]);
	}
    return mx;
} 

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
       cin >> a[i];

    cout << largestDivisibleSubset(a) << endl;
    return 0;		
}