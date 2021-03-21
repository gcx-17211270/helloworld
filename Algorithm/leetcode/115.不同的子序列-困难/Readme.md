<!--
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-17 01:22:45
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-17 01:25:15
-->

# 115.不同的子序列-困难

## 暴力递归

虽然结果并不怎么可靠，但是不管怎么说自己也算是通过努力解决了这个问题的大部分，加油，奥里给！

没什么别的思路，就使用递归，从第一个字母，递归的寻找相同，在比较中如果发现了完全匹配的字符串，就记录下来，最后统计出所有匹配的过程。

54 / 62 个通过测试用例

状态：超出时间限制

提交时间：几秒前

最后执行的输入：

"adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc"
"bcddceeeebecbc"