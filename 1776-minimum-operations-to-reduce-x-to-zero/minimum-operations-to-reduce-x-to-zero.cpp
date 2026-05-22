class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target=accumulate(nums.begin(),nums.end(),0);
        target=target-x;
        int n=nums.size();
        if(target==0){
            return n;
        }
        int sum=0;
        int j=0;
        
        int maxi=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(j<i && sum>target){
                sum-=nums[j];
                j++;
            }
            if(sum==target){
                maxi=max(maxi,i-j+1);
            }
        }
        if(maxi==0){
            return -1;
        }
        return n-maxi;
    }
};