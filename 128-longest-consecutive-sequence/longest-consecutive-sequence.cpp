class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=1;
        // 1 2 3 4 100 200
        // 1 2 6 7 8
        if(nums.size()==0) return 0;
       set<int>st(nums.begin(),nums.end());
       vector<int>arr(st.begin(),st.end());
       int count=1;
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i]==arr[i-1]+1){
count++;
  ans=max(ans,count); //2
        }
        else count=1;
    }
       return ans;
    }
};