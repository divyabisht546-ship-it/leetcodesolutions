class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // 2 3 4 5
        reverse(nums.begin(),nums.end()); // 5 4 3 2
        int ans=(nums[0]-1)*(nums[1]-1); //4 3
        return ans;
    }
};