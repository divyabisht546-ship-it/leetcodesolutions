class Solution {
public:
//
    long long minArraySum(vector<int>& nums) {
        long long sum=0;
        int mx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        vector<bool>present(mx+1,false);
        for(int i=0;i<n;i++){
            present[nums[i]]=true;
        }
        for(int x:nums){
            int mini=x;
            for(int d=1;d*d<=x;d++){
                if(x%d==0){
                if(present[d]){
                    mini=min(mini,d);
                }
                else if(present[x/d]){
                    mini=min(mini,x/d);
                }
            }}
            sum+=mini;
        }
        return sum;
    }
};