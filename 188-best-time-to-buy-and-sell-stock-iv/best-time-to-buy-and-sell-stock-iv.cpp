class Solution {
public:
int solve(int k,vector<int>&prices,int buy,int idx, vector<vector<vector<int>>>&dp){
    if(idx>=prices.size() || k==0) return 0;
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
    int include=0;
    int exclude=0;
    if(buy){
include=max(-prices[idx]+solve(k,prices,!buy,idx+1,dp),solve(k,prices,buy,idx+1,dp));
    }
    if(!buy){
        exclude=max(prices[idx]+solve(k-1,prices,!buy,idx+1,dp),solve(k,prices,buy,idx+1,dp));
    }
    return dp[idx][buy][k]=max(include,exclude);
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(k,prices,1,0,dp);
    }
};