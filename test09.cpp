sol 9.1

std::vector<int> prime_factors(int n) {
    std::vector<int> factors;
    for (int i = 2; i <= n / i; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

sol 9.2

int main() {
	int n; cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++) v.push_back(v[i]);

    int result = nums[0]; 
    for (int i = 1; i < nums.size(); i++) {
        result = std::gcd(result, nums[i]); 
    }

    cout << "The largest positive integer that divides all the numbers is: " << result << endl;

    return 0;
}

sol 9.3

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeftNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int sum = 0;
    if (root->left) {
        sum += root->left->val; 
        sum += sumOfLeftNodes(root->left);  
    }
    sum += sumOfLeftNodes(root->right); 
    return sum;
}

