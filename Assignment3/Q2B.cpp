#include<iostream>
#include<memory>
using namespace std;

class Shader{
    string name="vertex";
    string type="fragment";
    public:

    Shader(){
      cout<<"Default Constructor"<<endl;
    }
    Shader(string name, string type):name(name),type(type){
        cout<<"Shadar Compiled"<<endl;
    }
    ~Shader(){
        cout<<"Shadar Destroyed"<<endl;
    }
    // int getReferenceCount(shared_ptr<Shader> usecount){
    //     return usecount.use_count();
    // }
    // int getReferenceCount(shared_ptr<Shader> &usecount){
    //     return usecount.use_count();
    // }
     int getReferenceCount(shared_ptr<Shader> *usecount){
        return usecount->use_count();
    }


};

int main(){

    auto shader=make_shared<Shader>("main_vert","vertex");
    cout<<"Ref count: "<<shader.use_count()<<endl;
    {
    shared_ptr<Shader> simulatingrender=shader;
    cout<<"Ref count: "<<shader.use_count()<<endl;
    shared_ptr<Shader> editorsharing=shader;
    cout<<"Ref count: "<<shader.use_count()<<endl;
    }
    cout<<"Ref count: "<<shader.use_count()<<endl;
    cout<<"Get Refrence count is: "<<shader->getReferenceCount(&shader)<<endl;;
}