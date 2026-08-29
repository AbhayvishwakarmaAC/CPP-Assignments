#include<iostream>
#include<cmath>
using namespace std;

// 22.1 31.5 46 28 50.2 10 38 -16
int main(){

    cout<<"Enter the Values from 1 to 100"<<endl;
     int count=0;
     int n;
     cin>>n;
     double arr[n];

    

     for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
         
      cin>>arr[i];

     }
     float arraysum=0;
     double t_min=arr[0];
     double t_max=arr[0];
     double t_average=0;

     int normal=0;
     int warning=0;
     int critical=0;
     int shutdown=0;

     cout<<"Reading entered : "<<n<<endl;
     cout<<"Valid reading   : ";

     for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
      if(arr[i]<0){
        count++;
           continue;
      }
      cout<<arr[i]<<" ";

         t_min=min(t_min,arr[i]);
         t_max=max(t_max,arr[i]);
         arraysum = arraysum+arr[i];

         if(arr[i]>0 && arr[i]<=29){
            normal++;
         }else if(arr[i]>-30 && arr[i]<=44){
            warning++;
         }else if(arr[i]>=45 && arr[i]<=59){
            critical++;
         }else{
            shutdown++;
         }
       
     }
     t_average=arraysum/((sizeof(arr)/sizeof(arr[0])-count));


     
     cout<<endl;
     cout<<"Skipped (Error) : "<<count<<endl;
     cout<<endl;
     cout<<endl;

     for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
      if(arr[i]>=45){
        cout<<"fist CRITICAL   : "<<"index "<<i<<" --> "<<arr[i]<<" *C"<<endl;
        break;
        }
       
     }

     cout<<endl;
     cout<<endl;

    
    cout<<"Min : "<<t_min<<" *C   Max : "<<t_max<<" *C  Avg : "<<t_average<<" *C"<<endl;;
    
    cout<<"Normal : "<<normal<<"   Warning : "<<warning<<"   Critical : "<<critical<<"   Shutdown : "<<shutdown<<endl;



}