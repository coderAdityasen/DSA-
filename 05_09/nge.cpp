#include<iostream>
#include<stack>
#include<vector>

using namespace std;


 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	int n = nums2.size();
	stack<int> st;
	vector<int> nge(n , -1);

	for (int i = n-1; i >= 0; i--)
	{
		int num = nums2[i];

		while (!st.empty() && st.top() <= num)
		{
			st.pop();
		}
		
		if(!st.empty()){
			nge[i] = st.top();
		}

		st.push(num);

		return nge;
	}
	
    }

int main(){

	

	
	return 0;
}