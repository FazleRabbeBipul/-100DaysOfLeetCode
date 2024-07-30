class Solution {
public:
    int minimumDeletions(string s) {
        int dlt = 0, b = 0;       
        
        for (char& c : s) {
            if (c == 'b') {
                b++;
            } else {
                dlt = min(dlt + 1, b);
            }
        }

        return dlt;
    }
};