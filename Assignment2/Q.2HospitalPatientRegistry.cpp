#include<iostream>
using namespace std;

    class Patient{


        int patientId;
        string name;
        int age;
        string ward;
        const string bloodGroup;

        public:
         
        Patient():bloodGroup("O+"){
           cout<<"[constructor] default patient registered"<<endl;
           patientId=0;
           name="Unknown";
           age=0;
           ward="General";
        }
         
         Patient(int id, const string& name){
            cout<<"[constructor] Emergency: ";

            this->patientId=id;
            this->name=name;
            cout<<name<<endl;
            this->ward=ward;
        }

        Patient(int id, const string& name, int age, const string& ward, const string& bg):bloodGroup(bg){
           cout<<"[constructor] Full Admission: ";
                patientId=id;
                this->name=name;
                this->age=age;
                this->ward=ward;
                cout<<name<<endl;
        }

        ~Patient(){
            cout<<"[Destructor]"<<"Patient "<<name<<" Discharged"<<endl;
        }

        void displayrecord() const{
         cout<<"Patient Record: " <<endl;  
        cout<<"PatientId   : "<<patientId<<endl;
        cout<<"Name        : "<<name<<endl;
        cout<<"Age         : "<<age<<endl;
        cout<<"Ward        : "<<ward<<endl;
        cout<<"Blood Group : "<<bloodGroup<<endl;


        }
        void transferWrad(const string& newWard){
        cout<<"Ward Transfer: "<<name<<" -> "<<newWard<<endl;
        ward=newWard;
        }





    };

    int main(){

        Patient ps1(1001, "Meera joshi",22,"Cardiology","B+");
        Patient ps2(1002, "Raj Patel");
        Patient ps3;

        Patient *ph= new Patient[4];

        for(int i=0; i<4; i++){
            ph[i].displayrecord();
          cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        ps1.displayrecord();
        cout<<endl;
        ps2.transferWrad("ICU");
        cout<<endl;
        cout<<endl;

        delete[] ph;


    }

