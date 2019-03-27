/*
 * PaperPhoto.h
 *
 *  Created on: 7 марта 2019 г.
 *      Author: 123
 */

#ifndef PAPERPHOTO_H_
#define PAPERPHOTO_H_
#include<string>
#include <iostream>
#include "Photo.h"
using namespace std;
class PaperPhoto: public Photo{
private:
	string papertype;
public:
    PaperPhoto(string papertype){
    	this->papertype = papertype;

    	length = 4;
    	width = 6;
    	color = "allcolors";
        ganre = "picture";
    }
    PaperPhoto(int length, int width, string color, string ganre,string papertype){
    		this->length = length;
    		this->width= width;
    		this->color = color;
    		this->ganre = ganre;
    		this->papertype= papertype;
    	}

    PaperPhoto(){
    	        papertype = "a4";
    	    	length = 4;
    	    	width = 6;
    	    	color = "allcolors";
    	        ganre = "paper";

    }
    virtual ~PaperPhoto(){}
    string getPapertype(){
    	return papertype;
    }
    void setPepertype(string s){
    	papertype = s;
    }

public:
    bool suitable(){
    	int l;
    	int w;
    	cout<<"input length of frame: ";
    	cin>>l;
    	cout<<"input width of frame: ";
    	cin>>w;
    	int square_of_photo = width*length;
    	if(square_of_photo<=l*w)return true;
    	else
    	return false;
    }
   friend ostream& operator <<(std::ostream& out, const PaperPhoto &p);
   friend istream& operator >>(std::ostream& out, PaperPhoto &p);
   string getGanre(){
   		return ganre;
   	}
   string getType(){
   		return "paper";
   	}
   void print() const override{
      	cout << "PaperPhoto(" << length << ", " << width<< ", " << ganre<< ", " <<papertype<< ")"<<endl;
      }
};
std::ostream& operator <<(std::ostream& out, const PaperPhoto &p){
    	out << "PaperPhoto(" << p.length << ", " << p.width<< ", " << p.ganre<< ", " <<p.papertype<< ")"<<endl;
        return out;
    }
   std::istream& operator >>(std::istream& in, PaperPhoto &p){

   			cout<<"Length: ";
   			in>>p.length;
   			cout<<"Width: ";
   			in>>p.width;
   			cout<<"Color: ";
   			in>>p.color;
   			cout<<"Ganre: ";
   			in>>p.ganre;
   			cout<<"Papertype: ";
   			string s;
   			in>>s;
   			p.setPepertype(s);
   			return in;
   	}



#endif /* PAPERPHOTO_H_ */
