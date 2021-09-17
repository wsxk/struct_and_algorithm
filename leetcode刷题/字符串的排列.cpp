class Solution {
public:    
    vector<string> res;
    vector<int> visit;
    
    void backtrack(const string &s,int i,int n,string &perm){
        if(i==n){
            res.push_back(perm);
            return;
        }
        for(int j=0;j<n;j++){
            if(visit[j]||(j>0&&!visit[j-1]&&s[j-1]==s[j]))
                continue;
            visit[j]=true;
            perm.push_back(s[j]);
            backtrack(s,i+1,n,perm);
            perm.pop_back();
            visit[j]=false;
        }
    }
    
    vector<string> permutation(string s) {
        int n = s.size();
        sort(s.begin(),s.end());
        visit.resize(n);
        string perm;


        backtrack(s,0,n,perm);
        return res;
    }   
};