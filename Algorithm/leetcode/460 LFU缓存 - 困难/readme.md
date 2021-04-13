<!--
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-12 09:01:28
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-12 09:01:30
-->

# 460 LFU缓存

## 1.应该是比较直接的想法

维护一个长度为capicity的数组，数组成员是一个个包含key value cnt time的对象实例，每次增加根据目前数组情况更新，每次查找更新数组信息，替换时候根据cnt和time值来找到最应该被替换的内容。

因为在判断时候经常需要遍历数组，因而复杂度应该不会低

执行结果：通过

执行用时：124 ms, 在所有 Java 提交中击败了5.00%的用户

内存消耗：47.5 MB, 在所有 Java 提交中击败了37.00%的用户

## 2.维护了一个双端链表，相当于是用栈的深度来作为优先级的判断，每次需要更新时候，就将原链表中的节点删除，更新数据然后插入队尾。

https://leetcode-cn.com/problems/lfu-cache/solution/java-13ms-shuang-100-shuang-xiang-lian-biao-duo-ji/

执行结果：通过

执行用时：19 ms, 在所有 Java 提交中击败了98.31%的用户

内存消耗：46.7 MB, 在所有 Java 提交中击败了60.55%的用户
