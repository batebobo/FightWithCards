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
    Monster murloc("Murloc Raider",1,1,2,1);
    Monster raptor("Bloodfen Raptor",2,2,3,2);
    Monster tank("Spider Tank", 3, 3, 3, 4);
    Monster yeti("Chillwind Yeti", 4, 4, 4, 5);
    Monster dog("Salty Dog", 5, 5, 7, 4);
    Monster ogre("Boulderfist Ogre", 6, 6, 6, 7);
    Monster golem("War Golem", 7, 7, 7, 7);
    Monster croco("River Crocolisk", 8, 2, 2, 3);
    Monster hound("Core Hound", 9, 7, 9, 5);
    Monster strider("Lost Tallstrider", 10, 4, 5, 4);
    Monster rager("Magma Rager", 11, 3, 5, 1);
    Monster snapjaw("Oasis Snapjaw", 12, 4, 2, 7);
    Monster stomper("Puddlestomper", 13, 2, 3, 2);
    Monster wisp("Wisp", 14, 0, 1, 1);
    
    SpellCard darkbomb(SpellCard::damageHero,"Dark Bomb", 15, 2, 3);
    SpellCard arcaneshot(SpellCard::damageHero, "Arcane Shot", 16, 1, 2);
    SpellCard arcaneshot(SpellCard::damageHero, "Fireball", 17, 4, 6);
    SpellCard pyroblast(SpellCard::damageHero, "Pyroblast", 18, 10, 10);
    SpellCard blessing(SpellCard::buffCreature, "Blessing of Kings", 19, 4, 4);
    SpellCard healing(SpellCard::healYourself, "Healing Touch", 20, 3, 8);
    
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
