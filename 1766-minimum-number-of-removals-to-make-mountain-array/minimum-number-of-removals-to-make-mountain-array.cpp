class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        //we craete an array of lis,lds so we can doo O(1) operation
        vector<int>lis(n,1);
        vector<int>lds(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
         for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    lds[i]=max(lds[i],lds[j]+1);
                }
            }
        }
        int maxi=1;
        for(int i=0;i<n;i++){
            if(lis[i]>1 && lds[i]>1){
      maxi=max(lis[i]+lds[i]-1,maxi);
            }
            
        }
        return n-maxi;
    }
};