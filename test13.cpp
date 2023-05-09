sol 13.1

bool isPerfectSquare(int n) {
    int sum = 0;
    int i = 1;

    while (sum < n) {
        sum += i;
        i += 2;
    }

    return (sum == n);
}

sol 13.2

int sumOfNumbers(string s) {
    int sum = 0;
    int current_num = 0;

    for (char c : s) {
        if (isdigit(c)) {
            current_num = current_num * 10 + (c - '0');
        } else {
            sum += current_num;
            current_num = 0;
        }
    }

    sum += current_num;

    return sum;
}

sol 13.3

int maxUnique(vector<int>& nums) {
    int max_sum = 0;
    unordered_set<int> seen;
    int i = 0, j = 0;

    while (j < nums.size()) {
        if (seen.count(nums[j]) == 0) {
            seen.insert(nums[j]);
            max_sum = max(max_sum, accumulate(nums.begin() + i, nums.begin() + j + 1, 0));
            j++;
        } else {
            seen.erase(nums[i]);
            i++;
        }
    }

    return max_sum;
}

