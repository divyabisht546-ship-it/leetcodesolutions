class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char,int>uni;
        unordered_map<string,int>mp;
        string str="";
        int n=s.size();
        int j=0;
        int i=0;
         int maxi=0;
        while(j<n){
            str+=s[j];
            uni[s[j]]++;
            if(str.size()>minSize){
                uni[s[i]]--;
                if(uni[s[i]]==0){
                    uni.erase(s[i]);
                }
                i++;
                str=str.substr(1);
            }
            j++;
            if(str.size()==minSize && str.size()<=maxSize){
                if(uni.size()<=maxLetters){
                    mp[str]++;
maxi=max(maxi,mp[str]);
                }
            }
        }
        return maxi;
    }
};