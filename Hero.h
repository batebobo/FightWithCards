#ifndef Hero_H_
#define Hero_H_
#include <string>
using namespace std;

class Hero
{
private:
	int health;
	string name;
	string power;
public:
	Hero();
	Hero (int, string, string);
	Hero (const Hero& other);
	Hero& operator=(const Hero& other);
	~Hero();
	int getHealth() const { return health; }
	string getName() const { return name; }
	string getPower() const { return power; }
	void print() const;
	void set();
};

#endif
