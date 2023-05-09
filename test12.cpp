sol 12.1

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int CommonDivisor(std::vector<int>& nums) {
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        result = gcd(result, nums[i]);
    }

    return result;
}

sol 12.2

bool isPerfectSquare(int n) {
    if (n < 0) {
        return false;
    } else if (n == 0 || n == 1) {
        return true;
    }

    long left = 1, right = n;

    while (left <= right) {
        long mid = left + (right - left) / 2;
        long square = mid * mid;

        if (square == n) {
            return true;
        } else if (square < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

sol 12.3

double getMiddleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == nullptr) {
        return (double)(slow->val + slow->prev->val) / 2.0;
    } else {
        return (double)slow->val;
    }
}

