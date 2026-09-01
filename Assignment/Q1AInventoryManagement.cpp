#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

class Product{

    int productId;
    string name;
    double price;
    int quantity;

    public:
    
    string getname(){
         return name;

    }

    void acceptDetails(){

        cout<<"Enter Product Id"<<endl;
        cin>>productId;
        cout<<"Enter Product name"<<endl;
        cin>>name;
        cout<<"Enter Product price"<<endl;
        cin>>price;
        cout<<"Enter Product quantity"<<endl;
        cin>>quantity;   
    }

    double totalValue(){
         
        return price*quantity;


    }
    bool isLowStock(int threshold) const{

    if(quantity<=threshold){

        return true;
    }else{
        return false;
    }
  }
     void displayDetails(){

        cout << fixed << setprecision(2);

        cout<<left<<setw(10)<<productId<<setw(15)<<name<<setw(10)<<price<<setw(10)<<quantity<<setw(15)<<totalValue();
        if(isLowStock(10)){
            cout<<"<--LOW STOCK";
        }
        cout<<endl;
    }


};

int main(){

    int n=2;

    Product arr[n];

    for(int i=0; i<n; i++){
        arr[i].acceptDetails();
    }

    cout << fixed << setprecision(2);
     
    cout<<"===== INVENTORY REPORT ====="<<endl;
    cout<<"IDName"  "Price  Qty  Total Value"<<endl;
    cout<<left<<setw(10)<<"ID"<<setw(15)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Qty"<<setw(15)<<"Total Value"<<endl;;
    for(int i=0; i<n; i++){
        arr[i].displayDetails();
    }

    double ValueProduct=arr[0].totalValue();
    int valueIndex=0;
    for(int i=0; i<n; i++){

        if(arr[i].totalValue()>ValueProduct){
            ValueProduct=arr[i].totalValue();
         valueIndex=i;
        }
    }

    cout<<"Highest Value Product : "<<arr[valueIndex].getname()<<"  (Rs. "<<arr[valueIndex].totalValue()<<")"<<endl;
    
    cout<<"Low Stock(threshold : 10)  : ";
    for(int i=0; i<n; i++){
      if(arr[i].isLowStock(10)){
        cout<<arr[i].getname();
      }
    }

    



}