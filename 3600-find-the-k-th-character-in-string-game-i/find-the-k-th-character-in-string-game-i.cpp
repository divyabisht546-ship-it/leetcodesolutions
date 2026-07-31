class Solution {
public:
    char kthCharacter(int k) {
        string suf="a";
        int length=0;
        while(suf.size()<k){
            string temp;
            for(char ch:suf){
                if(ch=='z'){
                    temp+='a';
                }
                else{
                    temp+=(ch+1);
                }
            }
            suf+=temp;
        }
        return suf[k-1];
    }
};