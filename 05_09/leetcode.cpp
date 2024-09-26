#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class cars{
	public:
	string brand;
	int year;

	cars(string x , int n){
		this->brand = x;
		this->year = n;
	}
};

int main(){

vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

cars.push_back("merce");
cars.pop_back();

	cout<<cars[0]<<" is my car"<<endl;

	return 0;
}