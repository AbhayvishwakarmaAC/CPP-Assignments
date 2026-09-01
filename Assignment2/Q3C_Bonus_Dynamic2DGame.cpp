#include<iostream>
using namespace std;


int level=1;

namespace Engine::Audio{
    string name;
    string playsound(string name){
          return name;
    }
}

int main(){

    int level=5; //player level

    cout<<"Game Difficulty level Start From "<<::level<<endl;
    cout<<"Palyer Level "<<level<<endl;
    

    cout<<"Playing Audio "<<Engine::Audio::playsound("sword_clash")<<endl;
    int row=3;
    int col=4;

    int **arr= new int*[row];

    cout<<"===== GAME MAP (3 x 4) ====="<<endl;

    for(int i=0; i<row; i++){
        arr[i]=new int[col];
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            int random=rand()%5;
            arr[i][j]=random;
        }
    }

    

    int Grass=0;
    int Water=0;
    int Mountain=0;
    int Forest=0;
    int Dungeon=0;


   
    

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
             if(arr[i][j]==0){
       
        Grass++;

    }else if(arr[i][j]==1){
        Water++;

    }
    else if(arr[i][j]==2){
        Mountain++;

    }
    else if(arr[i][j]==3){
        Forest++;

    }
    else if(arr[i][j]==4){
        Dungeon++;

    }
        }
        cout<<endl;
    }
        cout<<endl;
        cout<<"Legent: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon"<<endl;

        cout<<endl;

        cout<<"Tile Count: "<<endl;
        cout<<endl;

        cout<<"Grass    : "<<Grass<<endl;
        cout<<"Water    : "<<Water<<endl;
        cout<<"Mountain : "<<Mountain<<endl;
        cout<<"Forest   : "<<Forest<<endl;
        cout<<"Dungeon  : "<<Dungeon<<endl;


    
    

   for(int i=0; i<row; i++){
       delete[] arr[i];
    }

    delete[] arr;

}