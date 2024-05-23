#include <iostream>
#include "Dice.h"

using namespace std;

int main(){
    Dice * mydice = new Dice(); //Alternative declaration
    //Dice mydice;
    
    //cout<<"Result: "<<mydice.roll()<<"\n";
    cout<<"Result: "<<mydice->roll()<<"\n"; //Alternative call
    return 0;
}