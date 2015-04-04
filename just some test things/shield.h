#ifndef SHIELD_H
#define SHIELD_H
class Shield{
private:
	void copy(const Shield&);
	void destroy();
	char* name;
	int armor;
	int durability;
public:
	Shield(char* = "" , int = 0 );
	~Shield();
	Shield(const Shield&);
	Shield& operator=(const Shield&);
	
	void setName(char*);
	void engrave(int);

	
}