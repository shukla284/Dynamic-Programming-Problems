
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Maximum Obtainable price cutting rod
*/

int maxObtainable(vector<pair<int,int>>& a, vector<int>& dp, int n) {
	if (n <= 0)
		 return 0;

    if (dp[n] != -1)
    	 return dp[n];

	int mx = 0;
	for (int i = 0; i < a.size(); i++) 
		if (a[i].first <= n)
			mx = max(mx, maxObtainable(a, dp, n - a[i].first) + a[i].second);
	
	dp[n] = mx;
	return dp[n];
}

int maxObtainable(vector<pair<int,int>>& a, int n) {
	vector<int> dp(n + 1, 0); dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {

    	dp[i] = 0;
    	for (int j = 0; j < a.size(); j++)
    		 if (a[j].first <= i)
    		 	 dp[i] = max(dp[i], dp[i - a[j].first] + a[j].second);
    }
    return dp[n];
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n, val; cin >> n >> val;
    vector<pair<int,int>> a(val);

    for (int i = 0; i < n; i++)
    	cin >> a[i].first >> a[i].second;
    
    vector<int> dp(n + 1, -1);
    cout << maxObtainable(a, n) << endl;
    return 0;		
}