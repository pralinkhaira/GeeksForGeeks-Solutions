class Solution {
private:
    void generatePermutations(vector<int>& arr, int index, vector<vector<int>>& result) {
        if (index == arr.size()) {
            result.push_back(arr);
            return;
        }
        
        for (int i = index; i < arr.size(); i++) {
            swap(arr[index], arr[i]);
            generatePermutations(arr, index + 1, result);
            swap(arr[index], arr[i]);
        }
    }
    
public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> result;
        generatePermutations(arr, 0, result);
        return result;
    }
};