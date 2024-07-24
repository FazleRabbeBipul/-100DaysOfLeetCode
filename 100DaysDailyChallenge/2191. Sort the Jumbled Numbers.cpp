

bool SortBy(const pair<int,int> &a, const pair<int,int> &b) {
        if(a.second == b.second)
            return a.first < b.first;
        else
            return (a.second < b.second);
}


class Solution {
   
public:

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> vec;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int x = nums[i], y = 0, p = 1;
        
            if(x == 0){
                y = mapping[0];
            }
            else{
                while(x){
                    int ind = x % 10;
                    y += mapping[ind] * p;
                    p *= 10, x /= 10;
                }
            }

            vec.push_back({i, y});
        }
        sort(vec.begin(), vec.end(), SortBy);
        vector<int>ans;

        for(int i = 0; i < n; i++){
           int x = nums[vec[i].first];
           ans.push_back(x);
        }

        return ans;
    }

    
};