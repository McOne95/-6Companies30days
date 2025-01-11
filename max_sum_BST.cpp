class Solution {
    struct Info {
        bool isBST; // is a valid BST
        int mx, mn, curr; // max value, min value, current max sum
        Info() : isBST(true), mx(INT_MIN), mn(INT_MAX), curr(0) {}
    };

    Info solve(TreeNode* root, int& ans) {
        if(!root)
            return Info();

        // post order traversal, we are moving bottom up    
        Info par;
        Info lc = solve(root->left, ans);
        Info rc = solve(root->right, ans);

        if(lc.isBST && rc.isBST && root->val > lc.mx && root->val < rc.mn) { // check whether is a BST root
            par.isBST = true;
            par.curr = root->val + lc.curr + rc.curr;
            par.mn = min(root->val, lc.mn);
            par.mx = max(root->val, rc.mx);
        }

        else { // if not a valid BST root
            par.isBST = false;
            par.curr = max(lc.curr, rc.curr);
        }

        ans = max(ans, par.curr);
        return par;
    }

public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

auto fastio = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
} ();