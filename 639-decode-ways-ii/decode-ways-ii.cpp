class Solution {
public:
long long mod=1e9+7;
int solve(int n,vector<int>&dp,int i,string &s){
    if(i>=s.size()) return 1;
    if(dp[i]!=-1){
        return dp[i];
    }
    long long multi=1;
    long long result=0;
    if(s[i]=='0') return 0;
    if(s[i]=='*'){
        multi=9;
    }
    result+=multi*solve(n,dp,i+1,s);
    long long op=0;
    if(i<n-1){
        char next=s[i+1];
        if(s[i]=='*'){
            if(next=='*'){
                op=15;
            }
            else if(next<='6'){
                op=2;
            }
            else{
                op=1;
            }
        }
        else{
            if(next=='*'){
                if(s[i]<'3'){
                    if(s[i]=='2'){
                        op=6;
                    }
                    else if(s[i]=='1'){
                        op=9;
                    }
                }
            }
            else{
                if(stoi(s.substr(i,2))<=26){
                    op=1;
                }
            }
        }
        if(op){
        result+=op*solve(n,dp,i+2,s);}
    }
    return dp[i]=result%mod;
}
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(n,dp,0,s);
    }
};