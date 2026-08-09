class Solution {
public:
int solve(vector<vector<int>>&matrix,int r,int c,vector<vector<int>>&dp,int n){
    if(r<0||c<0||r>=n||c>=n) return INT_MAX;
     if(dp[r][c]!=INT_MIN) return dp[r][c];
    if(r==n-1)    return matrix[r][c];
    int oneoption=solve(matrix,r+1,c-1,dp,n);
    int twooption=solve(matrix,r+1,c,dp,n); 
    int threeoption=solve(matrix,r+1,c+1,dp,n);
    return dp[r][c]=matrix[r][c]+min({oneoption,twooption,threeoption});
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
ans=min(ans,solve(matrix,0,i,dp,n));
        }
        return ans;
    }
};