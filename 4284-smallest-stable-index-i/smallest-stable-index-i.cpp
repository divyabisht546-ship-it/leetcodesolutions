class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int maxi=*max_element(nums.begin(),nums.begin()+i+1);
            int mini=*min_element(nums.begin()+i,nums.end());
            ans.push_back(maxi-mini);
        }
        for(int j=0;j<n;j++){
            if(ans[j]<=k){
                return j;
            }
        }
        return -1;
    }
};