#include<iostream>
#include<string>
using namespace std;


enum class HttpStatus{
 OK=200,
 Created=201,
 BadRequest=400,
 Unauthorized=401,
 NotFound=404,
 ServerError=500,
};

void handleResponse(HttpStatus status, const string& endpoint){


    
    switch(static_cast<int>(status)){
        case 200: cout<<endpoint<<"\t--> "<<static_cast<int>(status)<<" OK\t\t: Request successful"<<endl;
               break;
        case 201:cout<<endpoint<<"\t--> "<<static_cast<int>(status)<<" Created\t\t: User created successfully"<<endl;
               break;
        case 400:cout<<endpoint<<"\t--> "<<static_cast<int>(status)<<" BadRequest\t: Invalid request data"<<endl;
               break;
        case 401:cout<<endpoint<<"\t--> "<<static_cast<int>(status)<<" Unauthorized\t: Authentication required"<<endl;
               break;
        case 404:cout<<endpoint<<"\t--> "<<static_cast<int>(status)<<" NotFound\t: User not found"<<endl;
               break;
        case 500:cout<<endpoint<<"\t--> "<<static_cast<int>(status)<<" ServerError\t: Internal server error"<<endl;
             break;
        default:break;                                               
                  
    }
}




int main(){


    handleResponse(HttpStatus::OK,"[GET/api/products/99]");
    handleResponse(HttpStatus::Created,"[POST /api/user]");
    handleResponse(HttpStatus::BadRequest,"[POST /api/users]");
    handleResponse(HttpStatus::Unauthorized,"[GET /api/users/99]");
    handleResponse(HttpStatus::NotFound,"[GET /api/users/99]");
    handleResponse(HttpStatus::ServerError,"[GET /api/users/99]");

}