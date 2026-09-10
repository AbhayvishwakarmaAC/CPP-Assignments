#include<iostream>
#include<iomanip>

using namespace std;

class LedgerEntry{
    string description;
    double * amounts;
    int days;
    
    public:
    static int totalEntries;

    // LedgerEntry(int days):days(days){ 
    //     amounts= new double[days];
    //     amounts[0]=0;
    //     totalEntries++;
    // }

    double totalamount()const{
        double total=0;
        for(int i=0; i<days; i++){
           total=total+amounts[i];
        }
        return total;
    }

    LedgerEntry(const string desc, int days):description(desc),days(days){
        
        amounts= new double[days];
        cout<<"[LedgerEntry Created]"<<" ";
        cout<<description<<" "<<days<<"days"<<endl;
        amounts[0]=0;
        totalEntries++;
    }
    //Deep Copy
    LedgerEntry(const LedgerEntry& l){
        days=l.days;
        description=l.description;
        amounts= new double[5];
        for(int i=0; i<days;++i){
            amounts[i]=l.amounts[i];
        }   

    }
    // Move Constuctor 
    LedgerEntry(LedgerEntry&& other) noexcept{
           description = other.description;
           days=other.days;
           amounts=other.amounts;
           cout<<"[Move Constructor] Ownerhsip Transferred from: "<<other.description<<endl;
           other.amounts=nullptr;
           
    }

    double& operator[](int index){
            if(index<0||index>=days){
                throw out_of_range(" index out of bound");
            }
            return amounts[index];
    }
      // Asiignment copy
    LedgerEntry operator+(const LedgerEntry& addition){
        LedgerEntry comb(days);
         for(int i=0; i<days; i++){
            comb.amounts[i]=amounts[i]+addition.amounts[i];
         }
          return LedgerEntry(comb);
                             
    }
      // Asiignment moved 
    LedgerEntry& operator=(LedgerEntry && other){
         if(this != &other){
            delete[] amounts;
            amounts= other.amounts;
            other.amounts=nullptr;
         }
         return *this;
    }


    bool movedfrom(){
        return amounts==nullptr;
    }

    bool operator==(const LedgerEntry& other) const{
          for(int i=0; i<days; i++){
            if(totalamount()==other.totalamount()){
                return true;
            }
          }
          return false;
          
    }
    bool operator>(const LedgerEntry& other) const{
             for(int i=0; i<days; i++){
            if(totalamount()>other.totalamount()){
                return true;
            }
          }
          return false;
    }

    friend ostream& operator<<(ostream& out, const LedgerEntry& entry);

    ~LedgerEntry(){
        cout<<"[Destructor] "<<description<<" destroyed"<<endl;
        delete[] amounts;
        totalEntries--;
    }

};
ostream& operator<<(ostream& out, const LedgerEntry& entry){
    // cout<<fixed<<setprecision(2);
    // double sum=0;
    // for(int i=0; i<entry.days; ++i){
    //     sum=sum+entry.amounts[i];
    // }  
    out<<entry.description<<" : ["; for(int i=0; i<entry.days; ++i){
        out<<entry.amounts[i]<<" ";
    }out<<"]"<<" Total: "; out<<entry.totalamount()<<endl;
    
    return out;
}

int LedgerEntry::totalEntries=0;

int main(){
   LedgerEntry jan("January Sales", 5);
   jan[0]=1200.50;
   jan[1]=3400.00;
   jan[2]=800.75;
   jan[3]=2100.00;
   jan[4]=650.25;
   LedgerEntry feb("February Sales", 5);
   feb[0]=900.00;
   feb[1]=2200.50;
   feb[2]=1750.00;
   feb[3]=3000.00;
   feb[4]=475.50;
   cout<<jan<<endl;
   cout<<feb<<endl;
   LedgerEntry combined=jan+feb;
   cout<<"Combined "<<combined<<endl;

   cout<<"Jan == Feb  : "<< (jan==feb? "Yes" : "No")<<endl;
   cout<<"Jan  > Feb  : "<< (jan>feb? "Yes" : "No")<<endl;

   LedgerEntry moved=move(jan);
   cout<<"After move, jan.amount is null: "<<(jan.movedfrom()? "Yes": "No")<<endl;
   cout<<"Moved entry: "<<moved<<endl;

   LedgerEntry q1("Q1 total",5);
  q1=move(feb); 
  cout<<"Q1 (moved from feb): "<<q1<<endl;

  cout<<"Live LedgerEntry objects: "<<LedgerEntry::totalEntries<<endl;

}