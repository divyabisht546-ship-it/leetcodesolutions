class Solution {
public:
int solve(string&s,string&t,int i,int j,int dp[1001][1001]){
 if(j==t.size()) return 1;
    if(i>=s.size()) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int include=0;
   if(s[i]==t[j]){
    include=solve(s,t,i+1,j+1,dp);
   }
    int exclude=solve(s,t,i+1,j,dp);
    return dp[i][j]=include+exclude;
}
    int numDistinct(string s, string t) {
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
return solve(s,t,0,0,dp);
    }
};