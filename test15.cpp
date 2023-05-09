sol 15.1

string toBase3(int n) {
    string result;
    while (n != 0) {
        int rem = n % 3;
        result += to_string(rem);
        n /= 3;
    }
    reverse(result.begin(), result.end());
    return result;
}

sol 15.2

bool hasOnly235PrimeFactors(int n) {
    if (n <= 0) {
        return false;
    }
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }
    return n == 1;
}

sol 15.3

int max_operations(std::vector<int>& nums, int target) {
    int count = 0;
    std::unordered_set<int> visited;
    for (int num : nums) {
        int complement = target - num;
        if (visited.count(complement)) {
            count++;
            visited.erase(complement);
        } else {
            visited.insert(num);
        }
    }
    return count;
}

