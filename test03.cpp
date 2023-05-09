sol 3.1

vector<int> Square_sorted(vector<int>& nums) {
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

sol 3.2

int Sum_of_numbers(string s) {
    int n = s.length();
    int sum = 0, num = 0;
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else {
            sum += num;
            num = 0;
        }
    }
    sum += num;
    return sum;
}

sol 3.3

bool Four_sum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 4) {
        return false;
    }

    unordered_map<int, vector<pair<int, int>>> pairs;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = nums[i] + nums[j];
            pairs[sum].push_back({i, j});
        }
    }

    for (auto it = pairs.begin(); it != pairs.end(); it++) {
        int complement = k - it->first;
        if (pairs.count(complement)) {
            for (auto& p1 : it->second) {
                for (auto& p2 : pairs[complement]) {
                    int i1 = p1.first, j1 = p1.second;
                    int i2 = p2.first, j2 = p2.second;
                    if (i1 != i2 && i1 != j2 && j1 != i2 && j1 != j2) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

