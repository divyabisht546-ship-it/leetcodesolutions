class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        long long ans=0,currsum=0;
        long long lp=0;
        int n=nums.size();
        mp[0]=1;
for(int i=0;i<n;i++){
            if(nums[i]==target){
lp+=mp[currsum];
currsum++;
            }
            else{
                currsum--;
                lp-=mp[currsum];
            }
            mp[currsum]++;
            ans+=lp;
        }
        return ans;
    }
};