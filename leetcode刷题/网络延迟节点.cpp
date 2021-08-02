class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT_MAX/2;
        vector<vector<int>> g(n,vector<int>(n,inf));
        for(auto &t:times){
            g[t[0]-1][t[1]-1]=t[2];
        }
        vector<int> dist(n,inf);
        vector<int> used(n,0);
        dist[k-1]=0;
        for(int i=0;i<n;i++){
            int y;
            int x=-1;
            for(y=0;y<n;y++){
                if(!used[y]&&(x==-1||dist[y]<dist[x]))
                    x=y;
            }
            used[x]=1;
            for(y=0;y<n;y++){
                dist[y] = min(dist[y],dist[x]+g[x][y]);
            }
        }
        int ret = *max_element(dist.begin(),dist.end());
        return ret == inf? -1:ret;
    }
};