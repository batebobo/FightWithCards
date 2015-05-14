#ifndef MONSTER_H_
#define MONSTER_H_
class Monster {
private:
	char* nameMonster;
	int attack;
	int health;

public:
	Monster (char* = "", int = 0, int = 0);
	Monster (Monster const&);
	
	char const* getNameMonster () const
	{
		return nameMonster;
	}

	int getAttack () const
	{
		return attack;
	}	

	int getHealth () const
	{
		return health;
	}

	void setNameMonster (char const*);
	void setAttack (int a) {attack = a; }
	void setHealth (int h) {health = h;}
	void print () const;

	~Monster();
};

#endif /* MONSTER_H_ */