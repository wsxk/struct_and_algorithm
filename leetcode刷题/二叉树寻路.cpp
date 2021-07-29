class Solution {
public:
    int reverse_(int label,int row){
        return (1<<(row-1))+(1<<row)-1-label;
    }
    vector<int> pathInZigZagTree(int label) {
        int row=1,row_start=1;
        while(2*row_start<=label){
            row++;
            row_start*=2;
        }
        vector<int> path;
        if(row%2==0){
            label = reverse_(label,row);
        }
        while(row>0){
            if(row%2==0){
                path.push_back(reverse_(label,row));
            }else{
                path.push_back(label);
            }
            label>>=1;
            row--;
        }
        reverse(path.begin(),path.end());
        return path;
    }
};