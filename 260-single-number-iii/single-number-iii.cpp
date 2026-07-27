class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // 1 1  2 2 3 5
    int i=0;
    int n=nums.size(); //6
    vector<int>ans;
   while(i<n-1){ //5
    if(nums[i]!=nums[i+1]){
ans.push_back(nums[i]);
i++;
    }
    else{
        i=i+2;
    }
   }
   if(nums[n-1]!=nums[n-2]){
  ans.push_back(nums[n-1]);
   }
   return ans;
    }
};