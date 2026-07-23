class Solution 
{
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        return sumLeaves(root, false);
    }

    int sumLeaves(TreeNode* root, bool isLeft)
    {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return isLeft ? root->val : 0;

        int sum = 0;
        sum += sumLeaves(root->left, true);
        sum += sumLeaves(root->right, false);
        return sum;
    }
};