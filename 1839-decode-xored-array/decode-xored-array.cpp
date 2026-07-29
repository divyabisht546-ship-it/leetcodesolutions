class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        vector<int>arr(n+1);
        arr[0]=first; //1
        for(int i=1;i<n+1;i++){
            arr[i]=arr[i-1]^encoded[i-1];
        }
        return arr;
    }
};