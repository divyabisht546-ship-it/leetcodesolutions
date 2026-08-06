class Solution {
public:
int solve(vector<int>&nums,int target,int n,vector<int>&dp,int i){
    if(i>=(n-1)) return 0;
    if(dp[i]!=INT_MIN) return dp[i];
    long long take=-1;
    for(int j=i+1;j<n;j++){
        long long next=solve(nums,target,n,dp,j); // if it gives us negative can't doo anything
        if(next!=-1){
    if(abs(nums[j]-nums[i])<=target){
        take=max(take,1+next);
    }
    }}
    return dp[i]=take;
}
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
    vector<int>dp(n,INT_MIN);
       int ans=solve(nums,target,n,dp,0);
       return ans;
    }
};