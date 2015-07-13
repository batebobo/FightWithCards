// game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "battle.cpp"
#include "hand.cpp"
#include "monster.cpp"
#include "deck.cpp"
#include "Card.cpp"
#include "SpellCard.cpp"
#include "Hero.cpp"
#include "player.cpp"
#include "priest.cpp"
#include "mage.cpp"
#include "warrior.cpp"
#include "hunter.cpp"
#include "damage_hero_spell.cpp"
#include "heal_hero_spell.cpp"
#include "damage_monster_spell.cpp"
#include "heal_monster_spell.cpp"

using namespace std;


int main()
{
	system("color 2");
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
    
    DamageHeroSpell darkbomb("Dark Bomb", 15, 2, 3);
   /* SpellCard arcaneshot("Arcane Shot", 16, 1, 2);
    SpellCard fireball("Fireball", 17, 4, 6);
    SpellCard pyroblast("Pyroblast", 18, 10, 10);
    SpellCard blessing("Blessing of Kings", 19, 4, 4);*/
    HealHeroSpell healing("Healing Touch", 20, 3, 8);
	DamageMonster damage("damage",21,1,1);
	HealMonster heal("heal",22,1,1);
   
    Card* cards[30];
    for(int i = 0 ; i<30;i += 6){
            cards[i] = new Monster(murloc);
            cards[i + 1] = new Monster(rager);
			cards[i + 2] = new DamageHeroSpell(darkbomb);
			cards[i + 3] = new HealHeroSpell(healing);
			cards[i + 4] = new HealMonster(heal);
			cards[i + 5] = new DamageMonster(damage);
    }
	 Card* cards2[30];
   for(int i = 0 ; i<30;i += 6){
            cards2[i] = new Monster(murloc);
            cards2[i + 1] = new Monster(rager);
			cards2[i + 2] = new DamageHeroSpell(darkbomb);
			cards2[i + 3] = new HealHeroSpell(healing);
			cards2[i + 4] = new HealMonster(heal);
			cards2[i + 5] = new DamageMonster(damage);
    }
    Deck myDeck("best deck eu",cards);
	Deck PcDeck("pc" , cards2);
	//myDeck.shuffle();
	//PcDeck.shuffle();
	Hero* mage = new Mage;
	Hero* hunter = new Hunter;
	Deck newDeck = myDeck;
	Player Player1("Player1" , myDeck , mage);
	Player Player2("Player2" , PcDeck , hunter);
	
	Battle b1(Player1 , Player2 , 1);
	b1.beginBattle();
	system("pause");
    return 0;
}