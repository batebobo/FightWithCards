#include<iostream>
#include"card.h"
#include"deck.h"
using namespace std;
int main(){
    Card c1(15,150 ,"The walking horror",5);
    Card c2(20 , 500 , "The wrestler" , 2);
    Card c3(10 , 200 , "Dingo" , 1);
    Card c4(50 , 1 , "Explosive" , 4);
    Card c5(12 , 250 , "The Batka" , 3);
    Card* cards = new Card[30];
    for(int i = 0 ; i < 30 ; i++){
        if(i %5 ==0){
            cards[i] = c1;
        }
        if(i%5 == 1){
            cards[i] = c2;
        }
        if(i%5 == 2){
            cards[i] = c3;
        }
        if(i%5 == 3){
            cards[i] = c4;
        }
        if(i%5 == 4){
           cards[i] = c5;
        }
    }
    c1.print_card();
    Deck myDeck("Best deck EU" , cards);
    myDeck.shuffle();
    myDeck.printDeck();
    return 0;
}
