#include<iostream>
#include<cmath>
using namespace std;


bool parsePacket(const int* rawdata, int size, int** outMin, int** outMax){
   
    int outmax1=*rawdata;
    int outmin1=*rawdata;
    if(size<0){
        return 0;
    }else {   

        for(int i=0; i<6; i++){
           outmin1=min(outmin1,*(rawdata+i));

        }
        *outMin= new int(outmin1); // beacuse *minPtr is null 
                                    // so there is Null Adress So we have to allocate the adress so 
                                    // we use ne to create object on heap which **outmax can point
        // cout<<outmin1<<endl;

         for(int i=0; i<6; i++){
           outmax1=max(outmax1,*(rawdata+i));
        }
         *outMax= new int(outmax1);
        // cout<<outmax1<<endl;

        return true;
    }

}

int main() {
  
    int packet[]={45,12,67,8,55,31};
    int* minPtr=0;
    int* maxPtr=0;

    if(parsePacket(packet, 6, &minPtr, &maxPtr)){

        cout<<"Calibration Min : "<<*minPtr<<endl;
        cout<<"Calibration Min : "<<*maxPtr<<endl;
    }

    delete minPtr;
    delete maxPtr;



}