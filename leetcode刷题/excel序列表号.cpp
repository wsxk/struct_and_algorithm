class Solution {
public:
    int titleToNumber(string columnTitle) {
        int colunm=0;
        int n = columnTitle.size();
        for(int i=0;i<n;i++){
            int x = columnTitle[i] - 64;
            colunm = colunm*26+x;
        }
        return colunm;
    }
};