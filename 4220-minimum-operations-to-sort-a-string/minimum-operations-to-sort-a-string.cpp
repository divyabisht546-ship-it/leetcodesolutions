class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
    if(is_sorted(s.begin(),s.end())){
        return 0;
    }
    if(n==2) return -1;
    int mn=*min_element(s.begin(),s.end());
    int mx=*max_element(s.begin(),s.end());
    if(mn==s[0]||mx==s[n-1]) return 1;
    if(mx==s[0] && mn==s[n-1] && count(s.begin(),s.end(),mx)==1 && count(s.begin(),s.end(),mn)==1) return 3;
    return 2;
    }
};