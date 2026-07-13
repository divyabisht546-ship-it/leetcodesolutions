class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
    string str="123456789";
    vector<int>ans2;
    string s=to_string(low);
    string e=to_string(high);
    int lsize=s.size();
    int rsize=e.size();
    vector<int>ans;
    while(lsize<=rsize){
        int size=lsize;
        int i=0;
        int j=0;
        while(j<str.size()){
            if(j-i+1==size){
                string p=str.substr(i,size);
                int num=stoi(p);
                ans.push_back(num);
                i++;
            }
            j++;
        }
        lsize++;
    }
    for(int i=0;i<ans.size();i++){
        if(low<=ans[i] && ans[i]<=high){
           ans2.push_back(ans[i]);
        }
    }
    return ans2;
    }
};