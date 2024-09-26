#include<iostream>
#include<vector>

using namespace std;

int main(){

	vector <int> vr(5,-1);

	vr.at(3) = 4;

	vr.push_back(10);
	for (int i = 0; i < vr.size(); i++)
	{
		cout<<vr[i]<<" ";
	}
	

	return 0;
}