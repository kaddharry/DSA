class Solution {
public:
    string reverseWords(string s) {
        string word, result;
        istringstream iss(s);
        vector<string> words;

        while(iss >> word) words.push_back(word);

        for(int i = words.size()-1; i >= 0; i--){
            result += words[i] + ( i > 0 ? " ": "");
        }
        return result;
    }
};