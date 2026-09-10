#include<iostream>
#include <iomanip>
#include <string>
#include <vector>
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
    }
    virtual double fuelCost(double kmToTravel)const=0;
    virtual void describe() const{
        cout<<registrationNo<<"\t"<<ownerName<<"\t"<<yearOfManufacture<<"\t"<<kmDriven<<endl;
    }
    virtual string vehicletype() const=0;
    virtual ~Vehicle(){
        cout<<"[Vehicle Destroyed] "<<registrationNo<<endl;
    };
    double getkmDriven() const{
        return kmDriven;
    }
    string getregNo() const{
        return registrationNo;
    }
    string getOwnerName(){
        return ownerName;
    }


};

class Car: public Vehicle{
    string fueltype;
    double mileageKmpl;

    public:
    Car(const string& reg, const string& owner, int year, double km, string fltyp, double mi)
     : Vehicle(reg,owner,year,km),fueltype(fltyp),mileageKmpl(mi){
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

    string getFuelType(){
         return fueltype;
    }
     
    ~Car(){
        cout<<"[Car Destroyed]"<<endl;
    }

};

class Truck: public Vehicle{
       double payloadCapacityTons;
       double fuelEfficiencyKmpl;
       public:
       Truck(const string& reg, const string& owner, int year, double km, double capacity, double fuelE)
     : Vehicle(reg,owner,year,km),payloadCapacityTons(capacity),fuelEfficiencyKmpl(fuelE){
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
        cout<<"[Truck Destroyed]"<<endl;
    }

    };

class ElectricTruck:public Truck{
     double batteryCapacityKWh;
     double rangePerChargeKm;
     int batteryPercent;
     public:
     ElectricTruck(const string &reg, const string &owner, int year, double km, double payload,
                     double efficiency, double battry, double range, int charge):
     Truck(reg,owner,year,km,payload,efficiency), batteryCapacityKWh(battry),rangePerChargeKm(range),batteryPercent(charge)
    {

     }

    double fuelCost(double kmToTravel)const override{
             const double electricitycost=9.50;
        return (kmToTravel/rangePerChargeKm)*batteryCapacityKWh*electricitycost;
    }
     

    string vehicletype() const override{
        return "Electric Truck";
       }

       void describe()const override{
           Truck::describe();

           cout<<"Battery Capacity "<<batteryCapacityKWh<<" KWh"<<endl;
           cout<<"Range "<<rangePerChargeKm<<endl;
           cout<<"Battry "<<batteryPercent<<"%"<<endl;
       }

       int getBatteryPercentage(){
        return batteryPercent;
       }
          
       ~ElectricTruck(){
        cout<<"[ElectricTruck Destroyed]"<<endl;
    }

};

class Van:public Vehicle{
    int seatingCapcity;
    double mileageKmpl;
    public:
    Van(const string& reg, const string& owner, int year, double km, int seatc, double mileage)
    :Vehicle(reg,owner,year,km),seatingCapcity(seatc),mileageKmpl(mileage){

    }

    double fuelCost(double kmToTravel) const override{
        double petrol=106.00;

        return (kmToTravel/mileageKmpl)*petrol;
    }
    
    string vehicletype() const override{
        return "Van";
       }

       void describe()const override{
        Vehicle::describe();
        cout<<"Seating Capcity "<<seatingCapcity<<endl;
        cout<<"MileageKmpl "<<mileageKmpl<<endl;
       }
       ~Van(){
        cout<<"[Van Destroyed]"<<endl;
       }
    };
     
    void printFleetReport(const vector<Vehicle*>&fleet, double tripKm)
        {
           cout << fixed << setprecision(2);
           cout<<"====FLEET REPORT - Trip Distance: "<<tripKm<<" Km"<<endl;

           cout<<left<<setw(10)<<"Reg"<<setw(15)<<"Type"<<setw(10)<<"Owner"<<setw(10)<<"Km Driven"<<endl;
            
            Vehicle* mostEfficient = nullptr;
            double minimumCost = 0;


           for(Vehicle* v: fleet){
           cout<<left<<setw(10)<<v->getregNo()<<setw(15)<<v->vehicletype()<<setw(10)<<v->getOwnerName()<<setw(10)<<v->getkmDriven()<<endl;
           }
           cout<<"===== FUEL / CHARGE COST ESTIMATE ====="<<endl;
           for(Vehicle* v: fleet){

              double cost= v->fuelCost(tripKm);

              cout<<left<<setw(12)<<v->getregNo();
              cout<<"("<<v->vehicletype()<<")";
           
            cout<<": Rs."<<fixed<<setprecision(2)<<cost;
              
            Car* c=dynamic_cast<Car*>(v);
            if(c!=nullptr){
                cout<<" ("<<c->getFuelType()<<")";
            }
        


            ElectricTruck* et=dynamic_cast<ElectricTruck*>(v);
            if(et!=nullptr){
                cout<<" [Battery: "<<et->getBatteryPercentage()<<"% Charged]";
            }

            cout<<endl;

            if(mostEfficient == nullptr||cost < minimumCost){
                        minimumCost=cost;
                        mostEfficient=v;       
            }
        }

        cout<<"Most Efficient Vehicle:"<<mostEfficient->getregNo()<<" ("<<mostEfficient->vehicletype()<<")"
        <<"-Rs. "<< minimumCost<<" for "<<tripKm<<" km"<<endl; 

    }
 int main(){

    vector<Vehicle*> fleet;
    fleet.push_back(new Car("MH01CAR123","Abhay",2024,15000,"petrol",18.7));
    fleet.push_back(new Truck("MH02TRK456","Rahul",2022,40000,5,12));
    fleet.push_back(new ElectricTruck("MH03EV789","Amit",2025,5000,3,10,120,400,85));
    fleet.push_back(new Van("MH04VAN111","Rohit",2023,20000,8,15));
    fleet.push_back(new Car("MH05DAR153","Shil",2021,65000,"deisel",21.4));
    

    double tripKm = 200;
    printFleetReport(fleet, tripKm);
     

    cout<<"===== Clean Up====="<<endl;
    for(Vehicle* v : fleet){
      delete v;
    }
    return 0;
}