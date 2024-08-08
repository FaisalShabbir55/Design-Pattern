#include<iostream>
using namespace std;


class Fighter
{
public:
	Fighter(){}

	virtual void weapon() = 0;


	~Fighter(){}

private:

};

class KnifeFighter : public Fighter
{
public:
	KnifeFighter(){}

	void weapon(){
		cout << "Fighter fight with Knife" << endl;
	}

	~KnifeFighter(){}

private:

};


class SwordFighter : public Fighter
{
public:
	SwordFighter() {}

	void weapon() {
		cout << "Fighter fight with Sword" << endl;
	}

	~SwordFighter() {}

private:

};

class GunFighter : public Fighter
{
public:
	GunFighter(){}

	void weapon() {
		cout << "Fighter fight with Guns" << endl;
	}


	~GunFighter(){}

private:

};



class Context
{
public:
	Context(Fighter* obj):obj(obj){}

	void setStrategy(Fighter* obj) {
		this->obj = obj;
	}

	void selectWeapon() {
		obj->weapon();

	}

	~Context(){}

private:
	Fighter* obj;
};

// main part start
int main() {

	KnifeFighter knifeFighter;
	GunFighter gunFighter;
	SwordFighter swordFighter;

	Context context(&knifeFighter);

	cout << "Default strategy:" << endl;
	context.selectWeapon();


	context.setStrategy(&gunFighter);

	cout << "Updated strategy:" << endl;
	context.selectWeapon();

	context.setStrategy(&swordFighter);
	cout << "New Strategy: " << endl;
	context.selectWeapon();

	return 0;
}



