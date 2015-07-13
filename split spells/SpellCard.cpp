#include "SpellCard.h"
#include <string>
#include <map>

void SpellCard::setProperties(Effects _effect, int _effectValue) {

	if(_effect < DEAL_DAMAGE || _effect > INCREASE_HP) {
		effect = DEAL_DAMAGE;
	}
	else {
		effect = _effect;
	}

	switch(effect) {
	case DEAL_DAMAGE:
			readOnlyEffect =  new char[13];
			strcpy(readOnlyEffect , "Deals damage");
			break;
	case INCREASE_HP:
			readOnlyEffect = new char[17];
			strcpy(readOnlyEffect , "Increases health");
			break;
	}
	effectValue = _effectValue;
}

SpellCard::SpellCard(Effects _effect , char* _name, int _number, int _cost,int _damage): Card(_name, _number, _cost) , readOnlyEffect(NULL){
	setProperties(_effect, _damage);
}

void SpellCard::useCard(Player* current, Player* other)
{

	enum Options {HERO , MONSTER , OWN , ENEMY};
	map <string , Options> m;
	m["hero"] = HERO;
	m["monster"] = MONSTER;
	m["own"] = OWN;
	m["enemy"] = ENEMY;

	cout<<"Use spell card on hero or monster? ";
	string choice;
	cin>>choice;
	Options firstChoice = m[choice];
	cout<<endl;
	cout<<"Use spell card on enemy or own target? ";
	choice.clear();
	cin>>choice;
	Options secondChoice = m[choice];
	cout<<endl;
	bool swapped = false;
	if(secondChoice == OWN)
	{
		Player* temp = current;
		current = other;
		other = temp;
		swapped = true;
	}
	
	if(firstChoice == HERO)
	{
		if(effect == DEAL_DAMAGE)
			other->getHero()->setHealth(other->getHero()->getHealth() - effectValue);
		else
			other->getHero()->setHealth(other->getHero()->getHealth() + effectValue);
		if(!swapped)
		{
			current->changeMana(-getManacost());
			current->getHand().useCard(getNumber());
		}
		else
		{
			other->changeMana(-getManacost());
			other->getHand().useCard(getNumber());
		}
	}
	else if(firstChoice == MONSTER)
	{
		if(!(other->fieldIsEmpty()))
		{
			int monsterIndex;
			other->printField();
			cout<<endl;
			cout<<"Enter the number of the monster you want to use your spell card on : ";
			cin>>monsterIndex;
			if(effect == DEAL_DAMAGE)
			{
				other->getField()[monsterIndex]->setHealth(other->getField()[monsterIndex]->getHealth() - effectValue);
				if(other->getField()[monsterIndex]->getHealth() <= 0)
				{
					cout<<other->getField()[monsterIndex]->getName()<<" has died!"<<endl;
					other->removeCardFromField(monsterIndex);
				}
			}
			else
				other->getField()[monsterIndex]->setHealth(other->getField()[monsterIndex]->getHealth() + effectValue);
			if(!swapped)
			{
				current->changeMana(-getManacost());
				current->getHand().useCard(getNumber());
			}
			else
			{
				other->changeMana(-getManacost());
				other->getHand().useCard(getNumber());
			}
		}
		else if(other->fieldIsEmpty())
			cout<<"Player "<<other->getName()<<" has no monsters on his field!"<<endl;
	}
	else
		cout<<"Incorrect input!"<<endl;
}

SpellCard::SpellCard(const SpellCard& spellCard) :Card(spellCard), effectValue(spellCard.effectValue) , readOnlyEffect(NULL) {
	readOnlyEffect = new char[strlen(spellCard.readOnlyEffect) + 1];
	strcpy(readOnlyEffect , spellCard.readOnlyEffect);
}

SpellCard& SpellCard::operator=(SpellCard const& spell)
{
	if(this != &spell)
	{
		if(readOnlyEffect != NULL)
			delete[] readOnlyEffect;
		Card::operator=(spell);
		effectValue = spell.getEffectValue();
		readOnlyEffect = new char[strlen(spell.readOnlyEffect) + 1];
		strcpy(readOnlyEffect , spell.readOnlyEffect);
		
	}
	return *this;
}

SpellCard::~SpellCard()
{
	if(readOnlyEffect != NULL)
		delete[] readOnlyEffect;
}

void SpellCard::printSpell() {
	printCard();
	cout<<"Effect power : "<<effectValue<<endl;
}

/*void SpellCard::print()
{
	printSpell();
	cout<<"Effect : "<<readOnlyEffect<<endl;
	cout<<endl;
}*/