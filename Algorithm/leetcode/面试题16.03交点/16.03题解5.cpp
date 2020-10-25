// 双100%，茫茫多的if语句···有个比较难的地方就是，斜率相等时的交点怎么求，我是分别求四个端点是否在另一条线段上，然后取最小的。明天起来看看大佬们有没有简洁点的代码···

class Solution {
public:
    bool Isonline(int x,vector<int>& start,vector<int>& end){
        if(x<=max(start[1],end[1])&&x>=min(start[1],end[1]))return true;
        return false;
    }
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        vector<double> spot;
        double k1,k2,m1,m2,x,y;
        //两直线斜率都存在
        if(start1[0]!=end1[0]&&start2[0]!=end2[0]){
            k1=(double)(end1[1]-start1[1])/(end1[0]-start1[0]);
            k2=(double)(end2[1]-start2[1])/(end2[0]-start2[0]);
            m1=start1[1]-k1*start1[0];
            m2=start2[1]-k2*start2[0];
            if(k1!=k2){
                x=(m2-m1)/(k1-k2);
                y=k1*x+m1;
                if(Isonline(y,start1,end1)&&Isonline(y,start2,end2)){
                    spot.push_back(x);
                    spot.push_back(y);
                }
            }
            else{
                //两线段共线
                if(m1==m2){
                    if(Isonline(start1[1],start2,end2)){
                    if(spot.empty()){
                        spot.push_back(start1[0]);
                        spot.push_back(start1[1]);
                    }
                    else{
                        spot[1]=min(spot[1],(double)start1[1]);
                    }
                }
                if(Isonline(end1[1],start2,end2)){
                    if(spot.empty()){
                        spot.push_back(end1[0]);
                        spot.push_back(end1[1]);
                    }
                    else{
                        spot[1]=min(spot[1],(double)end1[1]);
                    }
                }
                if(Isonline(start2[1],start1,end1)){
                    if(spot.empty()){
                        spot.push_back(start2[0]);
                        spot.push_back(start2[1]);
                    }
                    else{
                        spot[1]=min(spot[1],(double)start2[1]);
                    }
                }
                if(Isonline(end2[1],start1,end1)){
                    if(spot.empty()){
                        spot.push_back(end2[0]);
                        spot.push_back(end2[1]);
                    }
                    else{
                        spot[1]=min(spot[1],(double)end2[1]);
                    }
                }
                }
            }
        }
        //一条直线斜率存在，另一条不存在
        else if(start1[0]==end1[0]&&start2[0]!=end2[0]){
            k2=(double)(end2[1]-start2[1])/(end2[0]-start2[0]);
            m2=start2[1]-k2*start2[0];
            x=start1[0];
            y=k2*x+m2;
            if(Isonline(y,start1,end1)){
                spot.push_back(x);
                spot.push_back(y);
            }
        }
        //同上
        else if(start1[0]!=end1[0]&&start2[0]==end2[0]){
            k1=(double)(end1[1]-start1[1])/(end1[0]-start1[0]);
            m1=start1[1]-k1*start1[0];
            x=start2[0];
            y=k1*x+m1;
            if(Isonline(y,start2,end2)){
                spot.push_back(x);
                spot.push_back(y);
            }
        }
        //斜率都不存在
        else if(start1[0]==end1[0]&&start2[0]==end2[0]){
            //两线段共线 才有可能有交点
            if(start1[0]==start2[0]){
                if(Isonline(start1[1],start2,end2)){
                    if(spot.empty()){
                        spot.push_back(start1[0]);
                        spot.push_back(start1[1]);
                    }
                    else{
                        spot[1]=min(spot[1],(double)start1[1]);
                    }
                }
                if(Isonline(end1[1],start2,end2)){
                    if(spot.empty()){
                        spot.push_back(end1[0]);
                        spot.push_back(end1[1]);
                    }
                    else{
                        spot[1]=min(spot[1],(double)end1[1]);
                    }
                }
                if(Isonline(start2[1],start1,end1)){
                    if(spot.empty()){
                        spot.push_back(start2[0]);
                        spot.push_back(start2[1]);
                    }
                    else{
                        spot[1]=min(spot[1],(double)start2[1]);
                    }
                }
                if(Isonline(end2[1],start1,end1)){
                    if(spot.empty()){
                        spot.push_back(end2[0]);
                        spot.push_back(end2[1]);
                    }
                    else{
                        spot[1]=min(spot[1],(double)end2[1]);
                    }
                }
            }
        }
        return spot;
    }
};