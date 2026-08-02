class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // we use dp here same as we used in maximum product subarray
        int mini=0;
        int maxi=0;
        int temp=0;
        int ans=*max_element(nums.begin(),nums.end());
        for(auto &x:nums){
            temp=maxi+x;
            maxi=max({mini+x,temp,x});
            mini=min({mini+x,temp,x});
            ans=max(ans,maxi);
        }
        return ans;
    }
};