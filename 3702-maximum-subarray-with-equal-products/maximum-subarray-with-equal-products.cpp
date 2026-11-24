class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        //[2,3,4,5,6]
        int maxi=2;
        // gcd should bee 1 tabhi lcm hamara multiipication kee baare maii hogaa
        for(int i=0;i<n;i++){
             multiset<int>st;
            for(int j=i;j<n;j++)
            {
            int f=0;
      for(auto it=st.begin();it!=st.end();it++){
        if(gcd(*it,nums[j])>1){
            f=1;
            break;
        }
      }
      if(f) break;
      if(f==0)    maxi=max(maxi,j-i+1);
       st.insert(nums[j]);
        }
}
        return maxi;
    }
};

