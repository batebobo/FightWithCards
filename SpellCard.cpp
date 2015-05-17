#include "SpellCard.h"

void SpellCard::setProperties(effects _effect, int _effectValue) { 


	if(_effect < dealDamageToCreature || _effect > healYourself) { 
		effect = dealDamageToCreature;
	}
	else { 
		effect = _effect;
	}
	
	switch(effect) { 
	case effects::dealDamageToCreature: 
			readOnlyEffect =  new char[18];
			strcpy(readOnlyEffect , "Just deals damage");
			break;
	case effects::dealDamageToHero: 
			readOnlyEffect = new char[15];
			strcpy(readOnlyEffect , "Damages hero");
			break;
	case effects::buffCreature: 
			readOnlyEffect = new char[17];
			strcpy(readOnlyEffect , "Buffs creature");
			break;
	case effects::healYourself: 
			readOnlyEffect = new char[26];
			strcpy(readOnlyEffect , "Restores HP to the player");
			break;
	}
	effectValue = _effectValue;
}

SpellCard::SpellCard(effects _effect, char* _name, int _number, int _cost,int _damage): Card(_name, _number, _cost) , readOnlyEffect(NULL){
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

void SpellCard::dealDamageToHero(Hero& hero) { 
	//player.hp -= damage;
}

void SpellCard::healHero(Hero& hero) { 
	//player.hp += damage;
}

SpellCard::SpellCard(const SpellCard& spellCard) : readOnlyEffect(NULL) { 
	int len = strlen(spellCard.getReadonlyEffectInformation());

	readOnlyEffect = new char[len + 1];
	strcpy(readOnlyEffect, spellCard.getReadonlyEffectInformation());

	effect = spellCard.getEffect();
	effectValue = spellCard.getEffectValue();
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

		effect = spell.getEffect();
		effectValue = spell.getEffectValue();
	}
	return *this;
}

void SpellCard::print() {
	printCard();
	cout<<"Effect : "<<readOnlyEffect<<endl;
	cout<<"Effect power : "<<effectValue<<endl;
}
