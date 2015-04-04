#ifndef SWORD_H
#define SWORD_H

class Sword{
	private:
		int attack;
		char* name;
		int durability;
		void copy(const Sword&);
		void destroy();

	public:
		Sword(char* = "" , int = 1);
		~Sword();
		Sword(const Sword&);
		Sword& operator=(const Sword&);


		void setName(char*);
		void forge(int);
}

#endif