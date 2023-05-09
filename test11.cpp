sol  11.1

std::vector<int> relativeRanking(std::vector<int>& nums) {
    std::vector<int> result;
    std::unordered_map<int, int> rankings;
 
    std::vector<int> sortedNums(nums);
    std::sort(sortedNums.begin(), sortedNums.end(), std::greater<int>());

    for (int i = 0; i < sortedNums.size(); i++) {
        if (i == 0) {
            rankings[sortedNums[i]] = 0; 
        } else {
            if (sortedNums[i] == sortedNums[i-1]) {
                rankings[sortedNums[i]] = rankings[sortedNums[i-1]];  
            } else {
                rankings[sortedNums[i]] = i;  
            }
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        result.push_back(rankings[nums[i]]);
    }

    return result;
}

sol 11.2

std::string addStrings(std::string a, std::string b) {
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    std::string result;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digitA = i >= 0 ? a[i] - '0' : 0;
        int digitB = j >= 0 ? b[j] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result = std::to_string(sum % 10) + result;
        i--;
        j--;
    }

    return result;
}

sol 11.3

int main()
{
    string s;
    cin>>s;
    vector<string> conditions, expressions;
    int i=0;
    while(i<s.size())
    {
        string temp;
        while(i<s.size()&&s[i]!=' ')
        {
            temp.push_back(s[i]);
            i++;
        }
        i++;
        if(s[i]==':')
            break;
        else
            conditions.push_back(temp);
    }
    i=s.size()-1;
    while(i>=0)
    {
        string temp;
        while(i>=0&&s[i]!=' ')
        {
            temp.push_back(s[i]);
            i--;
        }
        i--;
        reverse(temp.begin(),temp.end());
        expressions.push_back(temp);
        if(s[i]=='?')
            break;
    }
    if(conditions.size()+1 != expressions.size())
        cout<<"Invalid Input";
    else
    {
        bool is_output_print=false;
        
        for(int j=0;j<conditions.size();j++)
        {
            if(conditions[j]=="false")
            {
                cout<<expressions[j];
                is_output_print=true;
            }
        }
        
        if(is_output_print==false)
            cout<<expressions.back();
    }
    

    return 0;
}
