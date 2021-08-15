class Solution {
private:
    int get_sum(int a,int b){
        int sum = 0;
        while(a||b){
            sum += a%10;
            a /= 10;
            sum += b%10;
            b /=10;
        }
        return sum;
    }
public:
    int movingCount(int m, int n, int k) {
        if(!k)
            return 1;
        queue<pair<int,int>> q;
        vector<vector<int>>graph(m,vector<int>(n,0));
        int dx[2] = {1,0};
        int dy[2] = {0,1};
        int count=1;
        q.push(make_pair(0,0));
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0;i<2;i++){
                int tx = x+dx[i];
                int ty = y+dy[i];
                if(tx<0||tx>=m||ty<0||ty>=n||get_sum(tx,ty)>k||graph[tx][ty])
                    continue;
                q.push(make_pair(tx,ty));
                count++;
                graph[tx][ty]=1;
            }
        }
        return count;
    }
    
};