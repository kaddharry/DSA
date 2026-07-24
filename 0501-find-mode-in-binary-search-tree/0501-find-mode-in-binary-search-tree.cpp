class Solution {
public:
    TreeNode* prev = nullptr;
    int count = 0;
    int maxFreq = 0;
    vector<int> ans;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val == root->val)
            count++;
        else
            count = 1;

        if (count > maxFreq) {
            maxFreq = count;
            ans.clear();
            ans.push_back(root->val);
        }
        else if (count == maxFreq) {
            ans.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};