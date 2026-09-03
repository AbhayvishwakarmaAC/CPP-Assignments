#include<iostream>
#include<memory>
using namespace std;

class Texture{
    string name;
    int width;
    int height;
    public:
    Texture(){
        cout<<"Default Texture Loaded"<<endl;
    }
    Texture(string name,int width, int height):name(name),width(width),height(height){
        cout<<"Texture Loaded"<<endl;
    }

    ~Texture(){
        cout<<"Texture Released"<<endl;
    }

    void display()const{
        cout<<"name "<<name<<endl;
        cout<<"Width "<<width<<endl;
         cout<<"Height "<<height<<endl;
    }
};


int main(){
       
    unique_ptr<Texture> texture=make_unique<Texture>("player_sprite",512,512); 
    texture->display();

    // unique_ptr<Texture> texture1=texture;
    //  note: use '-fdiagnostics-all-candidates' to display considered candidates
//    34 |     unique_ptr<Texture> texture1=texture;

//  Explanation : Texture Can not be Shared or copied Beacuse Unique have only One Onwer 
    
unique_ptr<Texture> texture1=move(texture);
cout<<"texture is null: "<<(texture==nullptr? "Yes":"No")<<endl;
}