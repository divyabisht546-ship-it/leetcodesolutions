class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
     int odd=INT_MAX;
     for(int i:nums1){
        if(i%2!=0){
            odd=min(i,odd);
        }
     }
     if(odd==INT_MAX) return true;
  for(int x:nums1){
    if(x%2==0){
        if(x<odd) return  false;
    }
  }
  return true;
    }
};