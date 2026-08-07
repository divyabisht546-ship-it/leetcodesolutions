class Solution {
public:
int solve(vector<vector<char>>& matrix,vector<vector<int>>&dp,int m,int n){
    int maxside=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        if(matrix[i][j]=='1'){
            if(i==0||j==0){
                dp[i][j]=1;

            }
                    else{
            dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
        }
          maxside=max(maxside,dp[i][j]);
        }
        else{
            dp[i][j]=0;
        }
        }
    }
    return maxside*maxside;
}
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(matrix,dp,m,n);
    }
};