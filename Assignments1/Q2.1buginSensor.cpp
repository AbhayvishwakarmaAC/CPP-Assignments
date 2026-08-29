#include<iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2){ // This Method is Not Useful Beacuse in Call by Value its Expect Some Return value
                                                    // And we have use Void so So the Swapping done only inside function,
                                                    //also Returning Two values Not Possible As We want Swapped A and B 
    int temp=0;
    temp=reading1;
    reading1=reading2;
    reading2=temp;

}
void resetSensorPairV2(int &reading1, int &reading2){
    int  temp=reading1;
    reading1=reading2;
    reading2=temp;
    


}
void resetSensorPairV3(int *reading1, int *reading2){
    
int  temp=*reading1;
    *reading1=*reading2;
    *reading2=temp;

}

int main(){

    int A=55;
    int B=12;
    cout<<"---V1: Call by value---"<<endl;
    cout<<"Before : "<<"A="<<A<<"  B="<<B<<endl;
    resetSensorPairV1(A,B);
    cout<<"After  : "<<"A="<<A<<"  B="<<B<<"   <-----Value unchanged"<<endl;

    cout<<endl;
    cout<<"---V2: Call by Refrence---"<<endl;
    cout<<"Before : "<<"A="<<A<<"  B="<<B<<endl;
    resetSensorPairV2(A,B);
    cout<<"After  : "<<"A="<<A<<"  B="<<B<<"   <-----Value swapped"<<endl;

    cout<<endl;
    cout<<"---V3: Call by Pointer---"<<endl;
    cout<<"Before : "<<"A="<<A<<"  B="<<B<<endl;
    resetSensorPairV3(&A,&B);
    cout<<"After  : "<<"A="<<A<<"  B="<<B<<"   <-----Value swapped back"<<endl;


}