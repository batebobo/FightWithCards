#ifndef Hero_H_
#define Hero_H_
using namespace std;

// ðàçáèâàíå íà êëàñîâå è äîáàâÿíå íà âèðòóàëíè ôèíêöèè
class Hero
{
private:
	int health;
	char* name;
	int skill_manacost;
	bool has_attacked;
public:
	Hero(char* = "Priest" , int = 30 , int = 2 , bool = false);
	Hero (Hero const&);
	Hero& operator=(Hero const&);
	~Hero();

	int getHealth() const { return health; }
	char* getName() const { return name; }
	int getSkillManacost() const{return skill_manacost;}
	bool hasAttacked() const{ return has_attacked;}

	virtual void print() const{}
	void printHero() const;
	void setName(char*);
	void setHealth(int);
	void setHasAttacked(bool);

	virtual bool hasDifferentTargets() const{return false;}
	virtual void usePower(Hero* , Monster* , int){} // gets hero , monster and 0 to use power on hero or 1 to use power on monster
};

#endif
