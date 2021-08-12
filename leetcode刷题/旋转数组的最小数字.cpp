class Solution {
public:
    int minArray(vector<int>& numbers) {
        int minus = numbers[0];
        for(int &tmp:numbers){
            if(tmp<minus){
                minus = tmp;
                break;
            }
        }
        return minus;
    }
};