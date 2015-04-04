#ifndef PICKAXE_H
#define PICKAXE_H
class Pickaxe{
private:
	char* onlyToNeedConstructor;
	int durability;
	int digGoldChance;
	float moneyColected;
	void copy(const Pickaxe&);
	void destroy();
public:
	Pickaxe(char8 = "" , int = 0 , int = 0 , float = 0);
	~Pickaxe();
	Pickaxe(const Pickaxe&);
	Pickaxe& operator=(const Pickaxe&);
	void repair();
	void digGold();
	float upgrade(float);//kato ostatuk vrushta restoto
	void print()const;

#endif