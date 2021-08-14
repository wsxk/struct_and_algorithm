class Solution {
public:
    string replaceSpace(string s) {
        int len = s.size();
        int count = 0;
        string ans(3*len,'\0');
        for(char &tmp:s){
            if(tmp==' '){
                ans[count++]='%';
                ans[count++]='2';
                ans[count++]='0';
            }else
                ans[count++]=tmp;
        }
        return ans;
    }
};