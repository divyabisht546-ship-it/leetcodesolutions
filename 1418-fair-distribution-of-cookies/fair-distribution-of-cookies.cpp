class Solution {
public:
int mini=INT_MAX;
void solve(vector<int>&cookies,int k,int idx,vector<int>&children){
    if(idx>=cookies.size()){
        int maxi=*max_element(children.begin(),children.end());
        mini=min(mini,maxi);
        return;
    }
    int cookie=cookies[idx];
    for(int j=0;j<k;j++){
    children[j]+=cookie;
    solve(cookies,k,idx+1,children);
    children[j]-=cookie;
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>children(k);
        solve(cookies,k,0,children);
        return mini;
    }
};