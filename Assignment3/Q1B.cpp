#include<iostream>
#include<vector>
using namespace std;

    using Header= pair<string, string>;
    using HeaderList=vector<Header>;
    using Port= unsigned int;
    using IPAddress=  string;
    typedef unsigned long long RequestID;

void printHeaders(const HeaderList& headers){
    for(int i=0; i<3; i++){
     cout<<headers[i].first<<headers[i].second<<endl;
    }
        
}

int main(){

    RequestID id=1748293847;
    cout<<"Request ID :"<<id<<endl;
    Port p=8080;
    cout<<"Server Port :"<<p<<endl;
    IPAddress ip="192.168.1.1";
    cout<<"IP :"<<ip<<endl;
    cout<<endl;
    cout<<endl;
    
    HeaderList headers={
                     {"Content-Type    :","application/json"},
                     {"Authorization   :","Bearer eyjhbGci"},
                     {"Accept-Language :","en-US"},
                     };
    cout<<"Headers :"<<endl;
    printHeaders(headers);

}