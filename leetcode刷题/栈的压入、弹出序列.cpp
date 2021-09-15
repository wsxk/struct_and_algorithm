class Solution {
public
    bool validateStackSequences(vectorint& pushed, vectorint& popped) {
        if(pushed.size()==0)
            return true;
        stackint tmp;

        int len=pushed.size();
        int push_count=0;
        int pop_count=0;
        for(;push_countlen;push_count++){
            tmp.push(pushed[push_count]);
            while(!tmp.empty()&&popped[pop_count]==tmp.top()){
                tmp.pop();
                pop_count++;
            }
        }

        return tmp.empty();
    }
};