class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int wait) {
        
        vector< vector<int> > g (n + 1);
        for (const vector<int>& edg : edges) {
            int u = edg[0];
            int v = edg[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

      
        queue< pair<int, int> > Q;
        Q.push({1, 0}); 
        vector<vector<int>> dist(n + 1, vector<int>(2, INT_MAX));

        dist[1][0] = 0; 

  
        while (!Q.empty()) {
            pair< int, int > x = Q.front();
            Q.pop();

            int u = x.first;
            int cost = x.second;

            for (int v : g[u]) {
                if (cost + 1 < dist[v][0]) {
                    dist[v][1] = dist[v][0];
                    dist[v][0] = cost + 1;    
                    Q.push({v, cost + 1});
                }
                else if (dist[v][0] < cost + 1 && cost + 1 < dist[v][1]) {
                    dist[v][1] = cost + 1;
                    Q.push({v, cost + 1});
                }
            }
        }

        int tot = 0;
        for (int i = 0; i < dist[n][1]; ++i) {
            tot += time;
            if (i < dist[n][1] - 1   &&   (tot / wait) % 2 == 1) {
                tot += wait - (tot % wait);
            }
        }

        return tot;
    
    }
};

