class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        istringstream iss(s);
        while (iss >> word) {
            words.push_back(word);
        }
        
        if (words.size() != pattern.length()) return false;

        unordered_map<char, string> mp;
        unordered_set<string> seenValues; // Tracks values that are already taken

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string currentWord = words[i];

            // Scenario 1: The key has not been mapped yet
            if (!mp.count(c)) {
                // BUG FIX: Check if another key already took this exact value
                if (seenValues.count(currentWord)) {
                    return false; // Value is not unique!
                }
                mp[c] = currentWord;
                seenValues.insert(currentWord); // Mark value as taken
            } 
            // Scenario 2: The key already exists, verify it matches perfectly
            else if (mp[c] != currentWord) {
                return false; 
            }
        }
        return true;
    }
};