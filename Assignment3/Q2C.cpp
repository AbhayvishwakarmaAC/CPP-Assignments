#include<iostream>
#include<memory>

using namespace std;

class AudioClip{
    string name;
    double time;

    public:
    AudioClip(){

    }
    AudioClip(string name, double time):name(name),time(time){
        cout<<"Audio uploading"<<endl;
    }
    ~AudioClip(){
        cout<<"Audio uploadded"<<endl;
    }
    string getName(){
      return name;
    }

};

int main (){
    shared_ptr<AudioClip> audioclip=make_shared<AudioClip>("explosion",3.5);
    weak_ptr<AudioClip> observer=audioclip;
    
    if(auto clip=observer.lock()){
        cout<<"Clip alive: "<<clip->getName()<<endl;
        
    }
    audioclip.reset();

    if(observer.expired()){
        cout<<"Clip already unloaded. "<<endl;
    }
}