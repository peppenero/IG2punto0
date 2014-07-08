/*
 * LettoreMatrice.cpp
 *
 *  Created on: Jul 6, 2013
 *      Author: peppe
 */

#include "LettoreMatrice.h"

LettoreMatrice::LettoreMatrice(){
	this->riga=0;
	this->colonna=0;
}

char** LettoreMatrice::leggiMatrice() {
	input.open("input.txt");
	char carattere;

	input.get(carattere);

	while(!input.eof()){
		//input.get(carattere);
		if((carattere=input.get())=='\n')
			riga++;
	}

	input.close();


	input.open("input.txt");
	input.get(carattere);
	if(carattere!='\n')
		colonna++;

	while((carattere=input.get())!='\n')
	{
		colonna++;
	}

	input.close();
	matrice=new char*[riga];



	for(int i=0;i<riga;i++)
		matrice[i]=new char[colonna];

	int k=0;
	int n=0;

	input.open("input.txt");

	while(input.get(carattere))
	{
		if(carattere!='\n')
		{
			this->matrice[n][k]=carattere;
			k++ ;
		}
		else
		{
			n++;
			k=0;
		}
	}
	input.close();

	return matrice;
}

int LettoreMatrice::getColonna() const {
	return colonna;
}

void LettoreMatrice::setColonna(int colonna) {
	this->colonna = colonna;
}

int LettoreMatrice::getRiga() const {
	return riga;
}

void LettoreMatrice::setRiga(int riga) {
	this->riga = riga;
}

LettoreMatrice::~LettoreMatrice() {
	for(int i=0;i<riga;i++)
		delete matrice[i];
	delete[] matrice;
}

