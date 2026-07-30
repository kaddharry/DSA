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
public:\
    vector<TreeNode*> helper(int s,int e){
        if(s > e) return {nullptr};
        vector<TreeNode*> res;

        for(int i = s; i <= e; i++){
            vector<TreeNode*> leftT = helper(s, i-1);
            vector<TreeNode*> rightT = helper(i+1, e);
            for(TreeNode* lT : leftT){
                for(TreeNode* rT: rightT){
                    TreeNode* node = new TreeNode(i);
                    node->left = lT;
                    node->right = rT;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return helper(1,n);
    }
};