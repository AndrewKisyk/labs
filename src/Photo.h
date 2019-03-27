
#ifndef PHOTO_H_
#define PHOTO_H_
#include<string>
#include <iostream>

using namespace std;
int max_el_index(int[],int);
bool operator >(string, string);
class Photo{
public:
    int length;
    int width;
    string color;
    string ganre;
    Photo(int length, int width, string color, string ganre){
    	this->length = length;
    	this->width = width;
    	this->color = color;
    	this->ganre = ganre;
    }
    Photo(){
        length = 1600;
        width = 800;
        color = "allcolors";
        ganre = "picture";
    }
    virtual ~Photo(){}
public:
    int* cutFragment(){
    	int n;
    	try{
    		cout<<"intput number of points";
    	cin>>n;
    	if(n <2) throw 1;
    	if(n%2 != 0) throw 2;

    	} catch(int e){
    		if(e == 2)
    		cout<<"Input ecven numer";
    		else
    		cout<<"Input_Error";

    		cout<<"try again";
    		cin>>n;
    	}
    	int *a = new int[n*n];

    	for(int i = 0; i<n*n; i++){
    		if(i%2==0){
    			cout<<"x"<<i<<"= ";
    			cin>>a[i];
    		}else{
    			cout<<"y"<<i-1<<"= ";
    			cin>>a[i];
    			cout<<endl;
    		}
    	}
    	return a;
    }
    void convert(){
    	 int input;
    		cout<<"Press 1 to convert for alboum(1600x900)"<<endl;
    		cout<<"Press 2 to convert for passport(60x50)"<<endl;
    		cout<<"Press 3 to convert for standart(400x400)"<<endl;
    		cout<<"Press 4 to exit";
    	       		cin >> input;
    		        switch (input) {
    		        case 1:
    		            width = 1600;
    		            length = 900;
    		            break;
    		        case 2:
    		        	 width = 60;
    		        	 length =50;
    		            break;
    		        case 3:
    		        	width = 400;
    		            length =400;
    		            break;
    		        case 4:
    		            cout << "The End!\n";
    		            break;
    		        default:
    		            cout << "Error, but input, quitting\n";
    		            break;
    		        }
    }
    bool operator >(const Photo &p){
    	if(this->ganre>p.ganre)
    		return true;
    	else return false;
    }
    bool operator ==(const Photo &p){
    	bool value;
    	if(this->ganre == p.ganre){
    		value = true;
    	} else value = false;
    	return value;
    }
    bool operator !=(const Photo &p){
        	bool value;
        	if(this->ganre != p.ganre){
        		value = true;
        	} else value = false;
        	return value;
        }

void operator = (const Photo &p){
    	this->length = p.length;
    	this->width = p.width;
    	this->color = p.color;
    	this->ganre = p.ganre;
    }
virtual void print() const {}
virtual string getType()=0;
virtual string getGanre()=0;
};
/*string themostpopularganre(Photo p[], int n){
    	Photo themostpopular;
    	int coincidence[n];
    	int count;
    	for(int i = 0; i<n; i++){
    		themostpopular = p[i];
    	 for(int j =1; j<n; j++){
    		if(themostpopular == p[j]){
    			count++;
    		}
    	 }
    	 coincidence[i] = count;
    	 count = 0;
    	}
    	count = max_el_index(coincidence, n);
    	return p[count].ganre;
    }*/
/*Photo* arrange_of_ganre(Photo *p, int n){
	bool flag=true;
	Photo temp;
	while(flag){
		flag = false;
		for(int i = 0; i<n-1; i++){
			if(p[i]>p[i+1]){
				temp = p[i+1];
				p[i+1] = p[i];
				p[i] = temp;
				flag = true;
			}
		}
	}
	return p;
}*/
std::ostream& operator<< (std::ostream &out, const Photo &p){
    out << "Photo("  << p.length << ", " << p.width<< ", " << p.ganre<< ")";
    return out;
}
std::istream& operator>>(std::istream &in, Photo &p){

	cout<<"Length: ";
	in>>p.length;
	cout<<"Width: ";
	in>>p.width;
	cout<<"Color: ";
	in>>p.color;
	cout<<"Ganre: ";
	in>>p.ganre;
	return in;
}
int max_el_index(int arr[],int n){
	int max = arr[0];
	int max_el_index = 0;
	for (int i = 0; i < n; ++i) {
	        if (arr[i] > max) {
	            max = arr[i];
	            max_el_index = i;
	        }
	    }
	return max_el_index;
}

bool operator >(string s1, string s2){
    if(s1.length()>s2.length())
    return true;
    if(s1.length()==s2.length()&& s1!=s2)
    return true;
    else return false;
}


#endif /* PHOTO_H_ */
