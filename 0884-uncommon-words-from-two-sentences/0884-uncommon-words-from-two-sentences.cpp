class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream iss1(s1);
        istringstream iss2(s2);
        unordered_map<string, int> mp;
        string temp;
        while(iss1 >> temp){
            mp[temp]++;
        }
        while(iss2 >> temp){
            mp[temp]++;
        }
        vector<string> res;
        for(auto it: mp){
            if(it.second == 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};