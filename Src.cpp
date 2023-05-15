sol 1.1

#include <cmath>
#include <iostream>
#include <catch2/catch.hpp>

bool isPerfectSquare(int n) {
    int k = sqrt(n);
    return k * k == n;
}

TEST_CASE("Test isPerfectSquare") {
    REQUIRE(isPerfectSquare(4) == true);
    REQUIRE(isPerfectSquare(9) == true);
    REQUIRE(isPerfectSquare(16) == true);
    REQUIRE(isPerfectSquare(25) == true);
    REQUIRE(isPerfectSquare(30) == false);
    REQUIRE(isPerfectSquare(123456789) == false);
}

int main() {
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    if (isPerfectSquare(n)) {
        std::cout << n << " is a perfect square." << std::endl;
    }
    else {
        std::cout << n << " is not a perfect square." << std::endl;
    }

    return 0;
}

sol 1.2

#include <iostream>
#include <vector>
#include <catch2/catch.hpp>

std::vector<int> mergeSortedLists(const std::vector<int>&a, const std::vector<int>&b) {
    std::vector<int> result;

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        }
        else {
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

TEST_CASE("Test mergeSortedLists") {
    std::vector<int> a = { 1, 3, 5, 7 };
    std::vector<int> b = { 2, 4, 6, 8 };

    std::vector<int> result = mergeSortedLists(a, b);
    REQUIRE(result == std::vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8 }));

    a = { 1, 2, 3 };
    b = { 4, 5, 6 };

    result = mergeSortedLists(a, b);
    REQUIRE(result == std::vector<int>({ 1, 2, 3, 4, 5, 6 }));

    a = { 1, 3, 5, 7 };
    b = { 2, 4, 6 };

    result = mergeSortedLists(a, b);
    REQUIRE(result == std::vector<int>({ 1, 2, 3, 4, 5, 6, 7 }));

    a = {};
    b = { 2, 4, 6, 8 };

    result = mergeSortedLists(a, b);
    REQUIRE(result == std::vector<int>({ 2, 4, 6, 8 }));
}

int main() {
    std::vector<int> a = { 1, 3, 5, 7 };
    std::vector<int> b = { 2, 4, 6, 8 };

    std::vector<int> result = mergeSortedLists(a, b);

    std::cout << "Merged list: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

sol 1.3

#include <iostream>
#include <stack>
#include <catch2/catch.hpp>

bool areBracketsBalanced(const std::string & s) {
    std::stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty();
}

TEST_CASE("Test areBracketsBalanced") {
    REQUIRE(areBracketsBalanced(""));
    REQUIRE(areBracketsBalanced("()"));
    REQUIRE(areBracketsBalanced("()[]{}"));
    REQUIRE(areBracketsBalanced("({[]})"));
    REQUIRE_FALSE(areBracketsBalanced("("));
    REQUIRE_FALSE(areBracketsBalanced(")"));
    REQUIRE_FALSE(areBracketsBalanced("([])"));
    REQUIRE_FALSE(areBracketsBalanced("([)]"));
    REQUIRE_FALSE(areBracketsBalanced("{{}"));
}

int main() {
    std::string s = "({[()]})";

    bool balanced = areBracketsBalanced(s);

    std::cout << "The brackets in \"" << s << "\" are " << (balanced ? "balanced" : "not balanced") << "." << std::endl;

    return 0;
}

sol 2.1

#include <iostream>
#include <unordered_map>
#include <vector>
#include <catch2/catch.hpp>

void removeLastDuplicates(std::vector<int>&nums) {
    std::unordered_map<int, int> count;

    for (int i = nums.size() - 1; i >= 0; i--) {
        int num = nums[i];

        if (count[num] > 0) {
            nums.erase(nums.begin() + i);
        }
        else {
            count[num]++;
        }
    }
}

TEST_CASE("Test removeLastDuplicates") {
    std::vector<int> v1 = { 1, 2, 3, 4 };
    removeLastDuplicates(v1);
    REQUIRE(v1 == std::vector<int>({ 1, 2, 3, 4 }));

    std::vector<int> v2 = { 1, 2, 2, 3, 3, 3 };
    removeLastDuplicates(v2);
    REQUIRE(v2 == std::vector<int>({ 1, 2, 2, 3 }));

    std::vector<int> v3 = { 1, 1, 1 };
    removeLastDuplicates(v3);
    REQUIRE(v3 == std::vector<int>({ 1 }));

    std::vector<int> v4 = { 1 };
    removeLastDuplicates(v4);
    REQUIRE(v4 == std::vector<int>({ 1 }));

    std::vector<int> v5 = {};
    removeLastDuplicates(v5);
    REQUIRE(v5 == std::vector<int>({}));
}

int main() {
    std::vector<int> nums = { 1, 2, 3, 4, 4, 3, 2, 5 };

    std::cout << "Before removing duplicates: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    removeLastDuplicates(nums);

    std::cout << "After removing duplicates: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

sol 2.2

#include <iostream>
#include <string>
#include <algorithm>
#include <catch2/catch.hpp>

std::string addStrings(std::string a, std::string b) {
    int n = a.size(), m = b.size();
    if (n < m) {
        std::swap(a, b);
        std::swap(n, m);
    }

    int carry = 0;
    std::string result = "";
    for (int i = 0; i < n; i++) {
        int digit_a = a[n - i - 1] - '0';
        int digit_b = i < m ? b[m - i - 1] - '0' : 0;

        int sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    if (carry != 0) {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

TEST_CASE("Adding two integer strings", "[addStrings]") {
    REQUIRE(addStrings("0", "0") == "0");
    REQUIRE(addStrings("0", "1234") == "1234");
    REQUIRE(addStrings("456", "0") == "456");
    REQUIRE(addStrings("123", "456") == "579");
    REQUIRE(addStrings("1001", "999") == "2000");
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

sol 2.3

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <catch2/catch.hpp>

string evaluate(string s) {
    vector<string> conditions, expressions;
    int i = 0;

    // Extract conditions from input string
    while (i < s.size()) {
        string temp;
        while (i < s.size() && s[i] != ' ') {
            temp.push_back(s[i]);
            i++;
        }
        i++;
        if (s[i] == ':')
            break;
        else
            conditions.push_back(temp);
    }

    // Extract expressions from input string
    i = s.size() - 1;
    while (i >= 0) {
        string temp;
        while (i >= 0 && s[i] != ' ') {
            temp.push_back(s[i]);
            i--;
        }
        i--;
        reverse(temp.begin(), temp.end());
        expressions.push_back(temp);
        if (s[i] == '?')
            break;
    }

    // Check if number of conditions and expressions are valid
    if (conditions.size() + 1 != expressions.size())
        return "Invalid Input";
    else {
        bool is_output_print = false;

        // Evaluate conditions and print corresponding expressions
        for (int j = 0; j < conditions.size(); j++) {
            if (conditions[j] == "false") {
                is_output_print = true;
                return expressions[j];
            }
        }

        // Print last expression if no conditions evaluated to false
        if (!is_output_print)
            return expressions.back();
    }
}

TEST_CASE("Test evaluate") {
    REQUIRE(evaluate("x > 5 ? x : x * 2") == "10");
    REQUIRE(evaluate("x < 5 ? x * 2 : x") == "4");
    REQUIRE(evaluate("false ? 1 : 2 ? 3 : 4") == "4");
    REQUIRE(evaluate("true ? false ? 1 : 2 : false ? 3 : 4") == "2");
    REQUIRE(evaluate("a != b ? (a > b ? a : b) : (a < b ? a : b)") == "5");
    REQUIRE(evaluate("false ? 1 : true ? false ? 3 : 4 : 2") == "3");
}

int main() {
    std::string s = "true ? true : false";
    string ans = evaluate(s);
    std::cout << ans << std::endl;

    return 0;
}

sol 3.1

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <catch2/catch.hpp>

std::vector<int> squareSorted(std::vector<int>&nums) {
    std::vector<int> res(nums.size());
    int left = 0, right = nums.size() - 1;
    for (int i = right; i >= 0; i--) {
        if (abs(nums[left]) > abs(nums[right])) {
            res[i] = nums[left] * nums[left];
            left++;
        }
        else {
            res[i] = nums[right] * nums[right];
            right--;
        }
    }
    return res;
}

TEST_CASE("Testing squareSorted function") {
    vector<int> nums1 = { -5, -3, 0, 2, 8 };
    vector<int> nums2 = { -2, 0, 1, 3 };
    vector<int> nums3 = { -9, -7, -3, -1, 2, 3, 7, 9 };

    SECTION("Test case 1") {
        vector<int> res = squareSorted(nums1);
        vector<int> expected = { 0, 4, 9, 25, 64 };
        REQUIRE(res == expected);
    }

    SECTION("Test case 2") {
        vector<int> res = squareSorted(nums2);
        vector<int> expected = { 0, 1, 4, 9 };
        REQUIRE(res == expected);
    }

    SECTION("Test case 3") {
        vector<int> res = squareSorted(nums3);
        vector<int> expected = { 1, 4, 9, 49, 49, 81, 81, 121 };
        REQUIRE(res == expected);
    }
}

int main(int argc, char* argv[]) {
    Catch::Session().run(argc, argv);
    return 0;
}

sol 3.2

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <string>
#include <cctype>

int sum_of_numbers(const std::string & s) {
    int sum = 0, current_number = 0;
    for (char c : s) {
        if (isdigit(c)) {
            current_number = current_number * 10 + (c - '0');
        }
        else {
            sum += current_number;
            current_number = 0;
        }
    }
    return sum + current_number;
}

TEST_CASE("sum_of_numbers function returns correct output", "[sum_of_numbers]") {
    REQUIRE(sum_of_numbers("hello5world6") == 11);
    REQUIRE(sum_of_numbers("abc123def456") == 579);
    REQUIRE(sum_of_numbers("1a2b3c4d5e6f") == 21);
    REQUIRE(sum_of_numbers("no_numbers_here") == 0);
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

sol 3.3

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool fourSum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 4) return false;

    // Create a hash table to store two element sums and their pair
    unordered_map<int, pair<int, int>> twoSums;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            twoSums[nums[i] + nums[j]] = { i, j };
        }
    }

    // Find four element sum using the hash table
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int twoSum = nums[i] + nums[j];
            if (twoSums.find(k - twoSum) != twoSums.end()) {
                auto p = twoSums[k - twoSum];
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    return true;
                }
            }
        }
    }

    return false;
}

TEST_CASE("Test for fourSum", "[fourSum]") {
    vector<int> v1 = { 1, 2, 3, 4, 5 };
    REQUIRE(fourSum(v1, 10) == true);
    vector<int> v2 = { 2, 4, 6, 8 };
    REQUIRE(fourSum(v2, 20) == true);
    vector<int> v3 = { 1, 2, 3, 4, 5 };
    REQUIRE(fourSum(v3, 20) == false);
    vector<int> v4 = { 1, 2, 3 };
    REQUIRE(fourSum(v4, 10) == false);
}

int main(int argc, char* argv[]) {
    Catch::Session session;
    int returnCode = session.run(argc, argv);
    return returnCode;
}

sol 4.1

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <vector>

std::string reverseWords(std::string s) {
    std::vector<std::string> words;
    std::string word;

    // Split the string into words
    for (char c : s) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
        else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    std::string reversed;

    // Reverse the order of words and concatenate them
    for (auto it = words.rbegin(); it != words.rend(); ++it) {
        reversed += *it;
        reversed += ' ';
    }

    // Remove the last space
    if (!reversed.empty()) {
        reversed.pop_back();
    }

    return reversed;
}

TEST_CASE("reverseWords function returns correct output") {
    REQUIRE(reverseWords("hello world") == "world hello");
    REQUIRE(reverseWords(" the sky is blue ") == "blue is sky the");
    REQUIRE(reverseWords("") == "");
}

int main(int argc, char* argv[]) {
    // Run Catch2 tests
    Catch::Session session;
    int catch_result = session.run(argc, argv);

    std::string s = "the quick brown fox";
    std::cout << reverseWords(s) << std::endl;

    return catch_result;
}

sol 4.2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <catch2/catch.hpp>

std::string toBase3(int n) {
    if (n == 0) {
        return "0";
    }

    std::string result = "";
    while (n > 0) {
        int rem = n % 3;
        result += std::to_string(rem);
        n /= 3;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

TEST_CASE("Test toBase3 function") {
    REQUIRE(toBase3(0) == "0");
    REQUIRE(toBase3(1) == "1");
    REQUIRE(toBase3(2) == "2");
    REQUIRE(toBase3(3) == "10");
    REQUIRE(toBase3(4) == "11");
    REQUIRE(toBase3(5) == "12");
    REQUIRE(toBase3(6) == "20");
    REQUIRE(toBase3(7) == "21");
    REQUIRE(toBase3(8) == "22");
}

int main() {
    // Run the tests
    Catch::Session().run();

    // Get input from user
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    // Convert to base 3 and print the result
    std::string result = toBase3(n);
    std::cout << "Base-3 value of " << n << " is: " << result << std::endl;

    return 0;
}

sol 4.3

#include <vector>
#include <unordered_map>
#include <iostream>
#include "catch2/catch.hpp"

int maxOperations(std::vector<int>&nums, int target) {
    std::unordered_map<int, int> freq;
    int count = 0;
    for (int i : nums) {
        if (freq[target - i] > 0) {
            count++;
            freq[target - i]--;
        }
        else {
            freq[i]++;
        }
    }
    return count;
}

TEST_CASE("Test maxOperations function") {
    std::vector<int> nums1 = { 1,2,3,4,5 };
    int target1 = 6;
    int expected1 = 2;
    REQUIRE(maxOperations(nums1, target1) == expected1);

    std::vector<int> nums2 = { 3,1,3,4,3 };
    int target2 = 6;
    int expected2 = 1;
    REQUIRE(maxOperations(nums2, target2) == expected2);

    std::vector<int> nums3 = { 1,1,1,1 };
    int target3 = 2;
    int expected3 = 2;
    REQUIRE(maxOperations(nums3, target3) == expected3);
}

int main() {
    std::vector<int> nums = { 1,2,3,4,5 };
    int target = 6;
    std::cout << "maxOperations(nums, target) = " << maxOperations(nums, target) << std::endl;

    return 0;
}

sol 5.1

#include <iostream>
#include <vector>
#include <algorithm>
#include <catch2/catch.hpp>

std::vector<int> mergeSortedArrays(std::vector<int>&a, std::vector<int>&b) {
    std::vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        }
        else {
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

TEST_CASE("Merging two sorted arrays", "[mergeSortedArrays]") {
    std::vector<int> a = { 1, 2, 4, 6, 8 };
    std::vector<int> b = { 3, 5, 7, 9 };
    std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> result = mergeSortedArrays(a, b);
    REQUIRE(result == expected);

    a = { 1, 3, 5, 7 };
    b = { 2, 4, 6, 8, 9, 10 };
    expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    result = mergeSortedArrays(a, b);
    REQUIRE(result == expected);

    a = { 1 };
    b = { 2 };
    expected = { 1, 2 };
    result = mergeSortedArrays(a, b);
    REQUIRE(result == expected);

    a = { 3, 4, 5 };
    b = { 1, 2 };
    expected = { 1, 2, 3, 4, 5 };
    result = mergeSortedArrays(a, b);
    REQUIRE(result == expected);

    a = {};
    b = {};
    expected = {};
    result = mergeSortedArrays(a, b);
    REQUIRE(result == expected);
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

sol 5.2

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <algorithm>

std::vector<int> squareSorted(const std::vector<int>&nums) {
    std::vector<int> result(nums.size());
    int left = 0, right = nums.size() - 1, idx = right;
    while (left <= right) {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];
        if (leftSq > rightSq) {
            result[idx--] = leftSq;
            left++;
        }
        else {
            result[idx--] = rightSq;
            right--;
        }
    }
    return result;
}

TEST_CASE("Square sorted array", "[squareSorted]") {
    REQUIRE(squareSorted({ -7, -3, 2, 3, 11 }) == std::vector<int>({ 4, 9, 9, 49, 121 }));
    REQUIRE(squareSorted({ -4, -1, 0, 3, 10 }) == std::vector<int>({ 0, 1, 9, 16, 100 }));
    REQUIRE(squareSorted({ -5, -4, -3, -2, -1 }) == std::vector<int>({ 1, 4, 9, 16, 25 }));
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

sol 5.3

#include <iostream>
#include <queue>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkLeavesAtSameLevel(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    std::queue<std::pair<TreeNode*, int>> q;
    q.push(std::make_pair(root, 0));
    int level = -1;

    while (!q.empty()) {
        std::pair<TreeNode*, int> p = q.front();
        q.pop();

        if (p.first->left == NULL && p.first->right == NULL) {
            if (level == -1) {
                level = p.second;
            }
            else if (level != p.second) {
                return false;
            }
        }

        if (p.first->left != NULL) {
            q.push(std::make_pair(p.first->left, p.second + 1));
        }

        if (p.first->right != NULL) {
            q.push(std::make_pair(p.first->right, p.second + 1));
        }
    }

    return true;
}

int main() {
    // Test case 1: all leaves at the same level
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    std::cout << "Test case 1: " << checkLeavesAtSameLevel(root1) << std::endl;

    // Test case 2: leaves at different levels
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->left->left = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);

    std::cout << "Test case 2: " << checkLeavesAtSameLevel(root2) << std::endl;

    // Test case 3: empty tree
    TreeNode* root3 = NULL;

    std::cout << "Test case 3: " << checkLeavesAtSameLevel(root3) << std::endl;

    return 0;
}

sol 6.1

#include <iostream>
#include <string>
#include <algorithm>

std::string addStrings(std::string a, std::string b) {
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    std::string result = "";

    while (i >= 0 || j >= 0 || carry != 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 10;
        result += std::to_string(sum % 10);
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string a = "1234";
    std::string b = "5678";
    std::string result = addStrings(a, b);
    std::cout << result << std::endl;
    return 0;
}

#include "catch.hpp"
#include <string>

std::string addStrings(std::string a, std::string b);

TEST_CASE("Add two integers in string representation", "[addStrings]") {
    REQUIRE(addStrings("0", "0") == "0");
    REQUIRE(addStrings("1", "1") == "2");
    REQUIRE(addStrings("123", "456") == "579");
    REQUIRE(addStrings("999", "1") == "1000");
}

sol 6.2

#include <iostream>
#include <string>
#include <algorithm>
#include <catch2/catch.hpp>

std::string addStrings(std::string a, std::string b) {
    int n = a.size(), m = b.size();
    if (n < m) {
        std::swap(a, b);
        std::swap(n, m);
    }

    int carry = 0;
    std::string result = "";
    for (int i = 0; i < n; i++) {
        int digit_a = a[n - i - 1] - '0';
        int digit_b = i < m ? b[m - i - 1] - '0' : 0;

        int sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    if (carry != 0) {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

TEST_CASE("Adding two integer strings", "[addStrings]") {
    REQUIRE(addStrings("0", "0") == "0");
    REQUIRE(addStrings("0", "1234") == "1234");
    REQUIRE(addStrings("456", "0") == "456");
    REQUIRE(addStrings("123", "456") == "579");
    REQUIRE(addStrings("1001", "999") == "2000");
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

sol 6.3

#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    std::stack<TreeNode*> stk;
    stk.push(root);
    int sum = 0;
    while (!stk.empty()) {
        TreeNode* curr = stk.top();
        stk.pop();
        sum += curr->val;
        if (curr->right != NULL) {
            stk.push(curr->right);
        }
        if (curr->left != NULL) {
            stk.push(curr->left);
        }
    }
    return sum;
}

// unit tests
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("sumTree returns the sum of all values in the tree") {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);

    REQUIRE(sumTree(root) == 71);

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
}

sol 7.1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <catch2/catch.hpp>

std::string toBase3(int n) {
    if (n == 0) {
        return "0";
    }

    std::string result = "";
    while (n > 0) {
        int rem = n % 3;
        result += std::to_string(rem);
        n /= 3;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

TEST_CASE("Test toBase3 function") {
    REQUIRE(toBase3(0) == "0");
    REQUIRE(toBase3(1) == "1");
    REQUIRE(toBase3(2) == "2");
    REQUIRE(toBase3(3) == "10");
    REQUIRE(toBase3(4) == "11");
    REQUIRE(toBase3(5) == "12");
    REQUIRE(toBase3(6) == "20");
    REQUIRE(toBase3(7) == "21");
    REQUIRE(toBase3(8) == "22");
}

int main() {
    // Run the tests
    Catch::Session().run();

    // Get input from user
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    // Convert to base 3 and print the result
    std::string result = toBase3(n);
    std::cout << "Base-3 value of " << n << " is: " << result << std::endl;

    return 0;
}

sol 7.2

#include <cmath>
#include <iostream>
#include <catch2/catch.hpp>

bool isPerfectSquare(int n) {
    int k = sqrt(n);
    return k * k == n;
}

TEST_CASE("Test isPerfectSquare") {
    REQUIRE(isPerfectSquare(4) == true);
    REQUIRE(isPerfectSquare(9) == true);
    REQUIRE(isPerfectSquare(16) == true);
    REQUIRE(isPerfectSquare(25) == true);
    REQUIRE(isPerfectSquare(30) == false);
    REQUIRE(isPerfectSquare(123456789) == false);
}

int main() {
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    if (isPerfectSquare(n)) {
        std::cout << n << " is a perfect square." << std::endl;
    }
    else {
        std::cout << n << " is not a perfect square." << std::endl;
    }

    return 0;
}

sol 7.3

#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    int maxSum = root->val;
    int leftSum = maxPathSum(root->left);
    int rightSum = maxPathSum(root->right);
    maxSum = std::max(maxSum, root->val + leftSum);
    maxSum = std::max(maxSum, root->val + rightSum);
    maxSum = std::max(maxSum, root->val + leftSum + rightSum);
    return maxSum;
}

int main() {
    // Example usage:

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    std::cout << maxPathSum(root) << std::endl; // Output: 12
    return 0;
}

#include <catch2/catch.hpp>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    int maxSum = root->val;
    int leftSum = maxPathSum(root->left);
    int rightSum = maxPathSum(root->right);
    maxSum = std::max(maxSum, root->val + leftSum);
    maxSum = std::max(maxSum, root->val + rightSum);
    maxSum = std::max(maxSum, root->val + leftSum + rightSum);
    return maxSum;
}

TEST_CASE("Test maxPathSum", "[maxPathSum]") {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    REQUIRE(maxPathSum(root) == 12);

    TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    REQUIRE(maxPathSum(root2) == 42);
}

sol 8.1

#include <iostream>
#include <cmath>
#include "catch.hpp"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int binaryToDecimal(ListNode* head) {
    int result = 0;
    int pos = 0;
    ListNode* curr = head;

    while (curr != nullptr) {
        result += curr->val * pow(2, pos);
        curr = curr->next;
        pos++;
    }

    return result;
}

TEST_CASE("Binary to decimal conversion works", "[binaryToDecimal]") {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(1);
    head1->next->next->next = nullptr;

    REQUIRE(binaryToDecimal(head1) == 5);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(1);
    head2->next->next->next = nullptr;

    REQUIRE(binaryToDecimal(head2) == 7);
}

int main() {
    // Run tests
    Catch::Session().run();
    return 0;
}

sol 8.2

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Merge two sorted vectors
std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
    std::vector<int> merged;
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(merged));
    return merged;
}

TEST_CASE("Test merge function") {
    std::vector<int> a = { 1, 3, 5, 7, 9 };
    std::vector<int> b = { 2, 4, 6, 8, 10 };
    std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    REQUIRE(merge(a, b) == expected);

    a = { 1, 2, 3, 4, 5 };
    b = { 6, 7, 8, 9, 10 };
    expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    REQUIRE(merge(a, b) == expected);

    a = { 1, 3, 5, 7, 9 };
    b = { 0, 2, 4, 6, 8 };
    expected = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    REQUIRE(merge(a, b) == expected);
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

sol 8.3

#include <iostream>
#include <stack>
#include "catch.hpp"

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true; // empty list or single node list

    // find the midpoint of the list
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse the second half of the list
    ListNode* prev = NULL;
    ListNode* curr = slow->next;
    while (curr) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    slow->next = NULL;

    // compare the first and second halves of the list
    ListNode* p1 = head;
    ListNode* p2 = prev;
    while (p1 && p2) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

TEST_CASE("Test isPalindrome function") {
    // empty list
    ListNode* l1 = NULL;
    REQUIRE(isPalindrome(l1) == true);

    // single node list
    ListNode* l2 = new ListNode(1);
    REQUIRE(isPalindrome(l2) == true);

    // palindrome with odd number of nodes
    ListNode* l3 = new ListNode(1);
    l3->next = new ListNode(2);
    l3->next->next = new ListNode(1);
    REQUIRE(isPalindrome(l3) == true);

    // not a palindrome with odd number of nodes
    ListNode* l4 = new ListNode(1);
    l4->next = new ListNode(2);
    l4->next->next = new ListNode(3);
    REQUIRE(isPalindrome(l4) == false);

    // palindrome with even number of nodes
    ListNode* l5 = new ListNode(1);
    l5->next = new ListNode(2);
    l5->next->next = new ListNode(2);
    l5->next->next->next = new ListNode(1);
    REQUIRE(isPalindrome(l5) == true);

    // not a palindrome with even number of nodes
    ListNode* l6 = new ListNode(1);
    l6->next = new ListNode(2);
    l6->next->next = new ListNode(3);
    l6->next->next->next = new ListNode(4);
    REQUIRE(isPalindrome(l6) == false);
}

int main(int argc, char* argv[]) {
    // global setup...
    int result = Catch::Session().run(argc, argv);
    // global clean-up...
    return result;
}

sol 9.1

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <catch2/catch.hpp>

std::vector<int> primeFactors(int n) {
    std::vector<int> factors;
    for (int i = 2; i <= n / i; i++) {
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

TEST_CASE("Prime factorization of integers", "[primeFactors]") {
    REQUIRE(primeFactors(2) == std::vector<int>{2});
    REQUIRE(primeFactors(3) == std::vector<int>{3});
    REQUIRE(primeFactors(4) == std::vector<int>{2, 2});
    REQUIRE(primeFactors(5) == std::vector<int>{5});
    REQUIRE(primeFactors(6) == std::vector<int>{2, 3});
    REQUIRE(primeFactors(7) == std::vector<int>{7});
    REQUIRE(primeFactors(8) == std::vector<int>{2, 2, 2});
    REQUIRE(primeFactors(9) == std::vector<int>{3, 3});
    REQUIRE(primeFactors(10) == std::vector<int>{2, 5});
    REQUIRE(primeFactors(11) == std::vector<int>{11});
    REQUIRE(primeFactors(12) == std::vector<int>{2, 2, 3});
    REQUIRE(primeFactors(13) == std::vector<int>{13});
    REQUIRE(primeFactors(14) == std::vector<int>{2, 7});
    REQUIRE(primeFactors(15) == std::vector<int>{3, 5});
    REQUIRE(primeFactors(16) == std::vector<int>{2, 2, 2, 2});
    REQUIRE(primeFactors(17) == std::vector<int>{17});
    REQUIRE(primeFactors(18) == std::vector<int>{2, 3, 3});
    REQUIRE(primeFactors(19) == std::vector<int>{19});
    REQUIRE(primeFactors(20) == std::vector<int>{2, 2, 5});
    REQUIRE(primeFactors(21) == std::vector<int>{3, 7});
    REQUIRE(primeFactors(22) == std::vector<int>{2, 11});
    REQUIRE(primeFactors(23) == std::vector<int>{23});
    REQUIRE(primeFactors(24) == std::vector<int>{2, 2, 2, 3});
    REQUIRE(primeFactors(25) == std::vector<int>{5, 5});
    REQUIRE(primeFactors(26) == std::vector<int>{2, 13});
    REQUIRE(primeFactors(27) == std::vector<int>{3, 3, 3});
    REQUIRE(primeFactors(28) == std::vector<int>{2, 2, 7});
    REQUIRE(primeFactors(29) == std::vector<int>{29});
    REQUIRE(primeFactors(30) == std::vector<int>{2, 3, 5});
}
int main(int argc, char* argv[]) {
    Catch::Session session;
    int returnCode = session.run(argc, argv);
    return returnCode;
}

sol 9.2

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int largestCommonDivisor(const std::vector<int>& nums) {
    assert(nums.size() > 0);
    if (nums.size() == 1) return nums[0];
    int ans = gcd(nums[0], nums[1]);
    for (size_t i = 2; i < nums.size(); i++) {
        ans = gcd(ans, nums[i]);
    }
    return ans;
}

// Unit tests using the Catch2 testing framework
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Largest Common Divisor of Positive Integers") {
    REQUIRE(largestCommonDivisor({ 10, 20, 30, 40, 50 }) == 10);
    REQUIRE(largestCommonDivisor({ 5, 7, 15, 20, 25 }) == 1);
    REQUIRE(largestCommonDivisor({ 25, 125, 250, 375, 500 }) == 25);
    REQUIRE(largestCommonDivisor({ 13, 26, 39, 52, 65 }) == 13);
    REQUIRE(largestCommonDivisor({ 3 }) == 3);
    REQUIRE(largestCommonDivisor({ 15, 15, 15, 15 }) == 15);
}

sol 9.3

#include <iostream>
#include <queue>
#include <vector>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumLeftNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int sum = 0;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            if (i == 0) {
                sum += curr->val;
            }

            if (curr->left) {
                q.push(curr->left);
            }

            if (curr->right) {
                q.push(curr->right);
            }
        }
    }

    return sum;
}

TEST_CASE("sumLeftNodes - Example Test Cases") {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    CHECK(sumLeftNodes(root) == 24);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);

    CHECK(sumLeftNodes(root2) == 6);
}

sol 10.1

#include <vector>
#include <unordered_set>
#include <cmath>
#include <catch2/catch.hpp>

bool only235PrimeFactors(int n) {
    // Handle base cases
    if (n <= 1) {
        return false;
    }
    if (n == 2 || n == 3 || n == 5) {
        return true;
    }
    // Check if n has any prime factors other than 2, 3 or 5
    std::vector<int> primes{ 2, 3, 5 };
    std::unordered_set<int> primeSet(primes.begin(), primes.end());
    for (int i = 0; i < primes.size(); i++) {
        while (n % primes[i] == 0) {
            n /= primes[i];
        }
    }
    if (primeSet.find(n) != primeSet.end()) {
        return true;
    }
    return false;
}

TEST_CASE("Testing only235PrimeFactors", "[only235PrimeFactors]") {
    REQUIRE(only235PrimeFactors(2) == true);
    REQUIRE(only235PrimeFactors(3) == true);
    REQUIRE(only235PrimeFactors(5) == true);
    REQUIRE(only235PrimeFactors(6) == true);
    REQUIRE(only235PrimeFactors(8) == true);
    REQUIRE(only235PrimeFactors(10) == true);
    REQUIRE(only235PrimeFactors(15) == true);
    REQUIRE(only235PrimeFactors(30) == true);
    REQUIRE(only235PrimeFactors(7) == false);
    REQUIRE(only235PrimeFactors(13) == false);
    REQUIRE(only235PrimeFactors(21) == false);
    REQUIRE(only235PrimeFactors(23) == false);
    REQUIRE(only235PrimeFactors(29) == false);
}

sol 10.2

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <cmath>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int binaryListToInt(ListNode* head) {
    int num = 0;
    while (head != nullptr) {
        num = num * 2 + head->val;
        head = head->next;
    }
    return num;
}

TEST_CASE("Binary List to Int Test") {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(1);
    REQUIRE(binaryListToInt(head1) == 5);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(0);
    head2->next->next->next = new ListNode(1);
    REQUIRE(binaryListToInt(head2) == 11);
}

sol 10.3

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <catch2/catch.hpp>

int maxUniqueSublistSum(const std::vector<int>&nums) {
    int left = 0, right = 0;
    int sum = 0, max_sum = 0;
    std::unordered_set<int> seen_values;

    while (right < nums.size()) {
        if (seen_values.find(nums[right]) == seen_values.end()) {
            seen_values.insert(nums[right]);
            sum += nums[right];
            max_sum = std::max(max_sum, sum);
            right++;
        }
        else {
            seen_values.erase(nums[left]);
            sum -= nums[left];
            left++;
        }
    }

    return max_sum;
}

TEST_CASE("maxUniqueSublistSum - Example Tests") {
    REQUIRE(maxUniqueSublistSum({ 5, 2, 1, 3, 2, 4, 1 }) == 12);
    REQUIRE(maxUniqueSublistSum({ 1, 2, 3, 2, 1 }) == 6);
    REQUIRE(maxUniqueSublistSum({ 1, 1, 1, 1, 1 }) == 1);
}

TEST_CASE("maxUniqueSublistSum - Edge Cases") {
    REQUIRE(maxUniqueSublistSum({}) == 0);
    REQUIRE(maxUniqueSublistSum({ 0 }) == 0);
    REQUIRE(maxUniqueSublistSum({ 1, 2, 3, 4, 5 }) == 15);
    REQUIRE(maxUniqueSublistSum({ 5, 4, 3, 2, 1 }) == 5);
}

sol 11.1

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

// Function to return relative ranking of each person
std::vector<int> relativeRanking(std::vector<int>&nums) {
    std::unordered_map<int, int> map;  // Create a map to store each person's ranking
    std::vector<int> copy(nums);  // Create a copy of the nums vector to sort it
    std::sort(copy.rbegin(), copy.rend());  // Sort the copy of the nums vector in descending order

    // Iterate through the sorted copy of the nums vector and assign each person a ranking
    for (int i = 0; i < copy.size(); i++) {
        map[copy[i]] = i + 1;  // Assign a ranking to each person in the map
    }

    std::vector<int> result;  // Create a vector to store the relative rankings of each person

    // Iterate through the original nums vector and add each person's ranking to the result vector
    for (int i = 0; i < nums.size(); i++) {
        int ranking = map[nums[i]];  // Get the ranking of the current person from the map
        std::ostringstream oss;  // Create a string stream to convert the ranking to a string
        if (ranking == 1) {  // If the person is in first place, assign "Gold Medal"
            oss << "Gold Medal";
        }
        else if (ranking == 2) {  // If the person is in second place, assign "Silver Medal"
            oss << "Silver Medal";
        }
        else if (ranking == 3) {  // If the person is in third place, assign "Bronze Medal"
            oss << "Bronze Medal";
        }
        else {  // Otherwise, assign the ranking as a string
            oss << std::to_string(ranking);
        }
        std::string result_str = oss.str();  // Convert the ranking to a string
        result.push_back(ranking - 1);  // Add the relative ranking of the person to the result vector
    }

    return result;  // Return the vector of relative rankings
}

// Unit test using Catch2
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Relative ranking of each person is calculated correctly", "[relativeRanking]") {
    std::vector<int> nums1 = { 5, 4, 3, 2, 1 };
    REQUIRE(relativeRanking(nums1) == std::vector<int>({ 0, 1, 2, 3, 4 }));

    std::vector<int> nums2 = { 10, 3, 8, 9, 4 };
    REQUIRE(relativeRanking(nums2) == std::vector<int>({ 0, 4, 2, 1, 3 }));

    std::vector<int> nums3 = { 1, 1, 1, 1, 1 };
    REQUIRE(relativeRanking(nums3) == std::vector<int>({ 0, 0, 0, 0, 0 }));

    std::vector<int> nums4 = { 10, 10, 9, 8, 8 };
    REQUIRE(relativeRanking(nums4) == std::vector<int>({ 0, 0, 2, 3, 3 }));
}

sol 11.2

#include <iostream>
#include <string>
#include <algorithm>
#include <catch2/catch.hpp>

std::string addStrings(std::string a, std::string b) {
    int n = a.size(), m = b.size();
    if (n < m) {
        std::swap(a, b);
        std::swap(n, m);
    }

    int carry = 0;
    std::string result = "";
    for (int i = 0; i < n; i++) {
        int digit_a = a[n - i - 1] - '0';
        int digit_b = i < m ? b[m - i - 1] - '0' : 0;

        int sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    if (carry != 0) {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

TEST_CASE("Adding two integer strings", "[addStrings]") {
    REQUIRE(addStrings("0", "0") == "0");
    REQUIRE(addStrings("0", "1234") == "1234");
    REQUIRE(addStrings("456", "0") == "456");
    REQUIRE(addStrings("123", "456") == "579");
    REQUIRE(addStrings("1001", "999") == "2000");
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

sol 11.3

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <catch2/catch.hpp>

string evaluate(string s) {
    vector<string> conditions, expressions;
    int i = 0;

    // Extract conditions from input string
    while (i < s.size()) {
        string temp;
        while (i < s.size() && s[i] != ' ') {
            temp.push_back(s[i]);
            i++;
        }
        i++;
        if (s[i] == ':')
            break;
        else
            conditions.push_back(temp);
    }

    // Extract expressions from input string
    i = s.size() - 1;
    while (i >= 0) {
        string temp;
        while (i >= 0 && s[i] != ' ') {
            temp.push_back(s[i]);
            i--;
        }
        i--;
        reverse(temp.begin(), temp.end());
        expressions.push_back(temp);
        if (s[i] == '?')
            break;
    }

    // Check if number of conditions and expressions are valid
    if (conditions.size() + 1 != expressions.size())
        return "Invalid Input";
    else {
        bool is_output_print = false;

        // Evaluate conditions and print corresponding expressions
        for (int j = 0; j < conditions.size(); j++) {
            if (conditions[j] == "false") {
                is_output_print = true;
                return expressions[j];
            }
        }

        // Print last expression if no conditions evaluated to false
        if (!is_output_print)
            return expressions.back();
    }
}

TEST_CASE("Test evaluate") {
    REQUIRE(evaluate("x > 5 ? x : x * 2") == "10");
    REQUIRE(evaluate("x < 5 ? x * 2 : x") == "4");
    REQUIRE(evaluate("false ? 1 : 2 ? 3 : 4") == "4");
    REQUIRE(evaluate("true ? false ? 1 : 2 : false ? 3 : 4") == "2");
    REQUIRE(evaluate("a != b ? (a > b ? a : b) : (a < b ? a : b)") == "5");
    REQUIRE(evaluate("false ? 1 : true ? false ? 3 : 4 : 2") == "3");
}

int main() {
    std::string s = "true ? true : false";
    string ans = evaluate(s);
    std::cout << ans << std::endl;

    return 0;
}

sol 12.1

#include <vector>
#include "catch2/catch.hpp"

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int largestCommonDivisor(const std::vector<int>& nums) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result = gcd(result, nums[i]);
    }
    return result;
}

TEST_CASE("largestCommonDivisor of a list of positive integers") {
    std::vector<int> nums1{ 2, 4, 6, 8, 10 };
    REQUIRE(largestCommonDivisor(nums1) == 2);

    std::vector<int> nums2{ 12, 18, 24 };
    REQUIRE(largestCommonDivisor(nums2) == 6);

    std::vector<int> nums3{ 7, 14, 21 };
    REQUIRE(largestCommonDivisor(nums3) == 7);

    std::vector<int> nums4{ 5 };
    REQUIRE(largestCommonDivisor(nums4) == 5);
}

sol 12.2

#include <cmath>
#include <iostream>
#include <catch2/catch.hpp>

bool isPerfectSquare(int n) {
    int k = sqrt(n);
    return k * k == n;
}

TEST_CASE("Test isPerfectSquare") {
    REQUIRE(isPerfectSquare(4) == true);
    REQUIRE(isPerfectSquare(9) == true);
    REQUIRE(isPerfectSquare(16) == true);
    REQUIRE(isPerfectSquare(25) == true);
    REQUIRE(isPerfectSquare(30) == false);
    REQUIRE(isPerfectSquare(123456789) == false);
}

int main() {
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    if (isPerfectSquare(n)) {
        std::cout << n << " is a perfect square." << std::endl;
    }
    else {
        std::cout << n << " is not a perfect square." << std::endl;
    }

    return 0;
}

sol 12.3

#include <cmath>
#include <stdexcept>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

double getMiddleNodeValue(ListNode* head) {
    if (head == nullptr) {
        throw std::invalid_argument("List is empty");
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == nullptr) {
        return slow->val;
    }
    // If there are two middle nodes
    return (static_cast<double>(slow->val) + static_cast<double>(slow->next->val)) / 2;
}

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Test getMiddleNodeValue") {
    // Test case 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    REQUIRE(getMiddleNodeValue(head1) == 3);

    // Test case 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);
    REQUIRE(getMiddleNodeValue(head2) == 3.5);

    // Test case 3
    ListNode* head3 = new ListNode(1);
    REQUIRE(getMiddleNodeValue(head3) == 1);

    // Test case 4
    ListNode* head4 = nullptr;
    REQUIRE_THROWS_WITH(getMiddleNodeValue(head4), "List is empty");
}

sol 13.1

#include <cmath>
#include <iostream>
#include <catch2/catch.hpp>

bool isPerfectSquare(int n) {
    int k = sqrt(n);
    return k * k == n;
}

TEST_CASE("Test isPerfectSquare") {
    REQUIRE(isPerfectSquare(4) == true);
    REQUIRE(isPerfectSquare(9) == true);
    REQUIRE(isPerfectSquare(16) == true);
    REQUIRE(isPerfectSquare(25) == true);
    REQUIRE(isPerfectSquare(30) == false);
    REQUIRE(isPerfectSquare(123456789) == false);
}

int main() {
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    if (isPerfectSquare(n)) {
        std::cout << n << " is a perfect square." << std::endl;
    }
    else {
        std::cout << n << " is not a perfect square." << std::endl;
    }

    return 0;
}

sol 13.2

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <string>
#include <cctype>

int sum_of_numbers(const std::string & s) {
    int sum = 0, current_number = 0;
    for (char c : s) {
        if (isdigit(c)) {
            current_number = current_number * 10 + (c - '0');
        }
        else {
            sum += current_number;
            current_number = 0;
        }
    }
    return sum + current_number;
}

TEST_CASE("sum_of_numbers function returns correct output", "[sum_of_numbers]") {
    REQUIRE(sum_of_numbers("hello5world6") == 11);
    REQUIRE(sum_of_numbers("abc123def456") == 579);
    REQUIRE(sum_of_numbers("1a2b3c4d5e6f") == 21);
    REQUIRE(sum_of_numbers("no_numbers_here") == 0);
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

sol 13.3

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <catch2/catch.hpp>

int maxUniqueSublistSum(const std::vector<int>&nums) {
    std::unordered_set<int> unique_nums;
    int sum = 0, max_sum = 0;
    int left = 0, right = 0;

    while (right < nums.size()) {
        if (unique_nums.find(nums[right]) == unique_nums.end()) {
            unique_nums.insert(nums[right]);
            sum += nums[right];
            max_sum = std::max(max_sum, sum);
            ++right;
        }
        else {
            unique_nums.erase(nums[left]);
            sum -= nums[left];
            ++left;
        }
    }

    return max_sum;
}

TEST_CASE("Test maxUniqueSublistSum") {
    std::vector<std::pair<std::vector<int>, int>> testCases{
        {{1, 2, 3, 2, 5, 6, 7, 5}, 18},
        {{1, 1, 1, 1, 1}, 1},
        {{}, 0},
        {{1, 2, 3, 4, 5}, 15},
        {{1, 2, 3, 3, 2, 1}, 6}
    };

    for (auto& tc : testCases) {
        REQUIRE(maxUniqueSublistSum(tc.first) == tc.second);
    }
}

int main(int argc, char* argv[]) {
    Catch::Session session;
    int returnCode = session.applyCommandLine(argc, argv);
    if (returnCode != 0) {
        return returnCode;
    }
    return session.run();
}

sol 14.1

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <catch2/catch.hpp>

int maxSumSublist(std::vector<int>&nums) {
    int n = nums.size();
    int max_sum = 0;
    int i = 0, j = 0;
    std::unordered_set<int> st;
    while (i < n && j < n) {
        if (st.count(nums[j]) == 0) {
            st.insert(nums[j]);
            max_sum = std::max(max_sum, accumulate(nums.begin() + i, nums.begin() + j + 1, 0));
            j++;
        }
        else {
            st.erase(nums[i]);
            i++;
        }
    }
    return max_sum;
}

TEST_CASE("maxSumSublist - Example Test Cases") {
    std::vector<int> nums1 = { 1,2,3,2,5 };
    REQUIRE(maxSumSublist(nums1) == 8);

    std::vector<int> nums2 = { 1,1,1,1,1 };
    REQUIRE(maxSumSublist(nums2) == 1);

    std::vector<int> nums3 = { 1,2,3,4,5 };
    REQUIRE(maxSumSublist(nums3) == 15);
}

TEST_CASE("maxSumSublist - Edge Test Cases") {
    std::vector<int> nums1 = { 0 };
    REQUIRE(maxSumSublist(nums1) == 0);

    std::vector<int> nums2 = { 2,2,2,2,2 };
    REQUIRE(maxSumSublist(nums2) == 2);

    std::vector<int> nums3 = { 1,2,3,4,5,1,2,3,4,5 };
    REQUIRE(maxSumSublist(nums3) == 15);
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}

sol 14.2

#include <iostream>
#include <cmath>
#include "catch.hpp"

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getDecimalValue(ListNode* head) {
    int result = 0;
    ListNode* current = head;
    while (current != NULL) {
        result = result * 2 + current->val;
        current = current->next;
    }
    return result;
}

TEST_CASE("getDecimalValue function works properly", "[getDecimalValue]") {
    // Test case 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(1);
    REQUIRE(getDecimalValue(head1) == 5);

    // Test case 2
    ListNode* head2 = new ListNode(0);
    REQUIRE(getDecimalValue(head2) == 0);

    // Test case 3
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(1);
    REQUIRE(getDecimalValue(head3) == 3);
}

int main() {
    // Run tests
    Catch::Session().run();
    return 0;
}

sol 14.3

#include <string>
#include <stack>
#include <algorithm>

std::string deleteConsecutiveDuplicates(std::string s) {
    std::stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        }
        else {
            st.push(c);
        }
    }
    std::string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "solution.hpp"

TEST_CASE("deleteConsecutiveDuplicates with empty string", "[deleteConsecutiveDuplicates]") {
    REQUIRE(deleteConsecutiveDuplicates("") == "");
}

TEST_CASE("deleteConsecutiveDuplicates with no consecutive duplicates", "[deleteConsecutiveDuplicates]") {
    REQUIRE(deleteConsecutiveDuplicates("abcdefg") == "abcdefg");
}

TEST_CASE("deleteConsecutiveDuplicates with one pair of consecutive duplicates", "[deleteConsecutiveDuplicates]") {
    REQUIRE(deleteConsecutiveDuplicates("aab") == "b");
}

TEST_CASE("deleteConsecutiveDuplicates with multiple pairs of consecutive duplicates", "[deleteConsecutiveDuplicates]") {
    REQUIRE(deleteConsecutiveDuplicates("aabbcc") == "");
    REQUIRE(deleteConsecutiveDuplicates("aabbaacc") == "");
    REQUIRE(deleteConsecutiveDuplicates("aabbaaccd") == "d");
}

TEST_CASE("deleteConsecutiveDuplicates with all duplicates", "[deleteConsecutiveDuplicates]") {
    REQUIRE(deleteConsecutiveDuplicates("aaaaaa") == "");
}

sol 15.1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <catch2/catch.hpp>

std::string toBase3(int n) {
    if (n == 0) {
        return "0";
    }

    std::string result = "";
    while (n > 0) {
        int rem = n % 3;
        result += std::to_string(rem);
        n /= 3;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

TEST_CASE("Test toBase3 function") {
    REQUIRE(toBase3(0) == "0");
    REQUIRE(toBase3(1) == "1");
    REQUIRE(toBase3(2) == "2");
    REQUIRE(toBase3(3) == "10");
    REQUIRE(toBase3(4) == "11");
    REQUIRE(toBase3(5) == "12");
    REQUIRE(toBase3(6) == "20");
    REQUIRE(toBase3(7) == "21");
    REQUIRE(toBase3(8) == "22");
}

int main() {
    // Run the tests
    Catch::Session().run();

    // Get input from user
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    // Convert to base 3 and print the result
    std::string result = toBase3(n);
    std::cout << "Base-3 value of " << n << " is: " << result << std::endl;

    return 0;
}

sol 15.2

#include <vector>
#include <unordered_set>
#include <cmath>
#include <catch2/catch.hpp>

bool only235PrimeFactors(int n) {
    // Handle base cases
    if (n <= 1) {
        return false;
    }
    if (n == 2 || n == 3 || n == 5) {
        return true;
    }
    // Check if n has any prime factors other than 2, 3 or 5
    std::vector<int> primes{ 2, 3, 5 };
    std::unordered_set<int> primeSet(primes.begin(), primes.end());
    for (int i = 0; i < primes.size(); i++) {
        while (n % primes[i] == 0) {
            n /= primes[i];
        }
    }
    if (primeSet.find(n) != primeSet.end()) {
        return true;
    }
    return false;
}

TEST_CASE("Testing only235PrimeFactors", "[only235PrimeFactors]") {
    REQUIRE(only235PrimeFactors(2) == true);
    REQUIRE(only235PrimeFactors(3) == true);
    REQUIRE(only235PrimeFactors(5) == true);
    REQUIRE(only235PrimeFactors(6) == true);
    REQUIRE(only235PrimeFactors(8) == true);
    REQUIRE(only235PrimeFactors(10) == true);
    REQUIRE(only235PrimeFactors(15) == true);
    REQUIRE(only235PrimeFactors(30) == true);
    REQUIRE(only235PrimeFactors(7) == false);
    REQUIRE(only235PrimeFactors(13) == false);
    REQUIRE(only235PrimeFactors(21) == false);
    REQUIRE(only235PrimeFactors(23) == false);
    REQUIRE(only235PrimeFactors(29) == false);
}

sol 15.3

#include <vector>
#include <unordered_map>
#include <iostream>
#include "catch2/catch.hpp"

int maxOperations(std::vector<int>&nums, int target) {
    std::unordered_map<int, int> freq;
    int count = 0;
    for (int i : nums) {
        if (freq[target - i] > 0) {
            count++;
            freq[target - i]--;
        }
        else {
            freq[i]++;
        }
    }
    return count;
}

TEST_CASE("Test maxOperations function") {
    std::vector<int> nums1 = { 1,2,3,4,5 };
    int target1 = 6;
    int expected1 = 2;
    REQUIRE(maxOperations(nums1, target1) == expected1);

    std::vector<int> nums2 = { 3,1,3,4,3 };
    int target2 = 6;
    int expected2 = 1;
    REQUIRE(maxOperations(nums2, target2) == expected2);

    std::vector<int> nums3 = { 1,1,1,1 };
    int target3 = 2;
    int expected3 = 2;
    REQUIRE(maxOperations(nums3, target3) == expected3);
}

int main() {
    std::vector<int> nums = { 1,2,3,4,5 };
    int target = 6;
    std::cout << "maxOperations(nums, target) = " << maxOperations(nums, target) << std::endl;

    return 0;
}