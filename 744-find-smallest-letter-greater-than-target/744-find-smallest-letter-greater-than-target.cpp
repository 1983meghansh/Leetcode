class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //perform  a binary search to search for the immediate first character in the letters array that is greater than the target
        if(letters.back()<=target)
            return letters[0];
        int low=0;
        int high=letters.size()-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(letters[mid]>target)
                high=mid;
            else
                low=mid+1;
        }
        return letters[low];
    }
};