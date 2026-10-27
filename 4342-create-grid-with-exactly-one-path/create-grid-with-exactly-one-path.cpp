class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i=0;i<m-1;i++){
        string temp;
        temp.push_back('.');
        for(int i=0;i<n-1;i++){
            temp.push_back('#');
        }
        ans.push_back(temp);
}
        string temp;
for(int i=0;i<n;i++){
        temp.push_back('.');
    }
    ans.push_back(temp);
return ans;}
};