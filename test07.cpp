sol 7.1

string base3(int n) {
    if (n == 0) return "0";
    string result = "";
    while (n > 0) {
        result = to_string(n % 3) + result;
        n /= 3;
    }
    return result;
}

sol 7.2

bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return root * root == n;
}

sol 7.3

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftSum = maxPathSum(root->left);
    int rightSum = maxPathSum(root->right);
    return root->val + max(0, max(leftSum, rightSum));
}

