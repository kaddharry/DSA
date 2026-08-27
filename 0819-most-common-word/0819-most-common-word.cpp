class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // 1. Convert banned words to a set for O(1) lookups
        unordered_set<string> st(banned.begin(), banned.end());
        
        // 2. Pre-process the paragraph: clean punctuation and normalize case
        for (char &c : paragraph) {
            if (ispunct(c)) {
                c = ' '; // Replace punctuation with spaces to avoid joining words
            } else {
                c = tolower(c); // Lowercase everything since match is case-insensitive
            }
        }
        
        // 3. Extract pure words using stringstream
        unordered_map<string, int> freq;
        stringstream ss(paragraph);
        string word;
        int maxFreq = 0;
        string res;
        
        while (ss >> word) {
            // Check if the word is not banned
            if (!st.count(word)) {
                freq[word]++;
                if (maxFreq < freq[word]) {
                    maxFreq = freq[word];
                    res = word;
                }
            }
        }
        
        return res;
    }
};
