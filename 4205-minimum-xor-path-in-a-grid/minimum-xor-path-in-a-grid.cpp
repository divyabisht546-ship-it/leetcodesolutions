class Solution {
public:
bool isvalid(int r,int c,int m,int n){
    if(r>=m||c>=n||r<0||c<0) return false;
    return true;
}
int solve(vector<vector<int>>&arr,int i,int j,int m,int n,vector<vector<vector<int>>>&dp,int ans){
    if(dp[i][j][ans]!=-1) return dp[i][j][ans];
    if(i==m-1 && j==n-1){
        return dp[i][j][ans]=arr[i][j]^ans;
    }
        int res=INT_MAX;
    if(isvalid(i+1,j,m,n)){
       res=min(solve(arr,i+1,j,m,n,dp,ans^arr[i][j]),res);
    }
    if(isvalid(i,j+1,m,n)){
       res=min(solve(arr,i,j+1,m,n,dp,ans^arr[i][j]),res);
    }
     return dp[i][j][ans]=res;

}
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(1024,-1)));
     return solve(grid,0,0,m,n,dp,0);  
    }
};