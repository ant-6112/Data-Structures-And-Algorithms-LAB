#include<bits\stdc++.h>
using namespace std;

struct Node {
    int value;
    int * ptrnext;
};

int main(){
    Node SLLFirst[10];
    for(int i = 0;i<10;++i){
        SLLFirst[0].value = i+1;
        if(i<=8){
            SLLFirst[0].ptrnext = &SLLFirst[1].value;
        }else{
            SLLFirst[0].ptrnext = nullptr;
        }
    }

    //Transversing The List
    for(int j = 0;j<10;++j){
        cout<<SLLFirst[0];
    }
}

