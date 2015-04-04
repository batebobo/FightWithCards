#ifndef TEARDROP_H
#define TEARDROP_H
class Teardrop{
private:
	int howMany;
	float saltiness;
	bool fromHappines;
public:
	Teardrop(int = 100 , float = 5 , bool = true);
	~Teardrop();
	Teardrop& operator=(const Teardrop&);
	Teardrop(const Teardrop&);

	void drop();
	void setSaltiness(float);
	void checkHappines();
	float makeSalt();
}
#endif