/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<vector<int>> level = levelOrder(root);
        for(auto elem : level)
            result.push_back(elem[elem.size() - 1]);
        return result;
    }

private:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        recordLevel(root, result, 0);
        return result;
    }
    void recordLevel(TreeNode *root, vector<vector<int>> &result, int i){
        TreeNode* T = root;
        if(T == nullptr) return;
        if(result.size() == i){
            vector<int> leveli;
            result.push_back(leveli);
        }
        result[i].push_back(T->val);
        recordLevel(T->left, result, i + 1);
        recordLevel(T->right, result, i + 1);
    }
};
