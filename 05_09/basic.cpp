#include<iostream>
#include<stack>

using namespace std;

void sendtobottomwithrecurr(stack<int>& st , int elem){
	if(st.empty()){
		st.push(elem);
		return ;
	}else{
		int top = st.top();
		st.pop();
		sendtobottomwithrecurr(st,elem);
		st.push(top);
	}
}

void reversedstack(stack<int>& s){
	if(s.empty()){
		return;
	}

	int top = s.top();
	s.pop();
	reversedstack(s);
	sendtobottomwithrecurr(s , top);
}

void printallstac(stack<int> s){
	while (!s.empty())
	{
		int top = s.top();
		cout<<top<<" ";
		s.pop();
	}
}

int main(){

string string1 = "computer";
string string2 = "cmt";
string result = "";

for (int i = 0; i < string1.length(); i++)
{
	bool isfound = false;
	for (int j = 0; j < string2.length(); j++)
	{
		if(string1[i] == string2[j]){
			isfound = true;
			break;
		}
	}

	if (!isfound) {
            result+=string1[i];
        }
	
}

cout<<result<<endl;


	// stack <int> s;
	// s.push(2);
	// s.push(5);
	// s.push(8);
	// s.push(4);
//
	// cout<<"before reverse"<<endl;
	// printallstac(s);
	// cout<<endl;
	// cout<<"stack after reverse"<<endl;
	// reversedstack(s);
	// printallstac(s);

	return 0;
}

