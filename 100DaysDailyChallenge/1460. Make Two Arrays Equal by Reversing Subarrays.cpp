class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
         map<int, int> mp;
        
        for(int e : target){
            mp[e]+=1;
        }
        
        for(int x : arr){
            if(mp.find(x) == mp.end()){
                return false;
            }
            mp[x]-=1;
            if(mp[x] == 0){
                mp.erase(x);
            }
        }
        
        return true;
    }
};