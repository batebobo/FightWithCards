#ifndef Hero_H_
#define Hero_H_
using namespace std;

// разбиване на класове и добавяне на виртуални финкции
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

	void print() const;
	void setName(char*);
	void setHealth(int);

	void attack(Hero&);
	void heal();
	void usePower(Hero&);
};

#endif
