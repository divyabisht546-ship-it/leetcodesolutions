class Solution {
public:
const int mod =1e9+7;
    int numOfSubarrays(vector<int>& arr) {
    //   dekho even+odd =>odd haiiyaa
    //odd+even=odd
    //toh check for odd how much even you have previously and vice versa
    int even=1;
    int odd=0;
    int ans=0;
    long long count=0;
    int n=arr.size();
    vector<int>prefix(n);
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=arr[i]+prefix[i-1];
    }
    for(auto i:prefix){
        if(i%2==0){
            count+=odd;
            even++;
        }
        else {
            count+=even;
            odd++;
        }
    }
    return count%mod;
    }
};