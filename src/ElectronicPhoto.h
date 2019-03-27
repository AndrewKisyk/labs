/*
 * ElectronicPhoto.h
 *
 *  Created on: 7 марта 2019 г.
 *      Author: 123
 */
#ifndef ELECTRONICPHOTO_H_
#define ELECTRONICPHOTO_H_
#include <iostream>
#include"PaperPhoto.h"
using namespace std;
class ElectronicPhoto :public Photo{
private: string filetype;
	public:ElectronicPhoto(string filetype){
		length = 500;
		width = 400;
		color = "black and white";
		ganre = "formal";
		this->filetype = filetype;
	}
	ElectronicPhoto(int length, int width, string color, string ganre,string filetype){
		this->length = length;
		this->width= width;
		this->color = color;
		this->ganre = ganre;
		this->filetype= filetype;
	}
	ElectronicPhoto(){
	}
	virtual ~ElectronicPhoto(){}
public:
	string getFiletype(){
		return filetype;
	}
	string getGanre(){
		return ganre;
	}
    string getType(){
		return "electronic";
	}
	void setFiletype(string s){
		filetype =s;
		}
	bool validFormat(){
		if(filetype =="*.raw"||filetype =="*.raw"||filetype =="*.jpg"||filetype =="*.png"||filetype =="*.tiff")
			return true;
		else
			return false;
	}
    void print() const override{
    	cout << "ElectronikPhoto(" << length << ", " << width<< ", " << ganre<< ", " <<filetype<< ")"<<endl;
    }
	friend ostream& operator <<(std::ostream& out, const ElectronicPhoto &p);
    friend istream& operator >>(std::istream& in, ElectronicPhoto &p);
	};
std:: ostream& operator <<(std::ostream& out, const ElectronicPhoto &p){
		out << "ElectronicPhoto(" << p.length << ", " << p.width<< ", " << p.ganre<< ", " <<p.filetype<< ")"<<endl;
	    return out;
	}
std::istream& operator >>(std::istream& in, ElectronicPhoto &p){
			cout<<"Length: ";
			in>>p.length;
			cout<<"Width: ";
			in>>p.width;
			cout<<"Color: ";
			in>>p.color;
			cout<<"Ganre: ";
			in>>p.ganre;
			cout<<"Filetype: ";
			in>>p.filetype;
			return in;
	}


#endif /* ELECTRONICPHOTO_H_ */
