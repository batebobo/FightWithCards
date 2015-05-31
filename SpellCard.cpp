#include "SpellCard.h"

void SpellCard::setProperties(Effects _effect, int _effectValue) {


	if(_effect < dealDamageToCreature || _effect > healYourself) {
		effect = dealDamageToCreature;
	}
	else {
		effect = _effect;
	}

	switch(effect) {
	case dealDamageToCreature:
			readOnlyEffect =  new char[18];
			strcpy(readOnlyEffect , "Just deals damage");
			break;
	case damageHero:
			readOnlyEffect = new char[15];
			strcpy(readOnlyEffect , "Damages hero");
			break;
	case buffCreature:
			readOnlyEffect = new char[17];
			strcpy(readOnlyEffect , "Buffs creature");
			break;
	case healYourself:
			readOnlyEffect = new char[26];
			strcpy(readOnlyEffect , "Restores HP to the player");
			break;
	}
	effectValue = _effectValue;
}

SpellCard::SpellCard(Effects _effect, char* _name, int _number, int _cost,int _damage): Card(_name, _number, _cost) , readOnlyEffect(NULL){
	setProperties(_effect, _damage);
}

void SpellCard::dealDamageToMonster(Monster& creature) {
	if(effect == Effects::dealDamageToCreature) { 
		creature.setHealth(creature.getHealth() - effectValue);
	}
}

void SpellCard::dealDamageToHero(Hero* hero) {
	if(effect == Effects::damageHero) { 
		hero->setHealth(hero->getHealth() - effectValue);
	}
}

void SpellCard::healHero(Hero* hero) {
	if(effect == Effects::healYourself) {
		hero->setHealth(hero->getHealth() + effectValue);
	}
}

void SpellCard::buffMonster(Monster& monster) { 
	if(effect == Effects::buffCreature) {
		monster.setAttack(monster.getAttack() + effectValue);
	}
}


void SpellCard::useSpellCard(Monster& monster) { 
	switch(effect) { 
	case dealDamageToCreature: dealDamageToMonster(monster); break;
	case buffCreature: buffMonster(monster); break;
	}
}
void SpellCard::useSpellCard(Hero* hero) { 
	switch(effect) { 
	case damageHero: dealDamageToHero(hero); break;
	case healYourself: healHero(hero); break;
	}
}

SpellCard::SpellCard(const SpellCard& spellCard) :Card(spellCard), readOnlyEffect(NULL) {
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
