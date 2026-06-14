class Solution {
public:
void solve(string x,string y,int m,int  n,vector<vector<int>>&dp){
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
}
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        solve(str1,str2,m,n,dp);
        string result="";
int i=m;
int j=n;
while(i>0 && j>0){
    if(str1[i-1]==str2[j-1]){
        result+=str1[i-1];
        i--;
        j--;
    }
    else{
        if(dp[i][j-1]<dp[i-1][j]){
            result+=str2[j-1];
            j--;
        }
        else{
            result+=str1[i-1];
            i--;
        }
    }
}
while(i>0){
    result+=str1[i-1];
    i--;
}
while(j>0){
    result+=str2[j-1];
    j--;
}
reverse(result.begin(),result.end());
return result;
    }
};