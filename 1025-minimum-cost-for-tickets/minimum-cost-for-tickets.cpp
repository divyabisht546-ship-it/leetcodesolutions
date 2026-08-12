class Solution {
public:
int solve(vector<int>&days,vector<int>&costs,int i,int day,vector<vector<int>>&dp){
    if(i>=days.size()) return 0;
    if(dp[i][day]!=-1) return dp[i][day];
if(day>days[i]){
    return dp[i][day]=solve(days,costs,i+1,day,dp);
}
int one=costs[0]+solve(days,costs,i+1,days[i]+1,dp);
int two=costs[1]+solve(days,costs,i+1,days[i]+7,dp);
int three=costs[2]+solve(days,costs,i+1,days[i]+30,dp);
return dp[i][day]= min({one,two,three});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int maxi=*max_element(days.begin(),days.end());
        vector<vector<int>>dp(n+1,vector<int>(maxi+31,-1));
        return solve(days,costs,0,1,dp);
    }
};