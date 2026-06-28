class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);
        sort(arr.begin(),arr.end());
        if(arr[0]!=1){
        ans[0]=1;
        }
        else{
  ans[0]=arr[0];
        }
        if(arr.size()==1){
            return ans[0];
        }
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-ans[i-1])>1){
                ans[i]=ans[i-1]+1;
            }
            else{
                ans[i]=arr[i];
            }
        }
        int a=*max_element(ans.begin(),ans.end());
        return a;
    }
};