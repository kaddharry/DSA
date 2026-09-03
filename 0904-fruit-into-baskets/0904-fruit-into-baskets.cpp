class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> lastSeen;

        int start = 0;
        int res = 0;

        for (int i = 0; i < fruits.size(); i++) {

            lastSeen[fruits[i]] = i;

            if (lastSeen.size() > 2) {

                // Find the type whose last occurrence is earliest
                int oldestType = fruits[i];
                int oldestIndex = i;

                for (auto& p : lastSeen) {
                    if (p.second < oldestIndex) {
                        oldestIndex = p.second;
                        oldestType = p.first;
                    }
                }

                // Remove everything before/including its last occurrence
                start = oldestIndex + 1;
                lastSeen.erase(oldestType);
            }

            res = max(res, i - start + 1);
        }

        return res;
    }
};