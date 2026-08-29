#include<iostream>
using namespace std;
#include <stdio.h>

struct Layout1 {
    char c1;
    int i;
    char c2;
};

struct Layout2 {
    int i;
    char c1;
    char c2;
};

int main(void) {
    cout<<"sizeof(Layout1 = " <<sizeof(struct Layout1)<<endl;
    cout<<"sizeof(Layout2 = " << sizeof(struct Layout2)<<endl;


    /*Explanation 

    Q1. Size Diffrer Beacuse In Layout 1 The Order is int=4byte char=1byte int=4byte 
    So total will be 9 So Compiler Will Add Apdding 3 to make it 12 bytes So that it will be Easy to handle for Compiler
    But in layout 2 the order of defining is int=4 char=1 char=1 So total 6byte 
    So Compiler Add 2byte padding So that it will be 8 byte to handle efficienty

    Q2.Padding is Extra btye added to make Merrory Size Equal So that Compiler can handle it efficienty

    Q3. Beause if We keep order in changing dataype eg int Char int Double So compiler Give Padding Char +3 So the Memeroy utilization will be more 
    but if we keep in order Int Int Double double char char so compiler first Calculate int size then double then char and add minimum padding required So 
    Size will be less and Compiler also can handle efficiently

    */

}
