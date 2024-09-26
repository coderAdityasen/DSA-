#include<iostream>
#include<stack>
#include<vector>
#include<cmath>

using namespace std;


bool isbalbrack(string s){
	stack<char> str;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            str.push(s[i]);
        }else if(
			str.top() == '{' && s[i] == '}' 
		|| str.top() == '(' && s[i] == ')' || 
		str.top() == '[' && s[i] == ']'
		)
		{
			str.pop();
		}
	}
	
	if (str.empty()){
			return true;
		}else{
			return false;
		}
}

// with reccursion
void sendtobottomwithrecurr(stack<int> st , int elem){
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
	sendtobottom(s,top);
}

// without recurrsion
void sendtobottom(stack<int>& st , int elem){
	stack<int> newsta;

	while (!st.empty()){
		newsta.push(st.top());
		st.pop();
	}
	st.push(elem);
	while (!newsta.empty())
	{
		st.push(newsta.top());
		newsta.pop();
	}

	
}


void reverseString(string& s){
	stack<char> cr;

	for (int i = 0; i < s.length(); i++)
	{
		cr.push(s[i]);
	}

	string result;
	while (!cr.empty())
	{
		char c = cr.top();
		result += c;
		cr.pop();
	}

	s = result;
	
	
}



int main(){

// Q1.) balance the bracket 

	// string word = "{[()]}";
	// cout<<isbalbrack(word)<<endl;

// Q2.) send element to bottom of the stack 

	// stack<int> s;
	// s.push(4);
    // s.push(5);
    // s.push(6);
	//
	// int elem = 2;
	//
	// sendtobottom(s,elem);
//
	//  while (!s.empty()) {
    //     cout << s.top() << endl;
    //     s.pop();
    // }

// Q3.) reverse a string using stack

	// string word = "abcd";
	// reverseString(word);
	// cout<<word<<" is reveresed"<<endl;

// Q4.) reverse a stack using vector

	// stack<char> nums;
	// nums.push('1');
	// nums.push('2');
	// nums.push('3');
	// nums.push('4');
	// nums.push('5');
	// nums.push('6');
	// nums.push('7');
	// vector<char> v;
//
	// while (!nums.empty())
	// {
	// 	v.push_back(nums.top());
	// 	nums.pop();
	// }
//
	// int n = v.size();
//
	// if(n%2 == 0){
	// 	int target = n/2;
	// 	for (int i = 0; i < n; i++)
	// 	{
	// 		if(i == target) continue;
//
	// 		nums.push(v[i]);
	// 	}
		//
	// }else{
	// 	int target = ceil(n/2);
	// 	for (int i = 0; i < n; i++)
	// 	{
	// 		if(i == target) continue;
	// 		nums.push(v[i]);
	// 	}
	// }
//
	// cout<<"printing all elemets after deletion: ";
	// while (!nums.empty())
	// {
	// 	char c = nums.top();
	// 	nums.pop();
	// 	cout<<c<<" ";
	// }
	


	return 0;
}

