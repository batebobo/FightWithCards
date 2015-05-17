#include<iostream>
#include "player.h"
using namespace std;

Player::Player(Mystring _name,Deck myDeck,Hero myHero):fatigue(0)
{
    cout<<"success";
    /*for(int i = 0 ; i<7;i++){
        field[i] = *new Card();
    }*/
}

void Player::print(){
    cout<<"Player name: "<<name;
    cout<<"Player field:\n";
    /*for(int i = 0 ;i<7;i++){
        cout<<"card "<<i<<endl;
        field[i].print();
    }*/
}

