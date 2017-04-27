class Solution {
public:
    void combinationSum(vector<vector<int>>& result, vector<int>& candidates, int start, vector<int>& item, int current, int target)
    {
        if(current == target)
        {
            result.push_back(item);
            return;
        }
        if(current > target)
            return;
        
        int last = -1;
        for(int i = start; i < candidates.size(); i++)
        {
            int tmp = current + candidates[i];
            if(tmp > target)
                break;
            if(last == candidates[i])
                        continue;
            item.push_back(candidates[i]);
            current = tmp;
            combinationSum(result, candidates, i + 1, item, current, target);
            current = tmp - candidates[i];
            item.pop_back();
            last = candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size() <= 0)
            return result;
        sort(candidates.begin(), candidates.end());
        vector<int> item;
        combinationSum(result, candidates, 0, item, 0, target);
        return result;
    }
};