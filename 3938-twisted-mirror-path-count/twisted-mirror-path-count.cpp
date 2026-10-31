class Solution {
public:
const int mod=1e9+7;
// d see ham log kaha se aaye haii uska track karenge
// d=0 ->right
// d=1 ->down see
int solve(int m,int n,int i,int j,int d,vector<vector<int>>& grid,vector<vector<int>>&dp){
    if(i<0 || i>=m || j<0||j>=n) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(grid[i][j]==1){
        if(d==0) return solve(m,n,i+1,j,1,grid,dp);
        else return solve(m,n,i,j+1,0,grid,dp);
    }
    long long right=solve(m,n,i,j+1,0,grid,dp);
    long long down=solve(m,n,i+1,j,1,grid,dp);
    return dp[i][j]=(down+right)%mod;
}
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,0,0,0,grid,dp);
    }
};