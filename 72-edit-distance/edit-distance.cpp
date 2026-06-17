class Solution {
public:
int solve(int m,int n,vector<vector<int>>&dp,string word1,string word2){
    if(m==0){
        return n;
    }
    if(n==0){
        return m;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(word1[m-1]==word2[n-1]){
       return dp[m][n]=solve(m-1,n-1,dp,word1,word2);
    }
       return dp[m][n]=1+min({solve(m-1,n,dp,word1,word2),solve(m,n-1,dp,word1,word2),solve(m-1,n-1,dp,word1,word2)});
    
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,dp,word1,word2);
    }
};