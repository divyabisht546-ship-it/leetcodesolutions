class Solution {
public:
long long solve(vector<int>&arr,int idx,int buy, vector<vector<int>>&dp){
        if(idx>=arr.size()) return 0;
    if(dp[idx][buy]!=-1) return dp[idx][buy];
    long long include=0;
    long long exclude=0;
    if(buy){
include=max(-arr[idx]+solve(arr,idx+1,!buy,dp),solve(arr,idx+1,buy,dp));
    }
    if(!buy){
        exclude=max(arr[idx]+solve(arr,idx+2,!buy,dp),solve(arr,idx+1,buy,dp));

    }
    return dp[idx][buy]=max(include,exclude);
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return solve( prices,0,1,dp);
    }
};