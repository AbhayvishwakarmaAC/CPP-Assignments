#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
      cout << fixed << setprecision(2);
    double rowcolmn[3][3];
    int roomatwarning=0;
    

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
       cout<<"Temperature of floor "<<i+1<<" and room "<<j+1<<endl;
       cin>>rowcolmn[i][j];
       
        }

    }
    
    cout<<"        Room1"<<"     Room2"<<"     Room3"<<endl;
    
    double hotestroom=rowcolmn[0][0];

    double ArraySum=0;

    

    double floo1sum=0;
    double floo2sum=0;
    double floo3sum=0;

     for(int i=0; i<3; i++){
        cout<<"Floor:"<<i+1<<"   ";
        
        for(int j=0; j<3; j++){
       
       cout<<rowcolmn[i][j]<<"         ";
       hotestroom=max(hotestroom,rowcolmn[i][j]);

       if(rowcolmn[i][j]>=30){
        roomatwarning++;
       }
        
        if(i==0){
          floo1sum=floo1sum+rowcolmn[i][j];
          
        }else if(i==1){
          floo2sum=floo2sum+rowcolmn[i][j];
          
        }else if(i==2){
          floo3sum=floo3sum+rowcolmn[i][j];
        
        }

        }
    
      cout<<endl;
    }

    double avgfloor1=floo1sum/3;
    double avgfloor2=floo2sum/3;
    double avgfloor3=floo3sum/3;
   
    int hotestfloor=ArraySum/sizeof(rowcolmn)/sizeof(rowcolmn[0]);
    
    cout<<hotestroom<<endl;

    int Floori=0;
    int Roomj=0;
    
     
    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
        
       if(hotestroom==rowcolmn[i][j]){
        Floori=i+1;
        Roomj=j+1;
        break;
        }
    }}
    
    
    cout<<"Hostest Room   : Floor "<<Floori<<", Room "<<Roomj<<"  --->  "<<hotestroom<<endl;

    if(avgfloor1>avgfloor2 && avgfloor1>avgfloor3){
           
        cout<<"Hotest Floor : floor 1 "<<"(avg  "<<avgfloor1<<" *C)"<<endl; 
        
    }else if(avgfloor2>avgfloor3){
        cout<<"Hotest Floor : floor 2 "<<"(avg  "<<avgfloor2<<" *C)"<<endl;
    }else {
        cout<<"Hotest Floor : floor 1 "<<"(avg  "<<avgfloor3<<" *C)"<<endl;
    }

    cout<<"Room at WARNING or above : "<<roomatwarning<<endl;



}
