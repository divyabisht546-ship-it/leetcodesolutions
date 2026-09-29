class Solution {
public:
bool answer(int row,int col,vector<vector<char>>& grid,int m,int n,int ans1, vector<vector<vector<int>>>&dp){
    if(ans1<0) return false;
    if(dp[row][col][ans1]!=-1) return dp[row][col][ans1];
if(row==m-1 && col==n-1){
       return dp[row][col][ans1] = (ans1 == 0);
}
bool down=false;
bool right=false;
if(row+1<m){
    if(grid[row+1][col]=='(') down=answer(row+1,col,grid,m,n,ans1+1,dp);
    else down=answer(row+1,col,grid,m,n,ans1-1,dp);
}
if(col+1<n){
    if(grid[row][col+1]=='(') right=answer(row,col+1,grid,m,n,ans1+1,dp);
    else right=answer(row,col+1,grid,m,n,ans1-1,dp);
}
return dp[row][col][ans1]=down||right;
}
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // base case
        if(grid[0][0]==')') return false;
        if(grid[m-1][n-1]=='(') return false;
        // vector<vector<bool>> dp(m+1,vector<bool> dp(n+1,false));
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(m+n+1,-1)));
        // main logic
    return answer(0,0,grid,m,n,1,dp);
    }
};