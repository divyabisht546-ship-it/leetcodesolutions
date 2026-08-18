class Solution {
public:
int solve(vector<vector<int>>&arr,int i, vector<vector<int>>&dp,int pre){
    int include=0;
    if(i>=arr.size()) return 0;
    if(dp[i][pre+1]!=-1) return dp[i][pre+1];
    if(pre==-1||arr[pre][1]<arr[i][0]){
        include=1+solve(arr,i+1,dp,i);
    }
    int exclude=solve(arr,i+1,dp,pre);
    return dp[i][pre+1]=max(include,exclude);
}
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
    sort(pairs.begin(),pairs.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solve(pairs,0,dp,-1);
    }
};