#include<iostream>
#include<string>
using namespace std;

// ./sensor_monitor

int main(int argc, char* argv[]){

    if(argc<4){
         
        cout<<"Usage: ./sensor_monitor <warm_threshold> <critical_threshold> <num_readings>"<<endl;
        cout<<"Eror : Missing arguments."<<endl;
        return 1;
    }

   double warn=stod(argv[1]);
   double critical=stod(argv[2]);
   double readings=stod(argv[3]);

   int normal=0;
   int warning=0;
   int criticall=0;
   int shutdown=0;
    
   if(warn>=critical){
    cout<<"Error: Warning cannot be Greater or equal than critical"<<endl;
   }else if(1>=readings && readings<=500){
    cout<<"Error: Reading is out of Scope"<<endl;
   }else{
       
     
     for(int i=0; i<=9; i++){
      double readings=rand()%70;
     if(readings>=0 && readings<warn){
        normal++;
     }else if(readings>=warn && readings<critical){
        warning++;
     }else if(readings>=critical && readings<=59){
        criticall++;
     }else{
        shutdown++;
     }
    }
   }
   
   cout<<"Config : "<<"Warn= "<<warn<<" Critical= "<<critical<<" Readings= "<<readings<<endl;
   cout<<"Resut  : "<<"Normal: "<<normal<<" Warning: "<<warning<<" Critical: "<<criticall<<" Shutdown: "<<shutdown<<endl;

}