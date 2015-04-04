#ifndef INVENTORY_H
#define INVENTORY_H
class Inventory{
private:
	Food* food;
	Armor* armor;
	Sword* swords;
	int money;
	int capacity;
	int food;
	int armor;
	int swords;
	void copy(const Inventory&);
	void destroy();
	void resizeFood();
	void resizeArmor();
	void resizeSwords();
public:
	Inventory(int = 10);
	~Inventory();
	Inventory(const Inventory&);
	Inventory& operator=(const Inventory&);	


}
#endif