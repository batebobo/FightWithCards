#include<iostream>
#include "player.h"
using namespace std;

Player::Player(Mystring _name,Deck &myDeck,Hero myHero):name(_name),deck(myDeck),hero(myHero),fatigue(0),monstersInField(0)
{

}

void Player::print(){
    cout<<"Player name: "<<name<<endl;
    cout<<"Player field:\n";
    for(int i = 1 ;i<=monstersInField;i++){
        cout<<"card "<<i<<endl;
        field[i].print();
    }
    cout<<"player deck:\n";
    deck.printDeck();
}
void Player::useCard(int positionInHand){
    field[monstersInField] = hand[positionInHand];
    monstersInField++;
}
