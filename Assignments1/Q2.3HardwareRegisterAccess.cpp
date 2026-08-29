#include<iostream>
using namespace std;



void statusReg(int statusReg){

}
void controlReg(int controlReg){

}
void dataReg(int dataReg){

}



int main(){

    int statusReg =0b1011001;
    int controlReg=0b0000000;
    int const dataReg =0b11001010;

    const int *regPtr1=&statusReg;
          int *const regPtr2=&controlReg;
    const int *const regPtr3=&dataReg;

    
    //  *regPtr1=0b1011111;  
    //    error: assignment of read-only location '* regPtr1'29 |      *regPtr1=0b1011111;
    //    Explanation:Beacuse its kept constant to the value of at address of statusReg which stored in pointer
    //    and we are trying to accres this using Derefrencing )
    regPtr1=&controlReg; // The address stored in regPtr1 was address of &statusReg Now we change it beacuse the pointer was not constant
    
    
    // *regPtr2=0b1011111; // We can chnage the Value of controlReg beacuse in this pointer is constant but the value can be chnage

    // regPtr2=&dataReg;
      //error: assignment of read-only variable 'regPtr2'38 |     regPtr2=&dataReg;
    //   here we cant Chnage the address where regptr2 is pointer beacuse its Constnat 

     
    // dataReg=0b1011111;
    // error: assignment of read-only variable 'dataReg' 43 |     dataReg=0b1011111;
    // Beacuse during decleration i make it Constnat

     
    // *regPtr3=0b1011111;  
    //    Error:assignment of read-only location '*(const int*)regPtr3'48 |     *regPtr3=0b1011111;
    //    Explanation:Beacuse its kept constant to the value of at address of dataReg which stored in pointer
    //    and we are trying to accres this using Derefrencing )*/
   
    // regPtr3= &controlReg;  
    // Error:error: assignment of read-only variable 'regPtr3'53 |     regPtr3= &controlReg;
    // explaination:because we also kept constant to regpt3, so Address Can not be chnaged
   
    
     cout<<"statusReg: "<<statusReg<<endl;
     cout<<"controlReg before write: "<<controlReg<<endl;
     *regPtr2=0b1011111;
     cout<<"controlReg After write: "<<controlReg<<endl;
     cout<<"dataReg: "<<dataReg<<endl;
     


    
    


}