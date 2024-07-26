class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dis[it[0]][it[1]] = it[2];
			dis[it[1]][it[0]] = it[2];
		}

		for (int i = 0; i < n; i++) dis[i][i] = 0;
		
        for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dis[i][k] == INT_MAX || dis[k][j] == INT_MAX)
						continue;
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}

		int Mn = n;
		int pos = -1;
        
		for (int from = 0; from < n; from++) {
			int kt = 0;
			for (int to = 0; to < n; to++) {
				if (dis[from][to] <= distanceThreshold)
					kt++;
			}

			if (kt <= Mn) {
				Mn = kt;
				pos = from;
			}
		}
		return pos;
    }
};

// Floyd Warshall Algorithm