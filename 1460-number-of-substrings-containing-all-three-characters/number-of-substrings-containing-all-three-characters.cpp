class Solution {
public:
bool is(vector<int>freq){
    return freq[0]>0 && freq[1]>0 && freq[2]>0;
}
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>freq(3,0);
        int i=0;
        int j=0;
        int total=0;
        while(j<n){
           freq[s[j]-'a']++;
           while(is(freq)){
           total+=n-j;
           freq[s[i]-'a']--;
           i++;
           }
           j++;
        }
        return total;
    }
};