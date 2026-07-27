class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totalxor=0;
        for(int n:nums){
            totalxor^=n;
        }
        int first=0;
        int second=0;
        int bitsno=0;
while(((totalxor>>bitsno)&1)!=1){
    bitsno++;
}
        for(int i:nums){
            if((i>>bitsno)&1==1){
                first^=i;
            }
            else{
                second^=i;
            }
        }
return {first,second};
    }
};