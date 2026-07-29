class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
     int n=encoded.size();
     vector<int>ans(n+1);
     int totalxor=0;
     int odd=0;
     int a=0;
     for(int i=1;i<=n+1;i++){
      totalxor^=i;
     }
     for(int i=1;i<encoded.size();i+=2){
        odd^=encoded[i];
     }
     a=odd^totalxor;
     ans[0]=a;
     for(int i=1;i<n+1;i++){
        ans[i]=ans[i-1]^encoded[i-1];
     }
     return ans;
    }
};