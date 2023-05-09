sol 4.1

string reverse_words(string s) {
    vector<string> words;
    istringstream iss(s);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    int n = words.size();
    for (int i = 0; i < n / 2; i++) {
        swap(words[i], words[n - i - 1]);
    }

    ostringstream oss;
    for (int i = 0; i < n; i++) {
        oss << words[i];
        if (i < n - 1) {
            oss << " ";
        }
    }

    return oss.str();
}

sol 4.2

string base3(int n) {
    if (n == 0) {
        return "0";
    }
    string result = "";
    while (n > 0) {
        int remainder = n % 3;
        result += to_string(remainder);
        n /= 3;
    }
    reverse(result.begin(), result.end());
    return result;
}

sol 4.3

int max_operations(vector<int>& nums, int target) {
    unordered_map<int, int> freq;
    int count = 0;
    for (int num : nums) {
        if (freq[target - num] > 0) {
            count++;
            freq[target - num]--;
        } else {
            freq[num]++;
        }
    }
    return count;
}

