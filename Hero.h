#ifndef Hero_H_
#define Hero_H_
using namespace std;


class Hero
{
private:
	int health;
	char* name;
public:
	Hero(char* = "Priest" , int = 30);
	Hero (Hero const&);
	Hero& operator=(Hero const&);
	~Hero();

	int getHealth() const { return health; }
	char* getName() const { return name; }

	void print() const;
	void setName(char*);

	void attack(Hero&);
	void heal();
	void usePower(Hero&);
};

#endif
