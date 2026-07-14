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
    int diff =0;

    int depth(TreeNode* x){
        if(x==nullptr){
            return 0;
        }

        int leftdepth = depth(x->left);
        int rightdepth = depth(x->right);

        diff = max(diff, (leftdepth-rightdepth));
        diff = max(diff, (rightdepth-leftdepth));
        return 1 + max(leftdepth, rightdepth);
        }

    bool isBalanced(TreeNode* root) {
        depth(root);
        if(diff<2){
            return true;
        }
        else return false;
    }
};
