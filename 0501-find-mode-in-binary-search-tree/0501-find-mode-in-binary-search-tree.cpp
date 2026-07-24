class Solution {
public:
    void helper(TreeNode* root, vector<int>& in) {
        if (!root) return;

        helper(root->left, in);
        in.push_back(root->val);
        helper(root->right, in);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> in;
        helper(root, in);

        vector<int> res;

        int maxFreq = 0;
        int count = 1;

        for (int i = 0; i < in.size(); i++) {

            // Same value as previous
            if (i > 0 && in[i] == in[i - 1]) {
                count++;
            }
            // New value starts
            else {
                count = 1;
            }

            if (count > maxFreq) {
                maxFreq = count;
                res.clear();
                res.push_back(in[i]);
            }
            else if (count == maxFreq) {
                res.push_back(in[i]);
            }
        }

        return res;
    }
};