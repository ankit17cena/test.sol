sol 14.1

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int largestCommonDivisor(vector<int>& nums) {
    int n = nums.size();
    int result = nums[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, nums[i]);
    }
    return result;
}

sol 14.2

int getDecimalValue(ListNode* head) {
    int result = 0;
    while (head != nullptr) {
        result = (result << 1) | head->val;
        head = head->next;
    }
    return result;
}

sol 14.3

string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

