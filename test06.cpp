sol 6.1

string addStrings(string num1, string num2) {
    string res = "";
    int carry = 0, sum = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    while (i >= 0 || j >= 0) {
        int a = (i >= 0) ? num1[i] - '0' : 0;
        int b = (j >= 0) ? num2[j] - '0' : 0;
        sum = a + b + carry;
        res += to_string(sum % 10);
        carry = sum / 10;
        i--;
        j--;
    }
    if (carry != 0) {
        res += to_string(carry);
    }
    reverse(res.begin(), res.end());
    return res;
}

sol 6.2

int sumOfNumbers(string s) {
    int sum = 0;
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else {
            sum += num;
            num = 0;
        }
    }
    sum += num;
    return sum;
}

sol 6.3

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfTree(TreeNode* root) {
    int sum = 0;
    if (root == NULL) {
        return sum;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        sum += node->val;
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
    return sum;
}
