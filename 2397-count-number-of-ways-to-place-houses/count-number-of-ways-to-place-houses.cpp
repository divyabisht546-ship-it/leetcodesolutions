class Solution {
public:
int mod=1e9+7;
int solve(int n,int idx,vector<int>&dp){
    if(idx>=n) return 1;
    if(dp[idx]!=-1) return dp[idx];
    int take=solve(n,idx+2,dp);
    int skip=solve(n,idx+1,dp);
    return dp[idx]=(take+skip)%mod;
}
    int countHousePlacements(int n) {
        vector<int>dp(n,-1);
        int oneside=solve(n,0,dp);
        int ans=(1LL*oneside*oneside)%mod;
        return ans;
    }
};