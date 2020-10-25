
public class 16.03题解1 {
//class Solution {
    public double[] intersection(int[] start1, int[] end1, int[] start2, int[] end2) {
        //求两线段的最大点和最小点
        int xmin1 = start1[0] < end1[0] ? start1[0] : end1[0];
        int ymin1 = start1[1] < end1[1] ? start1[1] : end1[1];
        int xmin2 = start2[0] < end2[0] ? start2[0] : end2[0];
        int ymin2 = start2[1] < end2[1] ? start2[1] : end2[1];

        int xmax1 = start1[0] > end1[0] ? start1[0] : end1[0];
        int ymax1 = start1[1] > end1[1] ? start1[1] : end1[1];
        int xmax2 = start2[0] > end2[0] ? start2[0] : end2[0];
        int ymax2 = start2[1] > end2[1] ? start2[1] : end2[1];

        double x = 0;
        double y = 0;
        //如果两点在直线的同一侧，代入方程同号
        int f11 = fangcheng(start2[0],start2[1],start1[0],start1[1],end1[0],end1[1]);
        int f12 = fangcheng(end2[0],end2[1],start1[0],start1[1],end1[0],end1[1]);
        int f21 = fangcheng(start1[0],start1[1],start2[0],start2[1],end2[0],end2[1]);
        int f22 = fangcheng(end1[0],end1[1],start2[0],start2[1],end2[0],end2[1]);
        //两点在直线的同侧，没有交点
        if (f11 * f12 > 0 || f21*f22 > 0){
            return new double[0];
        }else if(f11 == f12 && f12 == f21 && f21 == f22){//四点共线
            // 没有交叉排列
            if (xmax1 < xmin2 || xmax2 < xmin1){
                return new double[0];
            }else if(xmax1 == xmin1 && xmin1 == xmax2 && xmax2 == xmin2){//垂直的线，判断y
                //没有交叉
                if (ymax1 < ymin2 || ymax2 < ymin1){
                    return new double[0];
                }else{
                    //取两个条线的小值中最大的，得交叉点小点
                    x = xmax1;
                    y = ymin1 > ymin2 ? ymin1 : ymin2;
                    return new double[]{x,y};
                }
            }else {
                //取两个条线的小值中最大的，得交叉点小点
                x = xmin1 > xmin2 ? xmin1 : xmin2;
                if (start1[0] == x){
                    y = start1[1];
                }else if(end1[0] == x){
                    y = end1[1];
                }else if (start2[0] == x){
                    y = start2[1];
                }else {
                    y = end2[1];
                }
                return new double[]{x,y};
            }
        }else{
            // 线段1垂直
            if (start1[0] == end1[0]){
                x = start1[0];
                double xue2 = 1.0*(start2[1] - end2[1])/(start2[0] - end2[0]);
                double b2 = end2[1] - xue2 * end2[0];
                y = xue2 * x + b2;
                return new double[]{x,y};
            }else if (start2[0] == end2[0]){//线段2垂直
                x = start2[0];
                double xue1 = 1.0*(start1[1] - end1[1])/(start1[0] - end1[0]);
                double b1 = end1[1] - xue1 * end2[0];
                y = xue1 * x + b1;
                return new double[]{x,y};
            }else {//通用情况，线段1和线段2都不垂直，计算斜率、常量值，y=a*x+b
                double xue1 = 1.0*(start1[1] - end1[1])/(start1[0] - end1[0]);//斜率1
                double xue2 = 1.0*(start2[1] - end2[1])/(start2[0] - end2[0]);//斜率2
                double b1 = end1[1] - xue1 * end1[0];//常量b1
                double b2 = end2[1] - xue2 * end2[0];//常量b2
                x = (b2 - b1)/(xue1 - xue2);
                y = xue1 * x + b1;
                return new double[]{x,y};
            }
        }
    }
    //验证两点是否在另一条直线的同一侧，同一侧同号，不同侧异号
    private int fangcheng(int x,int y,int x0,int y0,int x1,int y1){
        return (x-x0)*(y1-y0) - (x1-x0)*(y-y0);
    }
//}
}