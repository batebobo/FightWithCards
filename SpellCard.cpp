#include "stdafx.h"
#include "SpellCard.h"


void SpellCard::setProperties(int _effect, int _damage) { 
	if(_effect < 0 || _effect > 5) { 
		effect = 0;
	}
	else { 
		effect = _effect;
	}
	
	switch(effect) { 
		case 0: 
			readOnlyEffect =  new char[18];
			strcpy(readOnlyEffect , "Just deals damage");
			damage = _damage;
			break;
		case 1: 
			readOnlyEffect = new char[13];
			strcpy(readOnlyEffect , "Just freezes"); 
			break;
		case 2: 
			readOnlyEffect = new char[25];
			strcpy(readOnlyEffect , "Deals damage and freezes"); 
			damage = _damage;
			break;
		case 3: 
			readOnlyEffect = new char[15];
			strcpy(readOnlyEffect , "Damages player");
			damage = _damage;
			break;
		case 4: 
			readOnlyEffect = new char[17];
			strcpy(readOnlyEffect , "Destroys monster");
			break;
		case 5: 
			readOnlyEffect = new char[26];
			strcpy(readOnlyEffect , "Restores HP to the player");
			break;
	}
}

SpellCard::SpellCard(char* _name, int _number, int _cost, int _effect, int _damage): Card(_name, _number, _cost) , readOnlyEffect(NULL){
	setProperties(_effect, _damage);
}

void SpellCard::freezeMonster(Monster& creature) {
	//creature.changeStateTo("frozen");
}

void SpellCard::dealDamageToMonster(Monster& creature) { 
	if(effect == 0 || effect == 2) { 
		//creature.hp -= damage
	}
	if(effect == 2) { 
		freezeMonster(creature);
	}
	if(effect == 4) { 
		//creature.hp = 0;
	}
}

void SpellCard::dealDamageToPlayer(Player& player) { 
	//player.hp -= damage;
}

void SpellCard::healPlayer(Player& player) { 
	//player.hp += damage;
}

SpellCard::SpellCard(const SpellCard& spellCard) : readOnlyEffect(NULL) { 
	int len = strlen(spellCard.getReadonlyEffectInformation());

	readOnlyEffect = new char[len + 1];
	strcpy(readOnlyEffect, spellCard.getReadonlyEffectInformation());

	effect = spellCard.getEffectNumber();
	damage = spellCard.getDamageInformation();
}

SpellCard::~SpellCard()
{
	if(readOnlyEffect != NULL)
		delete[] readOnlyEffect;
}

SpellCard& SpellCard::operator=(SpellCard const& spell)
{
	if(this != &spell)
	{
		int len = strlen(spell.getReadonlyEffectInformation());
		if(readOnlyEffect != NULL)
			delete[] readOnlyEffect;
		readOnlyEffect = new char[len + 1];
		strcpy(readOnlyEffect, spell.getReadonlyEffectInformation());

		effect = spell.getEffectNumber();
		damage = spell.getDamageInformation();
	}
	return *this;
}

void SpellCard::print() {
	printCard();
	cout<<"Effect : "<<readOnlyEffect<<endl;
	cout<<"Effect power : "<<damage<<endl;
}
