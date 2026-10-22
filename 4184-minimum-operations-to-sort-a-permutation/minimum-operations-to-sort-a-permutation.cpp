class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n=nums.size();
       if(is_sorted(nums.begin(),nums.end())) return 0;
       int asc_count=0;
       int dsc_count=0;
       for(int i=1;i<n;i++){
        if(nums[i]==(nums[i-1]+1)%n){
            asc_count++;
        }
         if(nums[i-1]==(nums[i]+1)%n){
           dsc_count++;
        }
       }
       if(asc_count==n-1){
       int left=n-nums[0];
       int right=nums.back()+3;
return min(left,right);
       }
       if(dsc_count==n-1){
        if((nums[0]+1)%n==0) return 1;
        int left=n-nums.back()+1;
        int right=nums[0]+2;
        return min(left,right);
       }
return -1;
    }
};