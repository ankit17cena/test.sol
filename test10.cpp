sol 10.1

bool PrimeFactors(int n) {
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else if (n % 3 == 0) {
            n /= 3;
        } else if (n % 5 == 0) {
            n /= 5;
        } else {
            return false;
        }
    }
    return true;
}

sol 10.2

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int binaryListToInt(ListNode* head) {
    int result = 0;
    while (head) {
        result = result * 2 + head->val;  
        head = head->next; 
    }
    return result;
}

sol 10.3

int maxSublistSum(std::vector<int>& nums) {
    int maxSum = 0;
    int left = 0, right = 0;
    std::unordered_set<int> uniqueNums;

    while (right < nums.size()) {
        if (uniqueNums.count(nums[right]) == 0) {
            uniqueNums.insert(nums[right]);
            maxSum = std::max(maxSum, std::accumulate(nums.begin() + left, nums.begin() + right + 1, 0));
            right++;
        } else {
            uniqueNums.erase(nums[left]);
            left++;
        }
    }

    return maxSum;
}
