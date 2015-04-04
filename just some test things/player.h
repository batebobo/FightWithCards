#ifndef PLAYER_H
#define PLAYER_H
class Player{
private:
	char* name;
	int armor;
	int health;
	int money;
	Sword* sword;
	Shield* shield;
	void copy(const Player&);
	void destroy();
public:
	Player(char* = "" , int = 100 , int = 100 , int = 50);
	~Player();
	Player(const Player&);
	Player& operator=(const Player&);
	void attack(Player&);
	void defend(Player&);
	void equipSword(Sword&);
	void equipShield(Shield&);
}
#endif