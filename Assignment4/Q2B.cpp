#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

class Vehicle{
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

    public:
    Vehicle()
    :registrationNo(""),ownerName(""),yearOfManufacture(0),kmDriven(0){
        
    }
    Vehicle(const string& reg, const string& owner, int year, double km)
    :registrationNo(reg),ownerName(owner),
    yearOfManufacture(year),kmDriven(km){
      cout<<"[Vehicle Constructor]"<<" "<<registrationNo<<" "<<ownerName<<endl;
    }
    virtual double fuelCost(double kmToTravel)const=0;
    virtual void describe() const{
        cout<<"Registration Number is : "<<registrationNo<<endl;
        cout<<"ownerName              : "<<ownerName<<endl;
        cout<<"Year Of Manufacture    : "<<yearOfManufacture<<endl;
        cout<<"km Driven               : "<<kmDriven<<endl;
    }
    virtual string vehicletype() const=0;
    virtual ~Vehicle(){
        cout<<"[Vehicle Destructor]"<<" "<<registrationNo<<endl;
    };
    double getkmDriven() const{
        return kmDriven;
    }
    string getregNo() const{
        return registrationNo;
    }


};

class Car: public Vehicle{
    string fueltype;
    double mileageKmpl;

    public:
    Car(const string& reg, const string& owner, int year, double km, string fltyp, double mi)
     : Vehicle(reg,owner,year,km),fueltype(fltyp),mileageKmpl(mi){
      cout<<"[Car Constructor]"<<" "<<reg<<" "<<owner<<endl; 
    }

    double fuelCost(double kmToTravel)const override{
        double fuelprice=0;

        if(fueltype=="petrol")
        {
            fuelprice=106.00;
        }else if(fueltype=="diesel"){
            fuelprice=93.00;
        }else{
        cout<<"invalid fuel type";}
        return ((kmToTravel/mileageKmpl)*fuelprice);
    }

    string vehicletype()const override{
        return "Car";
    }

    void describe()const override{
        Vehicle::describe();
        cout<<"Fuel type : "<<fueltype<<endl;
        cout<<"MileageKmpl : "<<mileageKmpl<<endl;
    }
     
    ~Car(){
        cout<<"[Car Destructor]"<<" "<<getregNo()<<endl;
    }

};

class Truck: public Vehicle{
       double payloadCapacityTons;
       double fuelEfficiencyKmpl;
       public:
       Truck(const string& reg, const string& owner, int year, double km, double capacity, double fuelE)
     : Vehicle(reg,owner,year,km),payloadCapacityTons(capacity),fuelEfficiencyKmpl(fuelE){
     cout<<"[Truck Constructor]"<<" "<<reg<<" "<<owner<<endl;
    }  

       double fuelCost(double kmToTravel)const override{
        double reduction=0.05*payloadCapacityTons;
        double adjustedefficiency=fuelEfficiencyKmpl*(1-reduction);
        double diesel=93;
        return (kmToTravel/adjustedefficiency)*diesel;
       }
        string vehicletype() const override{
        return "Truck";
       }

       void describe()const override{
           Vehicle::describe();

           cout<<"Playload "<<payloadCapacityTons<<endl;
           cout<<"Fuel Efficiency "<<fuelEfficiencyKmpl<<endl;
       }
       ~Truck(){
        cout<<"[Truck Deconstructor]"<<" "<<getregNo()<<endl;
    }

    };

class ElectricTruck:public Truck{
     double batteryCapacityKWh;
     double rangePerChargeKm;
     public:
     ElectricTruck(const string &reg, const string &owner, int year, double km, double payload,
                     double efficiency, double battry, double range):
     Truck(reg,owner,year,km,payload,efficiency), batteryCapacityKWh(battry),rangePerChargeKm(range)
    {
       cout<<"[ElectricTruck Constructor] "<<reg<<" "<<owner<<endl; }

    double fuelCost(double kmToTravel)const override{
             const double electricitycost=9.50;
        return (kmToTravel/rangePerChargeKm)*rangePerChargeKm*electricitycost;
    }
     

    string vehicletype() const override{
        return "Electric Truck";
       }

       void describe()const override{
           Truck::describe();

           cout<<"Battery Capacity KWh "<<batteryCapacityKWh<<endl;
           cout<<"Range Per Charge Km "<<rangePerChargeKm<<endl;
       }
          
       ~ElectricTruck(){
        cout<<"[ElectricTruck Deconstructor]"<<" "<<getregNo()<<endl;
    }

};

class Van:public Vehicle{
    int seatingCapcity;
    double mileageKmpl;
    public:
    Van(const string& reg, const string& owner, int year, double km, int seatc, double mileage)
    :Vehicle(reg,owner,year,km),seatingCapcity(seatc),mileageKmpl(mileage){
    cout<<"[Van Constructor]"<<" "<<reg<<" "<<owner<<endl;

    }

    double fuelCost(double kmToTravel) const override{
        double petrol=106.00;

        return (kmToTravel/mileageKmpl)*petrol;
    }
    
    string vehicletype() const override{
        return "Van";
       }

       void describe(){
        Vehicle::describe();
        cout<<"Seating Capcity "<<seatingCapcity<<endl;
        cout<<"MileageKmpl "<<mileageKmpl<<endl;
       }
       ~Van(){
        cout<<"[Van Destructor]"<<" "<<getregNo()<<endl;
       }
    };

    int main(){

    cout << fixed << setprecision(2);

    // Car car("MH01CAR123","Abhay",2024,15000,"Petrol",18);

    // Truck truck("MH02TRK456","Rahul",2022,40000,5,12);

    ElectricTruck electricTruck("MH03EV789","Amit",2025,5000,3,10,120,400);
    // Van van("MH04VAN111","Rohit",2023,20000,8,15);
   


    return 0;
}