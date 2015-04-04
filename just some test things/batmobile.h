#ifndef BATMOB_H
#define BATMOB_H
class Batmobile{
private:
	char* noNeedOfName;
	int maxSpeed;
	void copy(const Batmobile&);
	void blastItWithRocketLauncher();
public:
	Batmobile(char* = "" , int = 1000);
	~Batmobile();
	Batmobile(const Batmobile&);
	Batmobile& operator=(const Batmobile&);
	
	void speedUp();
	void tryToSlowDown();
	

#endif