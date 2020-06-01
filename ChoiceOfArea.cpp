
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Choice of area
*/


map<pair<int,int>, int> dp;

int maxSurvival(pair<int,int> init, vector<pair<int,int>>& area, int idx) {

	if (init.first <= 0 || init.second <= 0)
		 return 0;
    
    if (dp.find(init) != dp.end())
    	 return dp[init];

	int mx = -1;
	for (int i = 0; i < 3; i++)
	   if (i != idx) 
         mx = max(mx, maxSurvival(make_pair(init.first + area[i].first, init.second + area[i].second), area, i) );
    
    dp[init] = 1 + mx;
    
	return dp[init];  
}

int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    pair<int, int> init; cin >> init.first >> init.second;
    vector<pair<int,int>> area(3);

    for (int i = 0; i < 3; i++)
    	cin >> area[i].first >> area[i].second;

    cout << maxSurvival(init, area, -1) - 1 << endl;
    return 0;		
}