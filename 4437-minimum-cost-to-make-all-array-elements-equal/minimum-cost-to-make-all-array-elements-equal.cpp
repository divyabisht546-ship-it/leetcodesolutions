/*class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        //creating prefix array
        vector<int>prefix(n);
        prefix[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
            else prefix[i]=0;
        }
        //creating suffix array
        vector<int>suffix(n);
        suffix[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==nums[i+1]){
                suffix[i]=suffix[i+1]+1;
            }
            else suffix[i]=0;
        }
        //check
        // take maximum value index of both prefix and suffix
        int max_prefix_index=0;
        int prefix_value=prefix[0];
        int suffix_value=suffix[0];
        int max_suffix_index=0;
        // for prefix check from starting
        for(int j=1;j<n-1;j++){
        if(prefix_value<prefix[j]){
             max_prefix_index=j;
prefix_value=prefix[j];
        }
        }
        // for suffix check from last
        for(int j=n-1;j>=1;j--){
            if(suffix_value<suffix[j]){
                max_suffix_index=j;
                suffix_value=suffix[j];
            }
        }
        // now finally answer
long long ans=INT_MAX;
        if(abs(max_prefix_index-prefix_value)==0) {
        ans=min(ans,1LL*(n-max_prefix_index-1)*prefix_value);}
        if(abs(max_suffix_index+suffix_value)==n-1){
            ans=min(ans,1LL*max_suffix_index*suffix_value);
        }
      int index=abs(max_prefix_index-prefix_value);
      long long total=(n-max_prefix_index-1)*prefix_value;
      ans=min(ans,index*prefix_value+total);

        return ans;
    }
};*/
class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        // Creating prefix array
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = 0;
        }

        // Creating suffix array
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == nums[i + 1])
                suffix[i] = suffix[i + 1] + 1;
            else
                suffix[i] = 0;
        }

        long long ans = LLONG_MAX;

        // Checking every possible pivot
        for (int i = 1; i < n - 1; i++) {

            long long left = i - prefix[i];
            long long right = i + suffix[i];

            // Cost of making all elements equal to nums[i]
            long long cost =
                (left + (n - right - 1)) * 1LL * nums[i];

            ans = min(ans, cost);
        }

        return ans;
    }
};