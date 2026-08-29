#include<iostream>
#include<cmath>
using namespace std;

double computeRMS(double *signal , int n){
    
    double squaresum=0;
    for(int i=0; i<n; i++){
    // cout<<*(signal+i)<<endl;
    squaresum=squaresum+(*((signal+i))*(*(signal+i)));
    }
    // cout<<squaresum<<endl;
    double squarerrot=sqrt(squaresum);
    return squarerrot/2;

}
void normalise(double* signal,int n ){

    double maximum=*signal;
    
    for(int i=0; i<n; i++){
    maximum=max(maximum,abs(*(signal+i)));
    }

     for(int i=0; i<n; i++){
    *(signal+i)=*(signal+i)/maximum;
    }
    
}
int countZeroCrossing(double* signal,int n ){
   int count=0;
    
   for(int i=0; i<n-1; i++){
    // if(*(signal+i)>0 ^ *(signal+i+1)>0){
    if(*(signal+i)*(*(signal+i+1))<0)
      count++;
    }

    return count;   

    
}
void applyGain(double* signal,int n, double gain ){

    for(int i=0; i<n; i++){
     *(signal+i)=(*(signal+i)*gain);
    }
}


int main(){

    cout<<"Enter the Number of Element"<<endl;
    int n;
    cin>>n;
    double arr[n];
    double gainfactor=1.2;

    for(int i=0; i<n; i++){
       cin>>arr[i];
    }
    cout<<"------------------------------"<<endl;
    double res=computeRMS(arr,n);
    cout<<"Value Retuen by computeRMS: "<<res<<endl;
    cout<<"------------------------------"<<endl;

    cout<<"Values before normalise"<<endl;
     for(int i=0; i<n; i++){
       cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    cout<<"------------------------------"<<endl;
     normalise(arr,n);

    cout<<"Values after normalise"<<endl;
     for(int i=0; i<n; i++){
       cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"------------------------------"<<endl;
    int count=countZeroCrossing(arr,n);
    cout<<"Count of Element have opposite signs: "<<count<<endl;
    cout<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Values before applyGain"<<endl;
     for(int i=0; i<n; i++){
       cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"------------------------------"<<endl;

    applyGain(arr,n,gainfactor);

    cout<<"Values after applyGain"<<endl;
     for(int i=0; i<n; i++){
       cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"------------------------------"<<endl;
    
    return 0;

//0.5 -1.2 0.8 -0.3 1 -0.9 0.1 
}