#include<iostream>
#include<string>
#include<cmath>
#include <iomanip>
using namespace std;

class Employee{

    int empId=1001;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;
    static int employeeCount;

    static int nextEmpId;

        public:
         Employee()
    {
        empId = nextEmpId++;
        employeeCount++;
    }
    



        void setName(const string& n){

            if(n.empty()){
                cout<<"Name can not be empty"<<endl;}
                else {
                    name=n;
                }
        }

        void setDepartment(const string& dept){

            if(dept=="Engineering" || dept=="HR" ||dept=="Fi"||dept=="Finance")
            {
            department=dept;}
            else {
                cout<<"Error: '"<<dept<<"' is not a registered department."<<endl;
            }
        }
        void setGrade(char g){

            if(g=='A'||g=='B'||g=='C'||g=='D'){
            grade=g;}
            else{
            cout<<"ERROR: Invalid grade '"<<g<<"'. Accepted values: A, B, C, D"<<endl;
            }
        }
        void setBasicSalary(double salary){

            if(salary<10000||salary>500000){
             cout<<"ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected."<<endl;
            }else{
             basicSalary=salary;
            }
        }
        void deactivate(){
            isActive=false;
        }


        int getEmpId() const{
             return empId;
        }

        string getName()const{
            return name;
        } 
        string getDepartment()  const{
            return department;
        }
        char getGrade() const{
            return grade;}
        double getBasicSalary() const{
            return basicSalary;}
        bool getIsActive() const{
          return isActive;}

          static int getEmployeeCount() {
               return employeeCount--;
            }

        double computeAllowances() const{
            switch(grade){
                 case 'A':
                 return basicSalary*0.40;
                          
                 case 'B':
                 return basicSalary*0.30;
                          
                 case 'C':
                 return basicSalary*0.20;
                          
                 case 'D':
                 return basicSalary*0.10;
                          
                
                  default:
                  return 0;
                      

            }
        }

        double computeGrossSalary() const{
            
              return basicSalary+computeAllowances();
        }
        double computeTax() const{

            if(computeGrossSalary()<=50000){
                return computeGrossSalary()*0;
             }else if(computeGrossSalary()>50000&&computeGrossSalary()<=100000){
                
                  return computeGrossSalary()*0.1;
             }else{
                     return (computeGrossSalary()*0.10)-5000;
             }

             }

             double computeNetSalary() const{

                return computeGrossSalary()-computeTax();
             }
        

            void acceptDetails(){
                cout << fixed << setprecision(2);
                cout<<"Enter Employee Name"<<endl;
                string inputname;
                cin.ignore();
                getline(cin,inputname);  
                setName(inputname);
                cout<<"Enter Employee Department"<<endl;
                string inputdepartment;
                cin>>inputdepartment;
                setDepartment(inputdepartment);
                cout<<"Enter Employee Grade"<<endl;
                char inputGrade;
                cin>>inputGrade;
                setGrade(inputGrade);
                cout<<"Enter Employee Basic Salary"<<endl;
                double inputSalary;
                cin>>inputSalary;
                setBasicSalary(inputSalary);

             }
            void printPayslip() const{
                cout<<boolalpha;

                cout<<"============================================"<<endl;
                cout<<"        EMPLOYEE PAYSLIP -- AUG 2026         "<<endl;
                cout<<"============================================"<<endl;

                cout<<"Emp ID     : "<<empId<<endl;
                cout<<"Name       : "<<name<<endl;
                cout<<"Department : "<<department<<endl;
                cout<<"Grade      : "<<grade<<endl;

                if(isActive){
                    cout<<"Status     : Active"<<endl;
                }else cout<<"Status     : Deactivated"<<endl;

                cout<<"--------------------------------------------"<<endl;
                cout<<"Basic Salary : "<<basicSalary<<endl;

                  cout << "Allowances ("<<(computeAllowances() / basicSalary) * 100<<"%)"<< ": Rs. " << computeAllowances() << endl;
                 cout <<"Gross Salary"<< ": Rs. " << computeGrossSalary()<<endl;
                   
                cout<<"--------------------------------------------"<<endl;
                   cout<<"Tax Deduction : "<<computeTax()<<endl;
                   cout<<"Net Salary    : "<<computeNetSalary()<<endl;
                cout<<"============================================"<<endl;
            }


};

int Employee::employeeCount = 0;
int Employee::nextEmpId = 1001;


int main(){

    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    
    //   Try uncommenting — observe the compiler error, then explain in a comment 
    //  why
// e1.empId = 999;    error: 'int Employee::empId' is private within this context
// //                     206 | e1.empId = 999;

// e1.basicSalary = -1000;   // error: 'double Employee::basicSalary' is private within this context
//                           // 207 | e1.basicSalary = -1000;
//                           //Beacuse the Basic Salary Inside Class kept in Private

   e1.printPayslip();
   e2->printPayslip();
   e3->printPayslip();
  

    e3->deactivate();
    if (!e3->getIsActive())
    cout << e3->getName() << " is no longer active. Payroll skipped." << endl;
    cout << "Total Employees : " << Employee::getEmployeeCount() << endl;
    delete e2;
    delete e3;
    return 0;

}