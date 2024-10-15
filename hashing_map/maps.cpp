#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){

	map<int , int> mp;
	mp[0] = 10;
	mp[3] = 40;
	mp[2] = 50;

	int n = mp.size();
	cout<<n<< " is n"<<endl;
	for (const auto &pair : mp)
	{
		if(pair.first == 2){
			mp[pair.first] = 200;
		}
		cout<<pair.first <<" " << pair.second << " " <<endl;
	}
	return 0;
}
