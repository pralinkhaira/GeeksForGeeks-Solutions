class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int i=0,j=0,k=0;
        set<int>ans;
        
        while(i<arr1.size() && j<arr2.size() && k<arr3.size())
        {
            int mini=min({arr1[i],arr2[j],arr3[k]});
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k])
            {
            ans.insert(arr1[i]);
            i++;
            j++;
            k++;
            }
            else if(arr1[i]==mini)
            {
                i++;
            }
            else if(arr2[j]==mini)
            {
                j++;
            }
            else if(arr3[k]==mini)
            {
                k++;
            }
        }
        vector<int>v;
        for(auto x:ans)
        v.push_back(x);
        return v;
    }
};