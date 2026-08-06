class Solution {
public:
int solve(vector<vector<int>>& obstacleGrid,int m,int n,int r,int c,vector<vector<int>>&dp){
        if(r==m-1 && c==n-1 && obstacleGrid[r][c]==1) return 0;
    if(r==m-1 && c==n-1) return 1;

    if(dp[r][c]!=-1) return dp[r][c];
    int right=0;
    int down=0;
    if(r+1<m && obstacleGrid[r][c]!=1){
        right=solve(obstacleGrid,m,n,r+1,c,dp);
    }
      if(c+1<n && obstacleGrid[r][c]!=1){
        down=solve(obstacleGrid,m,n,r,c+1,dp);
    }
    return dp[r][c]=right+down;
    
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if( obstacleGrid.size()==1 &&obstacleGrid[0][0]==1 ) return 0;
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return solve(obstacleGrid,m,n,0,0,dp);

    }
};