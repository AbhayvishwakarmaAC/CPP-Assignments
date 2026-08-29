#include<iostream>
#include<string>
using namespace std;

int main(){

    
    double tempretaure;
    cout<<"Enter Tempreature value: ";
    cin>>tempretaure;
    int status;

    double farhenheight=(tempretaure*9/5)+32;

    cout<<"Temperature : "<<tempretaure<<" *C"<< " / "<<farhenheight<<" *F)"<<endl;


    if(tempretaure<0){
        status=-1;
        cout<<"Status      : SENSOR_ERROR"<<endl;
    }else if(tempretaure>=0 && tempretaure<=29){
        status=0;
        cout<<"Status      : NORMAL"<<endl;
    }else if(tempretaure>=30 && tempretaure<=44){
        status=1;
        cout<<"Status      :WARNING"<<endl;
    }else if(tempretaure>=45 && tempretaure<=59){
        status=2;
        cout<<"Status      : CRITICAL"<<endl;
    }else{
        status=3;
        cout<<"Status      : SHUTDOWN"<<endl;
    }
    switch(status){
       
        case -1: cout<<"Action      : Sensor fault--check wiring"<<endl;
                 break;
        case 0:  cout<<"Action      : No action required"<<endl;
                 break;
        case 1:  cout<<"Action      : Alert sent to supervisor"<<endl;
                 break;
        case 2:  cout<<"Action      : Cooling system triggered"<<endl;
                 break;
        case 3:  cout<<"Action      : Emergency shutdown initiated"<<endl;
                 break;
        default: break;

    }

        string AboveandBelow= tempretaure>=25? "Reading     : Below Average" : "Reading     : Above Average";

        cout<<AboveandBelow<<endl;



}