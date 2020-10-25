import java.util.Scanner;
class MaxSumSubarray {
    public static int maxSubArray3(int[] nums) {
        int maxSum = nums[0];
        int sum = 0;
        int minSum = 0;
        for (int num : nums) {
          // prefix Sum
          sum += num;
          // update maxSum
          maxSum = Math.max(maxSum, sum - minSum);
          // update minSum
          minSum = Math.min(minSum, sum);
        }
        return maxSum;
    }
    public static void main(String[] argv)
    {
        int k;
        Scanner sc = new Scanner(System.in);
		System.out.print("请输入数组大小\n");
        k = sc.nextInt();
        int a[] = new int[k];
		System.out.print("请输入"+k+"个数据\n");
        for (int i = 0; i < k; i++)
            a[i] = sc.nextInt();
        System.out.println(MaxSumSubarray.maxSubArray3(a));
        sc.close();
    }
  }