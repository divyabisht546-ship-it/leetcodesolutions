class Solution {
public:
int solve(int m,int n,int r,int c,vector<vector<int>>& grid, vector<vector<int>>&dp){
    int right=INT_MAX;
    int down=INT_MAX;
    if(r==m-1 && c==n-1){
return grid[r][c];
    }
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    if(r+1<m){
       down=grid[r][c]+solve(m,n,r+1,c,grid,dp);
    }
    if(c+1<n){
       right=grid[r][c]+solve(m,n,r,c+1,grid,dp);
    }
    return dp[r][c]=min(right,down);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return solve(m,n,0,0,grid,dp);
    }
};