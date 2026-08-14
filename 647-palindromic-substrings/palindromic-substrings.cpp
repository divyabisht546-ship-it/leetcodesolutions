class Solution {
public:
bool solve(int l,int r,vector<vector<int>>&dp,string s){
    if(l>=r) return 1;
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    if(s[l]==s[r]){
        return dp[l][r]=solve(l+1,r-1,dp,s);
    }
    return dp[l][r]=0;
}
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
            if(solve(i,j,dp,s)){
                count++;
            }
            }
        }
        return count;
    }
};