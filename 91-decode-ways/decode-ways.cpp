class Solution {
public:
int solve(int idx,string s,unordered_map<string,char>&mp,vector<int>&dp){
    int sum=0;
    if(idx>=s.size()){
        return 1;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    if(mp.find(s.substr(idx,1))!=mp.end()){
        sum+=solve(idx+1,s,mp,dp);
    }
    if(mp.find(s.substr(idx,2))!=mp.end() && idx+1<s.size()){
        sum+=solve(idx+2,s,mp,dp);
    }
    return dp[idx]=sum;
}
    int numDecodings(string s) {
        unordered_map<string,char>mp;
        for(int i=1;i<=26;i++){
        mp[to_string(i)]=(i-1)+'a';
    }
    vector<int>dp(s.size(),-1);
    return solve(0,s,mp,dp);
    }
};