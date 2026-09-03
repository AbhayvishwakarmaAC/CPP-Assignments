#include<iostream>
using namespace std;

class Bonus{
     int Question;
     string level;
     string wantMore;
     mutable int accesscount=0;
     public:
     Bonus():Question(0), level(""), wantMore(""){
        cout<<"Mera Ho gaya Bas !!!!"<<endl;
     }

     void Setter(int Q, string l, string b){
            Question=Q;
            level=l;
            wantMore=b;
         
     } 

     int getA()const{
        accesscount++;
        return Question;
        
     }
     

     void print(){
        cout<<"Question :"<<Question<<endl;
        cout<<"level    :"<<level<<endl;
        cout<<"wantMore :"<<wantMore<<endl;
        cout<<"accesscount "<<accesscount<<endl;
     }


};

int main(){
  Bonus b;
  b.getA();
  b.getA();
  b.Setter(3,"Hard","Never");
  b.print();
}