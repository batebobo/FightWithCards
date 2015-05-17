#include <iostream>
/*#include "hand.h"
#include "monster.h"
#include "SpellCard.h"
#include "deck.h"
#include "Card.h"*/
#include "hand.h"
#include "monster.h"
#include "deck.h"
#include "Card.h"
#include "SpellCard.h"
using namespace std;
int main()
{
	Card a("aa" , 5 ,5) , b("bb" , 15 ,15) , c("cc" , 16 ,16);
	Monster m("meca" , 5 , 5 , 10 , 10) , mm("test" , 6 , 6 , 11 , 11);
	SpellCard spell(SpellCard::dealDamageToCreature , "spell", 1 , 1, 12);
	Card s[30];
	for(int i = 0 ; i < 30 ; i +=3)
	{
		s[i] = m;
		s[i+1] = mm;
		s[i+2] = spell;
	}
	Deck deck("teste" , s);
	Hand raka(m,mm,spell);
	deck.shuffle();
	raka.printHand();
	raka.drawCard(deck);
	cout<<"!!!!!!!!!!!"<<endl;
	raka.printHand();
	system("pause");
	return 0;
}