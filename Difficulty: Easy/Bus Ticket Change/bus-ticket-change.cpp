class Solution {
  public:
    bool canServe(vector<int> &arr) {
       int five = 0, ten = 0;
        
        for (int x : arr) {
            if (x == 5) {
                five++;
            } else if (x == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else { // x == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true; // code here
        
    }
};