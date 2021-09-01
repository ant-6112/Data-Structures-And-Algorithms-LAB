#include<bits/stdc++.h>
using namespace std;

#define PI 3.14
#define e 2.2718
#define Antrang "The Baddass Guy in The Whole World";

void dynamic_memmory(){
    int * foo;
    foo = new int [5];
    foo[0] = 10;
    foo[1] = 12;
    foo[2] = 59;
    foo[3] = 84;
    foo[4] = 48;
    cout<<*foo<<*(foo+1)<<*(foo+2)<<*(foo+3)<<*(foo+4)<<*(foo+5);
}

class Struct_Pointers
{
    private:
       struct Movie {
           string movie_name;
           int movie_timing;
           int ticket_price;
       };
       Movie mymovie;
    public: 
       void dosomething(){
            mymovie.movie_name = "Beauty";
            mymovie.movie_timing = 1300;
            mymovie.ticket_price = 500;
            Movie * ptr1;
            ptr1 = &mymovie;
            cout<<ptr1->ticket_price;
            cout<<ptr1->movie_timing;
            cout<<ptr1->ticket_price;
       }
        
}
using namespace std;
int main(){
    /*Hello:
    const int B = 98;
    cout<<B;
    goto Hello;*/

    /*long A[10] = {0,1,2,3,4,5,6,7,8,9};
    long * ptr;
    ptr = A;
    cout<<*ptr<<"\n";
    cout<<*(ptr+1)<<"\n";
    cout<<*(ptr+2)<<"\n";
    cout<<*ptr<<"\n";
    ptr = &(A[3]);
    cout<<*ptr<<"\n";
    ptr++;
    cout<<*ptr<<"\n";
    cout<<*(ptr-1)<<"\n";
    ptr--;
    cout<<*ptr<<"\n";
    ptr = &(A[7]);
    cout<<*ptr<<"\n";*/

    /*string B = "Hello";
    char c = 'H';
    char * ptr = &(c);
    char * ptr2 = &(B[0]);
    
    short C = 959;
    short * D;
    D = &(C);*/

    dynamic_memmory();

}
