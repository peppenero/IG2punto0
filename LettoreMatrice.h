/*
 * LettoreMatrice.h
 *
 *  Created on: Jul 6, 2013
 *      Author: peppe
 */
#include<iostream>
#include<fstream>

using namespace std;

#ifndef LETTOREMATRICE_H_
#define LETTOREMATRICE_H_

class LettoreMatrice{
private:
	ifstream input;
	int riga;
	int colonna;
	char** matrice;
public:
	LettoreMatrice();
	char** leggiMatrice();
	~LettoreMatrice();
	int getColonna() const;
	void setColonna(int colonna);
	int getRiga() const;
	void setRiga(int riga);
};




#endif /* LETTOREMATRICE_H_ */
