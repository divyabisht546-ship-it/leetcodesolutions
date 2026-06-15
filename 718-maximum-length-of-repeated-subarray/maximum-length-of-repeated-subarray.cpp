class Solution {
public:
int solve(string s1,string s2,int m,int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        string s1="";
        string s2="";
        for(int i:nums1){
            s1+=i;
        }
        for(int j:nums2){
            s2+=j;
        }
        int m=s1.size();
        int n=s2.size();
        return solve(s1,s2,m,n);
    }
};