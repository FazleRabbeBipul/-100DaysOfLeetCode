class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
                int n = books.size();
        vector<int> dp(n + 1);

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            
            int W = books[i - 1][0], H = books[i - 1][1];
            dp[i] = dp[i - 1] + H;
        
            for (int j = i - 1; j > 0; --j) {
    
                W += books[j - 1][0];
              
                if (W > shelfWidth) {
                    break;
                }
              
                H = max(H, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + H);
            }
        }
      
        
        return dp[n];
    }
};