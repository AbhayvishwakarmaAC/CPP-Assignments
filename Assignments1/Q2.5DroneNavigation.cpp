#include<iostream>
#include<cmath>
using namespace std;

inline double distanceBetween(double x1, double y1, double x2, double y2){

    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));

}
inline double toRadians(double degrees){

    return degrees*(M_PI/180);

}
inline double clamp(double value, double minVal, double maxVal ){
 
     if (value < minVal)
        return minVal;

    if (value > maxVal)
        return maxVal;

    return value;

}
inline bool isInSafeZone(double x, double y, double cx, double cy, double radius){
       
    if(sqrt(pow(x-cx,2)+pow(y-cy,2))<=radius){
    return true;
    }

    return false;

}

int main(){

    cout<<"===============Way Poinnt 1======================"<<endl;
    cout<<"The Distance from home is: "<<distanceBetween(4,5,0.0,0.0)<<endl;
    cout<<"The Radians is: "<<toRadians(60.0)<<endl;
    cout<<"Clamp Value : "<<clamp(10, 0, 25)<<endl;
    cout << boolalpha;
    cout<<"Safe Zone: "<<isInSafeZone(4,5,0,0,50)<<endl;


    cout<<"===============Way Poinnt 2======================"<<endl;
    cout<<"The Distance from home is: "<<distanceBetween(3.7,7.3,0.0,0.0)<<endl;
    cout<<"The Radians is: "<<toRadians(80.0)<<endl;
    cout<<"Clamp Value : "<<clamp(20, 0, 25)<<endl;
    cout << boolalpha;
    cout<<"Safe Zone: "<<isInSafeZone(3.7,7.3,0,0,50)<<endl;

    cout<<"===============Way Poinnt 3======================"<<endl;

    cout<<"The Distance from home is: "<<distanceBetween(10.2,6.5,0.0,0.0)<<endl;
    cout<<"The Radians is: "<<toRadians(90.0)<<endl;
    cout<<"Clamp Value : "<<clamp(15, 0, 25)<<endl;
    cout << boolalpha;
    cout<<"Safe Zone: "<<isInSafeZone(10.2,6.5,0,0,50)<<endl;



    



}