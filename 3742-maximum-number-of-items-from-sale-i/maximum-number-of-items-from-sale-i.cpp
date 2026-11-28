// // RECURSION
// class Solution {
// public:
// int solve(int idx,vector<vector<int>>&arr,unordered_map<int,int>&mp,int budget,bool taken,int n){
// if(idx>=n) return 0;
// int take=INT_MIN;
// if(budget-arr[idx][1]>=0){
//     if(!taken){
//         take=mp[idx]+1+solve(idx,arr,mp,budget-arr[idx][1],true,n);
//     }
//     else take=1+solve(idx,arr,mp,budget-arr[idx][1],true,n);
// }
// int skip=solve(idx+1,arr,mp,budget,false,n);
// return max(take,skip);
// }
//     int maximumSaleItems(vector<vector<int>>& items, int budget) {
//         // recursion -(take and skip)
//         unordered_map<int,int>mp;
//         int n=items.size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(i!=j && (items[j][0] % items[i][0]==0)) mp[i]++;
//             }
//         }
//       return  solve(0, items,mp,budget,false,n);
//     }
// };
// optimised approach- think of 0/1 knapsack+greedy

class Solution {
public:
int solve(int n,vector<vector<int>>& items,int budget, vector<vector<int>>&dp,unordered_map<int,int>&mp,int cheapest){
if(n==0) return budget/cheapest;
if(dp[n][budget]!=-1) return dp[n][budget];
int take=INT_MIN;
if(budget-items[n-1][1]>=0){
    take=1+mp[n-1]+solve(n-1,items,budget-items[n-1][1],dp,mp,cheapest);
}
int skip=solve(n-1,items,budget,dp,mp,cheapest);
return dp[n][budget]=max(take,skip);
}
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
    int n=items.size();
    vector<vector<int>>dp(n+1,vector<int>(budget+1,-1));
    int cheapest_item=INT_MAX;

//     // map waala idea
             unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
               if(i!=j && (items[j][0] % items[i][0]==0)) mp[i]++;
           }
           cheapest_item=min(cheapest_item,items[i][1]);
      }
       return solve(n,items,budget,dp,mp, cheapest_item);
    }
};