# 可以用二分查找找交点，就和昨天的每日一题类似的思路。转了一圈题解区好像没人提到，这个方法还是很不错的，适合懒人写法。。。既然都用计算机了，何苦再花时间做数学题呢？

class Solution:
    # 根据start和end以及给定x求y
    def _calY(self, start, end, x):
        slope = (end[1] - start[1]) / (end[0] - start[0])
        return slope * (x - start[0]) + start[1]


    # 两条垂直线的情况
    def _twoVertical(self, start1, end1, start2, end2):
        if start1[0] != start2[0]:
            return []
        else:
            lo, hi = max(start1[1], start2[1]), min(end1[1], end2[1])
            return [start1[0], lo] if lo <= hi else []


    # 一条垂直线的情况，1为垂直线，2为非垂直线
    def _oneVertical(self, start1, end1, start2, end2):
        if start1[0] < start2[0] or start1[0] > end2[0]:
            return []
        else:
            y = self._calY(start2, end2, start1[0])
            if y >= start1[1] and y <= end1[1]:
                return [start1[0], y]
            else:
                return []


    # 无垂直线的情况，基于二分查找
    def _noVertical(self, start1, end1, start2, end2):
        interX1, interX2 = max(start1[0], start2[0]), min(end1[0], end2[0])
        if interX1 > interX2:
            return []
        else:
            left, right = interX1, interX2
            interY1_left = self._calY(start1, end1, left)
            interY2_left = self._calY(start2, end2, left)
            interY1_right = self._calY(start1, end1, right)
            interY2_right = self._calY(start2, end2, right)

            if interY1_left == interY2_left: return [left, interY1_left]
            if interY1_right == interY2_right: return [right, interY2_right]
            if (interY1_left - interY2_left) * (interY1_right - interY2_right) > 0: return []

            # 二分查找收敛于交点，精度为给定的10^(-6)
            sign = 1 if interY1_left > interY2_left else -1
            while right - left > 10 ** (-6):
                mid = (right + left) / 2
                y1 = self._calY(start1, end1, mid)
                y2 = self._calY(start2, end2, mid)

                if y1 == y2: return [mid, y1]
                if (y1 - y2) * sign > 0:
                    left = mid
                else:
                    right = mid
            
            return [left, y1]


    def intersection(self, start1: List[int], end1: List[int], start2: List[int], end2: List[int]) -> List[float]:
        if start1[0] > end1[0]: start1, end1 = end1, start1
        if start2[0] > end2[0]: start2, end2 = end2, start2

        # 两条垂直线
        if start1[0] == end1[0] and start2[0] == end2[0]:
            if start1[1] > end1[1]: start1, end1 = end1, start1
            if start2[1] > end2[1]: start2, end2 = end2, start2
            return self._twoVertical(start1, end1, start2, end2)
        
        # 一条垂直线
        elif start1[0] == end1[0]:
            if start1[1] > end1[1]: start1, end1 = end1, start1
            return self._oneVertical(start1, end1, start2, end2)
        
        elif start2[0] == end2[0]:
            if start2[1] > end2[1]: start2, end2 = end2, start2
            return self._oneVertical(start2, end2, start1, end1)

        # 无垂直线
        else:
            return self._noVertical(start1, end1, start2, end2)