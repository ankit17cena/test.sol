sol 2.1

vector<int> Remove_last(vector<int>& nums) {
    unordered_map<int, int> num_count;

    for (int i = nums.size() - 1; i >= 0; i--) {
        num_count[nums[i]]++;
        if (num_count[nums[i]] > 1) {
            nums.erase(nums.begin() + i);
        }
    }

    return nums;
}

sol 2.2

string Add_strings(string a, string b) {
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    string result = "";

    while (i >= 0 || j >= 0 || carry > 0) {
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
        result += to_string(sum % 10);
    }

    reverse(result.begin(), result.end());
    return result;
}

sol 2.3

void Sol(string &s){
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
    
}

