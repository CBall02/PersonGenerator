
#include "CommonInclude.h"

using namespace std;

int randomNum(int a, int b) { //Generates an evenly distributed number
	random_device randNum;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(randNum()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(a, b); //takes parameters and sets random generator range
	int Num = dis(gen);
	//cout << Num;
	return Num;
}