# 94. 二叉树的中序遍历

**给定一个二叉树，返回它的中序 遍历。**

示例:

```
输入: [1,null,2,3]
   1
    \
     2
    /
   3
```

输出: [1,3,2]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？

通过次数143,840提交次数202,296
题解一 ![sd](https://img.shields.io/appveyor/build/高成鑫/234?label=45)

![d](https://img.shields.io/appveyor/build/gcx-17211270/helloworld?color=green&label=OneDay&logo=dasdfa&logoColor=adsfadsf)

题解1： 使用迭代的Java算法

- 时间复杂度：O(n)。递归函数 T(n)=2⋅T(n/2)+1。
- 空间复杂度：最坏情况下需要空间O(n)O(n)，平均情况为O(\log n)O(logn)。
- 执行结果：通过 
- 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
- 内存消耗 :37.9 MB, 在所有 Java 提交中击败了5.79%的用户

题解2： 使用栈

- 时间复杂度：O(n)。
- 空间复杂度：O(n)。
- 执行结果：通过
- 执行用时 :1 ms, 在所有 Java 提交中击败了55.45%的用户
- 内存消耗 :38.1 MB, 在所有 Java 提交中击败了5.79%的用户