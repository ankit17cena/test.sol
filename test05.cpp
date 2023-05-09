sol 5.1

vector<int> merge_lists(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> merged_list;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            merged_list.push_back(a[i]);
            i++;
        } else {
            merged_list.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        merged_list.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        merged_list.push_back(b[j]);
        j++;
    }
    return merged_list;
}

sol 5.2

vector<int> square_sorted(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    int i = 0, j = n - 1;
    for (int k = n - 1; k >= 0; k--) {
        if (abs(nums[i]) > abs(nums[j])) {
            res[k] = nums[i] * nums[i];
            i++;
        } else {
            res[k] = nums[j] * nums[j];
            j--;
        }
    }
    return res;
}

sol 5.3

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool all_leaves_level(TreeNode* root) {
    if (!root) {
        return true;
    }
    queue<pair<TreeNode*, int>> q;
    int leaf_level = -1;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second;
        q.pop();
        if (!node->left && !node->right) {
            if (leaf_level == -1) {
                leaf_level = level;
            } else if (level != leaf_level) {
                return false;
            }
        }
        if (node->left) {
            q.push(make_pair(node->left, level + 1));
        }
        if (node->right) {
            q.push(make_pair(node->right, level + 1));
        }
    }
    return true;
}

