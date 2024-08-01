class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0; 
        for (const auto& d : details) {
            int age = stoi(d.substr(11, 2));
            cnt += (age > 60) ? 1 : 0;
        }
        return cnt;
    }
};