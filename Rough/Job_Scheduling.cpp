#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int findJobs(vector <vector<int>> &arr, int time, int i, vector <vector<int>> &dp){
	
    if(i>=arr.size())
		return 0;

    if(dp[i][time]!=-1)
        return dp[i][time];

	if(arr[i][2]+time>arr[i][0])
        return dp[i+1][time]=findJobs(arr, time, i+1, dp);

	int included_reward, excluded_reward;
	
    included_reward = arr[i][1]+findJobs(arr, time+arr[i][2], i+1, dp);
	excluded_reward = findJobs(arr, time,i+1, dp);

	return dp[i][time] = max(included_reward, excluded_reward);
}

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
		vector <vector<int>> dp(1005, vector<int>(1005, -1));
		vector <vector<int>> arr(n, vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        }
		sort(arr.begin(), arr.end());
		cout<<findJobs(arr, 0, 0, dp)<<"\n";
	}
	return 0;
}