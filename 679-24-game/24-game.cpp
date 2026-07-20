class Solution {
public:
const double eplison=1e-6;
vector<double>check(double a,double b){
    vector<double>res;
    res.push_back(a+b);
    res.push_back(a*b);
      res.push_back(a-b);
    res.push_back(b-a);
    if(fabs(b)>eplison){
        res.push_back(a/b);
    }
        if(fabs(a)>eplison){
        res.push_back(b/a);
    }
    return res;
}

bool dfs(vector<double>&nums){
    if(nums.size()==1){
        return fabs(nums[0]-24)<eplison;
    }
    for(int i=0;i<nums.size();i++){
for(int j=0;j<nums.size();j++){
    if(i==j){
        continue;
    }
    vector<double>temp;
    for(int k=0;k<nums.size();k++){
        if(k!=i && k!=j){
temp.push_back(nums[k]);
        }
    }
   double a=nums[i];
    double b=nums[j];
    for(double num:check(a,b)){
        temp.push_back(num);
        if(dfs(temp)){
            return true;
        }
        temp.pop_back();
    }
}
    }
    return false;
}
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums;
        for(int n:cards){
            nums.push_back((double)n);
        }
       return dfs(nums);
    }
};