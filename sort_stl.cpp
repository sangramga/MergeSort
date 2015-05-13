#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(int x, int y) 
{
	return(x>y);
}

void getinput(vector<int> &vec)
{
	cout<<"enter Data: \n Enter -1 to End input\n";
	int temp;
	while(1)
	{
		cin>>temp;
		if(temp == -1)
			break;
		vec.push_back(temp);
		
	}

}
void giveoutput(vector<int> & vec)
{
	vector<int> :: iterator v = vec.begin();
	 for(v= vec.begin();v!=vec.end();v++)
	 {
	 	cout<<*v<<endl;
	 }		
}
int main()
{
	
	vector<int> vec;
	
	/*take input from user*/
	getinput(vec);
	
	 /*Partial Sorted (half Sorted) output */
	 cout<<"Half Sorted Output"<<"\n\n";
	 sort(vec.begin(),vec.begin() + (vec.size())/2,comp);
	 giveoutput(vec);
	 
	 
	  /*Full Sorted Output*/
	 cout<<"Sorted Output"<<"\n\n";
	 sort(vec.begin(),vec.end(),comp);
	 giveoutput(vec);
	
	
	
	 return(0);
}

