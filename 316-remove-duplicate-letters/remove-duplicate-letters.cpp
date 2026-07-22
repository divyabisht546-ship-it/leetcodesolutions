class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<bool>available(26,false);
        vector<int>last(26,0);
        string temp;
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
for(int i=0;i<n;i++){
    if(available[s[i]-'a']){
        continue;
    }
    while(!temp.empty() && s[i]<temp.back() && last[temp.back()-'a']>i){
                    available[temp.back()-'a']=false;
            temp.pop_back();
        }
    temp.push_back(s[i]);
    available[temp.back()-'a']=true;
}
return temp;
    }
};