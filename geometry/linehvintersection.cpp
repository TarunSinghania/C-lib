//https://www.hackerearth.com/practice/math/geometry/line-intersection-using-bentley-ottmann-algorithm/tutorial/

//in this algorithm , we dont care about vetical vertical, horizantal horizantal collisions
// example line (1,1) (1,5)  and line (1,3)(1,6) are not counted 
//in this algorithm we donot care about horizantal horizantal touches or vertical vertical touches
// example line (1,1) (1,5)  and line (2,3)(2,6) are not counted

//we only care about horizantal and vertical collision
//for touch on sides or corners extend horizantl, vertical line on both sides by 1  
int n,e;
class event{
    pair<int,int> p1,p2;
int type; //0 for insert horizantal line 2 remove horizanatal line 1 vertical line 
}
events event[MAX];
bool cmp(event a, event b){
    if(a.p1.first !== b.p1.first)
        a.p1.first < a.p1.first;
    else{
    //x coordinate is same then we would like to insert first and then vertical line check and then remove 
        return a.type; < b.type;
    }
}
multi_set<int> s;
void intersections(){
    for(int i =0 ;i < e; i++){
        event temp = e[i];
        if(e[i].type == 0)s.insert(e[i].p1.y);
        else if(e[i].type == 2)s.erase(s.find(e[i].p2.y));
        else{
        //range search 
        int y_low = min(e[i].p1.second,e[i].p2.second);
        int y_up =  min(e[i].p1.second,e[i].p2.second) ;
        auto it = lower_bound(s.begin(), s.end(), y_low);           
                    if(*it <= y_up){
                        //we have intersection
                    }
                }
            }
        }
        int main(){
        cin>>n;
        for(int i =0 ; i < n ; i++){
                int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
                if(x1 == x2){
                    events[e++] = event(x1,y2,x2,y2,1);
                }else(y1== y2){
                    if(x1 > x2)swap(x1,x2);
                    events[e++] = event(x1,y1,x2,y2,0)
                    events[e++] = event(x2,y2,x1,y1,2);
                }else{
                //incorrect input
                }
            }
        sort(events,events + e, cmp);
        intersections();
}


