//============================================================================
// Name        : classlaba4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdexcept>
#include<cstring>
#include "PaperPhoto.h"
#include "Photo.h"
#include "ElectronicPhoto.h"
using namespace std;
	void sizeplus(Photo **arr,Photo **temp, int *n);
	void remove(Photo **arr,Photo **temp, int *n);

int main() {
	 ElectronicPhoto *e;
	 PaperPhoto *p;
	try{
	ifstream myfile ("Info.txt");
	string line;
     if(!myfile) throw 1;
		  int n;
		  myfile>>n;
		  Photo **arr = new Photo*[n];
		  for(int i =0; i<n; i++){
			  int type;
			  myfile>>type;
			  int length;
			  int width;
			  string color;
			  string ganre;
			 if(type==1){
				 string filetype;
				 myfile>>length;
				 myfile>>width;
				 myfile>>color;
				 myfile>>ganre;
				 myfile>>filetype;
				  e=new ElectronicPhoto(length, width, color, ganre, filetype);
				 arr[i] = &(*e);
				 arr[i]->print();
				// cout<<arr[i]->getGanre()<<endl;
			 } else if(type ==0){
				 string papertype;
				 myfile>>length;
				 myfile>>width;
				 myfile>>color;
				 myfile>>ganre;
				 myfile>>papertype;
				 p=new PaperPhoto(length, width, color, ganre, papertype);
				 arr[i] = &(*p);
				 arr[i]->print();
				// cout<<arr[i]->getGanre()<<endl;
			 } else throw 0;
		  }

		  int g;
		  string ganre;
		  string type;
		   while(true){
			  cout<<"Choose ganre: "<<endl;
			  cout<<"Press 1 to choose formal."<<endl;
			  cout<<"Press 2 to choose informal."<<endl;
			  cin>>g;
			  if(g==1){ ganre="formal"; break;}
			  else if(g==2){ ganre="informal"; break;}
			  else cout<<"Input is incorrect"<<endl;
		  }
		   int t;
		  while(true){
		  	  cout<<"Choose photo type: "<<endl;
		  	  cout<<"Press 1 to choose Electronic."<<endl;
		  	  cout<<"Press 2 to choose Paper."<<endl;
		  	  cin>>t;
		  	  if(g==1){type="electronic"; break;}
		  	  else if(g==2){type="paper"; break;}
		  	  else cout<<"Input is incorrect"<<endl;
		   }
		   cout<<ganre<<endl;
		   cout<<type<<endl;

		   int count;
		   for(int i=0;i<n; i++){
			   if(arr[i]->getGanre()==ganre&&arr[i]->getType()==type){
				   count++;
			   }
		   }
		  Photo** sample = new Photo*[count];
		  for(int i=0;i<n;i++){
			  if(arr[i]->getGanre()==ganre&&arr[i]->getType()==type){
			  		sample[i]=arr[i];
			  		sample[i]->print();
			    }
		  }

		  cout<<endl;
		  cout<<"photo search by size: "<<endl;

		  int l;
		  cout<<"input length= ";
		  cin>>l;

		  int w;
		  cout<<"input width= ";
		  cin>>w;
		  cout<<endl;
		  bool flag =false;

		  Photo *maxE =arr[0]; //the biggest square of electronic photo
		  Photo *maxP =arr[1]; //the biggest square of paper photo

		  for(int i =0; i<n; i++){
			  //found photo
			  if(arr[i]->length == l && arr[i]->width == w ){
				  arr[i]->print();
				  cout<<endl;
				  flag = true;
			  }
			  //found the biggest square photo

			  if(arr[i]->getType()=="electronic"){
				  if(arr[i]->length*arr[i]->width >maxE->length*maxE->width){
					  maxE = arr[i];
				  }
			  }
			  if(arr[i]->getType()=="paper"){
			  	  if(arr[i]->length*arr[i]->width >maxP->length*maxP->width){
			  		  maxP = arr[i];
			  	   }
			  }
		  }
		  if(!flag) cout<<"Photo not found"<<endl;
		  cout<<endl;

		  cout<<"ElectronicPhoto with the biggest square is: \n";
		  maxE->print();
		  cout<<endl;
		  cout<<"PaperPhoto with the biggest square is: \n";
		  maxP->print();
		  cout<<endl;

		  bool exit=false;
		  int cot =0;
		  ElectronicPhoto *ep;
		  PaperPhoto *pp;
		  Photo **temp;
		  while(!exit){

			 int c;
			 cout<<"To add new Photo press 1 \n";
			 cout<<"To delate last photo press 2 \n";
			 cout<<"Press 3 to exit \n";
			 cin>>c;

			if(c==1){
				 bool f=true;
				while(true){
			    int q;
				cout<<"If you want to add ElectronicPhoto press 1 \n";
				cout<<"If you want to remove PaperPhoto press 2 \n";
				cout<<"If you want to exit press 3 \n";
				cin>>q;

				if(q==1){

					ep = new ElectronicPhoto();
					cin>>*ep;

				    sizeplus(arr,temp, &n);
				    cout<<1;
					arr[n-1]=&(*ep);
					cout<<1;
					 for(int i=0; i<n; i++)
							  	arr[i]->print();

				} else if(q==2){
				   pp= new PaperPhoto();
					cin>>*pp;

					 sizeplus(arr,temp, &n);
					 arr[n-1]=&(*pp);
					 for(int i=0; i<n; i++)
							  	arr[i]->print();
				} else if(q==3) break;
				  else cout<<"Input is incorrect \n";
				}
			}
			 if(c==2){
				 remove(arr,temp,&n);
				 for(int i=0; i<n; i++)
			      arr[i]->print();
			 }
			 if(c==3){
				 cout<<"Exit \n";
				 exit = true;
			 }
			 else
			 cout<<"Input is incorrect \n";
		  }
		  for(int i=0; i<n; i++)
		  	arr[i]->print();
	 } catch(int e){
		 if(e == 1)
		 cout << "File not found" ;
		 else cout<<"File content is incorrect";
	 }
	return 0;
}

void sizeplus(Photo **arr,Photo **temp, int *n ){
	*n+=1;
	temp = new Photo*[*n];
	for(int i =0; i<*n; i++)
		temp[i]=arr[i];


	arr = new Photo*[*n];
	arr[0]=temp[0];
	cout<<*arr[0]<<endl;

	for(int i =0; i<*n; i++)
		arr[i]=temp[i];

	delete []temp;
}
void remove(Photo **arr,Photo **temp,int *n){
	*n-=1;
	temp = new Photo*[*n];
	for(int i =0; i<*n; i++)
		temp[i]=arr[i];
	arr = new Photo*[*n];
	for(int i =0; i<*n; i++)
		arr[i]=temp[i];
	delete []temp;
}
