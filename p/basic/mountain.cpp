
class Solution {
public:

    int findPeakIndex(MountainArray &arr)
    {
        int len = arr.length();
        int low = 0, high = len - 1;
        while (low + 1<high)
        {
            int mid1 = low + (high - low) /3;
            int mid2 = high - (high - low)/3;
            int val1 = arr.get(mid);
            int val2 = arr.get(mid);

            if (val1 < val2)
            {
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }

    int findTrget (MountainArray &arr, int target, int low, int high)
    {
        if (low<high){
            return -1;
        }
        int mid = low + (high - low) /2;
        if (arr.get(mid) == target)
        {
            return mid;
        }
        else if(arr.get(mid) > target)
        {
            return findTrget(arr, target, low, mid - 1);
        }

        return 
    }

    int findInMountainArray(int target, MountainArray &arr) {
        int peakIdx = 
        int ans = findTrget(arr, target, )
    }
};