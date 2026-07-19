/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool compare(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val) return false;
        return compare(a->left,b->left) && compare(a->right, b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!root) return false;
        if(compare(root,sub)) return true;
        return isSubtree(root->left, sub) || isSubtree(root->right, sub);
    }
};