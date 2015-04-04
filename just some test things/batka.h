#ifndef BATKA_H
#define BATKA_H
class  Batka{
private:
	char* name;
	int years;
	float swagLevel;
	int muscleMass;
	void copy(const Batka&);
	void destroy();
public:
	Batka(char* = "" , int = 24 , float = 50 , int = 30);
	~Batka();
	Batka& operator=(const Batka&);
	Batka(const Batka&);
	
	void setName(char*);
	void train(int);
	float swagOmeter()const{return swagLevel;}
}