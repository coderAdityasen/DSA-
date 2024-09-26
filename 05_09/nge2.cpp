#include<iostream>
#include<stack>
#include<vector>

#define max 5

using namespace std;

int main(){

	int arr[max] = {2,10,12,1,11};
	stack<int> st;
	vector<int> nge(max,-1);

	int n = nge.size();

	// bad Time Complexity

	// for (int i = 0; i < max; i++)
	// {
	// 	for (int j = i+1; j < i+max; j++)
	// 	{
	// 		int ind = j % max;
	// 		if(arr[ind] > arr[i]){
	// 			nge[i] = arr[ind];
	// 			break;
	// 		}
	// 	}
	// }
	
	// for (int i = 0; i < max; i++)
	// {
	// 	cout<<nge[i]<<" ";
	// }
	
	// good Time complexity 

	for (int i = 2*max -1 ; i >= 0 ; i--)
	{
		while (!st.empty() && st.top() <= arr[i%max])
		{
			st.pop();
		}

		if(!st.empty()){
			nge[i%max] = st.top();
		}

		st.push(arr[i%max]);
		
	}
	

	for (int i = 0; i < n; i++)
	{
		cout<<" " << nge[i];
	}
	

	

	return 0;
}
