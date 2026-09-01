#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Entity{
    string name;
    int health;
    int level;
    string type;

    public:

    Entity &setName(const string &name){
        this->name=name;
        return *this;

    }
     Entity &setHealth(int health){
        this->health=health;
        return *this;
 
        
    }
     Entity &setLevel(int level){
        this->level=level;
        return *this;

        
    }
     Entity &setType(const string &type){
        this->type=type;
        return *this;

        
    }



    string getName()const{

        return name;


    }
    int getHealth()const{
      
        return health;

    }
    int getLevel()const{
        return level;


    }
     string getType()const{

        return type;


    }


    void displayInfo() const{

        cout<<name<<" "<<health<<" "<<level<<" "<<type<<endl;
       

    }


};


namespace Physics{
         
    double clamp(double val, double min, double max){
        
        if(val>max){
            return max;
        }else if(val<min){
            return min;
        }else return val;

    }
    double lerp(double a, double b, double t){ 

        return a+(b-a)*t;
    }

}

namespace GameMath{

    int clamp(int val, int min, int max){

        if(val>max){
            return max;
        }else if(val<min){
            return min;
        }else return val;

        

    }
    double lerp(double a, double b, double t){

        return a+(b-a)*t;
        
    }


}



int main(){
     
       Entity player;
       Entity enemy;
       Entity item;


    player.setName("Aragron").setHealth(100).setLevel(10).setType("Player");
    enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();
     
 
    cout<<"Clamp for Physics "<<Physics::clamp(14,5,35)<<endl;
    cout<<"lerp for Physics "<<Physics::lerp(0,95,0.3)<<endl;

    cout<<endl;

    cout<<"Clamp For GameMath "<<GameMath::clamp(17,0,19)<<endl;
    cout<<"lerp for Physics "<<GameMath::lerp(0,100,0.5)<<endl;


    
}