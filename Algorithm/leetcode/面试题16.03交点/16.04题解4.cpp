// 用克拉默法则求解两直线有无交点，再判断交点是否在线段上

vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
    int x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1];
    int x3 = start2[0], y3 = start2[1], x4 = end2[0], y4 = end2[1];
    int dx1 = x2 - x1, dy1 = y2 - y1, dx2 = x4 - x3, dy2 = y4 - y3;
    // ax + by + c = 0, 计算得到两条线段所在直线的方程, 用该方式表示并用行列式求解可以避免使用除法运算而产生小数
    int a1 = dy1, b1 = -dx1, c1 = dx1 * y1 - dy1 * x1;          
    int a2 = dy2, b2 = -dx2, c2 = dx2 * y3 - dy2 * x3;
    // 联立方程，用克拉默法则求解，det为原矩阵行列式，det1、det2为替换第1、2列后计算得到的行列式
    int det = a1 * b2 - a2 * b1, det1 = c2 * b1 - c1 * b2, det2 = c1 * a2 - c2 * a1;
    // 如果行列式为0，则有无穷解或无解
    if(det == 0) {
        // 考虑到a = 0 || b = 0，所以必须det1和det2都为0才能确定两线段在同一条直线上，
        if(det1 == 0 && det2 == 0) {
            // 判断两条线段有无交点,分别对x和y进行判断，考虑到直线平行于x轴和平行于y轴的情况
            if(min(x3, x4) > max(x1, x2) || min(x1, x2) > max(x3, x4)) return {};
            if(min(y3, y4) > max(y1, y2) || min(y1, y2) > max(y3, y4)) return {};
            // 线段位置有两种情况：包含或者是部分相交，两种情况中x第二小的即为所求，x相同时y第二小的即为所求
            vector<vector<int>> v{{x1, y1},{x2, y2},{x3, y3},{x4, y4}};
            sort(v.begin(), v.end()); // 使用sort简化代码
            return {(double)v[1][0], (double)v[1][1]};  //取第二小的即所求交点
        }
    }
    else{ // 有唯一解
        double x = det1 * 1.0 / det, y = det2 * 1.0 / det;
        // 判断交点是否在线段上
        if(max(min(x1, x2), min(x3, x4)) <= x && x <= min(max(x1, x2), max(x3, x4)) && max(min(y1, y2), min(y3, y4)) <= y && y <= min(max(y1, y2), max(y3, y4)))
            return {x, y};
    }
    return {}; // 无解或解不在线段上
}