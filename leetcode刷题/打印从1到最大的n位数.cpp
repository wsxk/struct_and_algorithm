class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> array;
        int sum= 1;
        while(n){
            sum *=10;
            n--;
        }
        for(int i=1;i<sum;i++){
            array.push_back(i);
        }
        return array;  
    }
};