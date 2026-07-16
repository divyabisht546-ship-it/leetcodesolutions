class Solution {
public:
void solve(vector<int>&arr,multiset<int>&op,int idx,int k,int&count,int n){
if(idx>=n){
    if(!op.empty()){
        count++;
    }
    return;
}
if(op.empty()||op.find(arr[idx]+k)==op.end()&& op.find(arr[idx]-k)==op.end()){
op.insert(arr[idx]);
solve(arr,op,idx+1,k,count,n);
op.erase(op.find(arr[idx]));}
solve(arr,op,idx+1,k,count,n);
}
    int beautifulSubsets(vector<int>& nums, int k) {
        multiset<int>op;
        int n=nums.size();
        int count=0;
    solve(nums,op,0,k,count,n);
    return count;}
    };
    /*
    class Solution {
public:
    void solve(vector<int>& arr, set<int>& op, int idx, int k, int& count, int n) {
        if (idx >= n) {
            if (!op.empty()) {
                count++;
            }
            return;
        }

        // Choice 1: Element को शामिल करना (अगर सुंदर सबसेट की शर्त पूरी हो)
        // चूंकि ऐरे सॉर्टेड है, हमें सिर्फ पीछे वाला (arr[idx] - k) चेक करना है
        if (op.find(arr[idx] - k) == op.end()) {
            
            // यह चेक करने के लिए कि क्या यह नंबर पहले से सेट में है (डुप्लिकेट हैंडलिंग)
            bool alreadyPresent = (op.find(arr[idx]) != op.end());
            
            if (!alreadyPresent) {
                op.insert(arr[idx]);
            }

            solve(arr, op, idx + 1, k, count, n);

            // बैकट्रैक: सिर्फ तभी हटाओ जब इस स्टेप में खुद इन्सर्ट किया था
            if (!alreadyPresent) {
                op.erase(arr[idx]);
            }
        }

        // Choice 2: Element को शामिल न करना
        solve(arr, op, idx + 1, k, count, n);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        // 1. ऐरे को सॉर्ट करना सबसे ज़रूरी है
        sort(nums.begin(), nums.end());
        
        set<int> op;
        int n = nums.size();
        int count = 0;
        
        solve(nums, op, 0, k, count, n);
        return count;
    }
};*/