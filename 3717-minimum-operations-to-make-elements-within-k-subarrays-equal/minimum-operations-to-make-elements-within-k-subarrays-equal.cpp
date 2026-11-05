class Solution {
public:
long long solve(long long i,long long taken,int x,int k,vector<long long>&cost,  vector<vector<long long>>&dp,int n){
if(taken==k) return 0;
long long remaining=k-taken;
long long elements= remaining*x;
int lastindex=i+elements-1;
if(lastindex>=n) return 1e16;
if(dp[i][taken]!=-1) return dp[i][taken];
long long take=cost[i]+solve(i+x,taken+1,x,k,cost,dp,n);
return dp[i][taken]=min(take,solve(i+1,taken,x,k,cost,dp,n));
}
    long long minOperations(vector<int>& nums, int x, int k) {
        // the solution written by mee
        // concepts used= dp why dp ->choices
        // median  to find effeciently the cost; lagaritmic time
        // sliding window to slide it in 0(n)
        // finding median 
        int n=nums.size();
        vector<long long>cost(n-x+1);
        int i=0;
        int j=0;
        multiset<int>left,right;
        long long leftsum=0;
        long long rightsum=0;
        while(j<nums.size()){
            if(left.size()<=right.size()){
                left.insert(nums[j]);
                leftsum+=nums[j];
            }
            else{
            right.insert(nums[j]);
            rightsum+=nums[j];}
            // balancing
            if(!left.empty() && !right.empty()){
                int maxleft=*left.rbegin();
                int minright=*right.begin();
                if(maxleft>minright){
                    // we can't swap directly we have to place
                    left.erase(left.find(maxleft));
                     right.erase(right.find(minright));
                     left.insert(minright);
                     right.insert(maxleft);
                    leftsum+=minright-maxleft;
                   rightsum+=maxleft-minright;
                }
            }
            // check if we found it
            if(j-i+1==x){
                int median=*left.rbegin();
                long long leftop=left.size()*median-leftsum;
                long long rightop=rightsum-right.size()*median;
                cost[i]=leftop+rightop;
                if(left.find(nums[i])!=left.end()){
                    leftsum-=nums[i];
                    left.erase(left.find(nums[i]));
                }
                else{
                    rightsum-=nums[i];
                    right.erase(right.find(nums[i]));
                }
                i++;
            }
            j++;
        }
        vector<vector<long long>>dp(nums.size(),vector<long long>(k+1,-1));
        return solve(0,0,x,k,cost,dp,n);
    }
};