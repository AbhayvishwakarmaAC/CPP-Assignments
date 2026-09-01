#include<iostream>
#include <iomanip>
using namespace std;



double reorderCost(int qty, double unitPrice){
    return qty * unitPrice;
}
 
double reorderCost(double qty, double unitPrice){
    return qty * unitPrice;
}
double reorderCost(int qty, double unitPrice, double taxRate){

    return (qty * unitPrice)+(qty * unitPrice*taxRate/100);
}
double applyDiscount(double price, double discountPercentage=10.0){
      return price-(price*discountPercentage/100);
}


int main(){

   cout << fixed << setprecision(2);
     
cout<<"The Cost Of integer Qty                            : Rs. "<<reorderCost(10,15.4)<<endl;
cout<<"The Cost double Qty                                : Rs. "<<reorderCost(15.5,96.5)<<endl;
cout<<"The Cost With Tax                                  : Rs. "<<reorderCost(15,66.4,18)<<endl;
cout<<"The Stock With Default 10 Percent Applied Discount : Rs. "<<applyDiscount(66.4)<<endl;
cout<<"The Cost With Applied Discount                     : Rs. "<<applyDiscount(66.4,18)<<endl;

return 0;
}