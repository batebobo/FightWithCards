// game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "battle.h"
#include "battle.cpp"
#include "hand.cpp"
#include "monster.cpp"
#include "deck.cpp"
#include "Card.cpp"
#include "SpellCard.cpp"
#include "Hero.cpp"
#include "player.h"
#include "player.cpp"

using namespace std;


int main()
{
    Monster murloc("murloc",1,1,3,4);
    SpellCard frostbolt(SpellCard::damageHero,"frostbolt",2,2,3);
    Card* cards[30];
    for(int i = 0 ; i<30;i++){
        if(i%2==0){
            cards[i] = new Monster(murloc);
        }
		else{
            cards[i] = new SpellCard(frostbolt);
        }
    }
	 Card* cards2[30];
    for(int i = 0 ; i<30;i++){
        if(i%2==0){
            cards2[i] = new Monster(murloc);
        }
		else{
            cards2[i] = new SpellCard(frostbolt);
        }
    }
    Deck myDeck("best deck eu",cards);
	Deck PcDeck("pc" , cards2);
    Hero hunter("Hunter");
	Hero priest("Priest");
	Deck newDeck = myDeck;
	Player Player1("Player1" , myDeck , hunter);
	Player Player2("Player2" , PcDeck , priest);
	
	Battle b1(Player1 , Player2 , 1);
	b1.beginBattle();
	system("pause");
    return 0;
}