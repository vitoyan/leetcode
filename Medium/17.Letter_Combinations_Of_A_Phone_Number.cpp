class Solution {
public:
    void combinations(vector<string>& result, string& item, string digits, int n)
    {
       if(n == (int)digits.size())
       {
            result.push_back(item);
            return;
       }
       string letters;
       switch(digits[n])
       {
           case '2':
            letters = "abc";
            break;
            case '3':
            letters = "def";
            break;
            case '4':
            letters = "ghi";
            break;
            case '5':
            letters = "jkl";
            break;
            case '6':
            letters = "mno";
            break;
            case '7':
            letters = "pqrs";
            break;
            case '8':
            letters = "tuv";
            break;
            case '9':
            letters = "wxyz";
            break;
            break;
            default:
                return;
       }
       cout<<letters<<endl;
       for(int i = 0; i < (int)letters.size(); i++)
       {
           item.push_back(letters[i]);
           combinations(result, item, digits, n + 1);
           item.pop_back();
       }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty())
            return result;
        for(int i = 0; i < digits.size(); i++)
        {
            if(digits[i] < '2' || digits[i] > '9')
                return result;
        }
        
        string item;
        combinations(result, item, digits, 0);
        return result;
       
    }
};