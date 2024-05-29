#include<iostream>
using namespace std;


class Target
{
public:
	virtual void request() = 0;


	~Target(){}

private:

};

class Adoptee
{
public:
	void anyRequest(){
		cout << "This is a any adoptee request" << endl;
	}

	~Adoptee(){}

private:

};

class Adopter :public Target
{
public:
	Adopter(Adoptee* adoptee) :adoptee(adoptee){}


	void request(){
		adoptee->anyRequest();
	}


	~Adopter(){}

private:
	Adoptee* adoptee;
};


void func(Adoptee adoptee){
	Target* adopter = new Adopter(&adoptee);
	adopter->request();
	delete adopter;
}

int main(){

	Adoptee adoptee;
	func(adoptee);


	return 0;
}
