/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-10 09:04:31
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-10 09:04:33
 */
class Solution {
    public boolean search(int[] nums, int target) {
        boolean bool = binSearch(nums, target, 0, nums.length - 1);
        return bool;
    }
    //不确定是否nums在区间内递增的二分查找
    private boolean binSearch(int[] nums, int target, int low, int high) {
        if (low != high) {
            int mid = (low + high) / 2;
            if (low == mid) {
                return nums[low] == target || nums[high] == target;
            }
            if (nums[mid] == target)
                return true;
            else if (nums[low] < nums[mid]) {
                //左侧是有序数组(因为有重复数组成员，所以这样不能判断是否有序)
                if (nums[mid] < target) 
                    return binSearch(nums, target, mid + 1, high);
                else
                    return binarySearch(nums, target, low, mid - 1);
            }
            else {
                //右侧是有序数组(因为有重复数组成员，所以这样不能判断是否有序)
                if (nums[mid] < target) 
                    return binarySearch(nums, target, mid + 1, high);
                else
                    return binSearch(nums, target, low, mid - 1);
            }
        }
        else {
            return nums[low] == target;
        }
    }
    //对有序数组正常的二分查找
    private boolean binarySearch(int[] nums, int target, int low, int high) {
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (low == mid) {
                return nums[low] == target || nums[high] == target;
            }
            if (target > nums[mid]) {
                low = mid + 1;
            }
            else if (target < nums[mid]) {
                high = mid - 1;
            }
            else 
                return true;
        }
        return false;
    }
}