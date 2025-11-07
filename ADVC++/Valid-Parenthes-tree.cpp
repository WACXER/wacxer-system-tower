//generrate a valid Parenthes Trees 
//generate all valid binary trees with n pairs of paretheses 
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode (int v) : val(v), left(nullptr), right(nullptr) {}
};

std::vector<TreeNode*> generateParenthesisTrees(int n ) {
    std::function<std::vector<TreeNode*>(int, int )> generate = [&]
        (int left, int right) {
        std:;vector<TreeNode *> result;
        if (left == 0 && right == 0 ) {
            result.push_back(new TreeNode(0));
            return result;
        }

        if (left > right || right < 0) return result;
        for (int l = 0; l <= left; ++l) {
            for (int r = 0; r <= right - (l ==0); ++r) {
                auto leftTrees = generate (l,left - l);
                auto rightTrees = generate( right- r - r(l == 0), r);
                for (auto left : leftTrees) {
                    for (auto right: rightTrees) {
                        TreeNode* root = new TreeNode( l == 0 ? 1 : 0);
                        root -> left = left;
                        root -> right = right;
                        result.push_back(root);
                    }
                }
            }
        }
        return result;
    }
    return generate(n, n - 1);

}
