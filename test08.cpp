sol 8.1

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

int binaryListToInt(ListNode* head) {
    int result = 0;
    while (head != NULL) {
        result = result * 2 + head->val;
        head = head->next;
    }
    return result;
}

sol 8.2

vector<int> mergeSortedLists(vector<int>& a, vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }
    return result;
}

sol 8.3

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    vector<int> values;
    while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
    }
    int left = 0, right = values.size() - 1;
    while (left < right) {
        if (values[left] != values[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}


