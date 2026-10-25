class Solution {
public:
// ismee hamnee 4 variables liyee haii bass
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        if(matrix.empty())
        return {};
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0;
        int left=0;
        int right=m-1;
        int down=n-1;
        while(top<=down && right>=left){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int j=top;j<=down;j++){
                ans.push_back(matrix[j][right]);
            }
            right--;
            if(down>=top){
            for(int k=right;k>=left;k--){
                ans.push_back(matrix[down][k]);
            }}
            down--;
            if(right>=left){
            for(int k=down;k>=top;k--){
                ans.push_back(matrix[k][left]);
            }
            left++;}
        }
        return ans;
    }
};