class Solution {
public:
int solve(int r,int c,int m,int n, vector<vector<int>>&dp,vector<vector<int>>&arr){
    if(r>=m || c>=n) return INT_MAX;
    if(dp[r][c]!=INT_MIN){
        return dp[r][c];
    }
    if(r==m-1 && c==n-1){
        if(arr[r][c]>0) return 1;
        else return abs(arr[r][c])+1;
    }
int right=solve(r+1,c,m,n,dp,arr);
int down=solve(r,c+1,m,n,dp,arr);
int result=min(right,down)-arr[r][c];
return dp[r][c]=(result>0)? result:1;
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MIN));
        
        return solve(0,0,m,n,dp, dungeon);
    }
};