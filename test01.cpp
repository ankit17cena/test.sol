Sol 1.1

bool PerfectSq(int n) {
    int sqrt_n = std::sqrt(n);
    return n == std::pow(sqrt_n, 2);
}

Sol 1.2

vector<int> Merge_Lists(vector<int> a, vector<int> b) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            merged.push_back(a[i]);
            i++;
        } else {
            merged.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        merged.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        merged.push_back(b[j]);
        j++;
    }

    return merged;
}

sol 1.3

bool Brackets_balanced(string s) {
    stack<char> st;
    unordered_map<char, char> brackets = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : s) {
        if (brackets.count(c) == 1) { 
            if (st.empty() || st.top() != brackets[c]) {
                return false;
            }
            st.pop();
        } else { 
            st.push(c);
        }
    }

    return st.empty();
}

 
