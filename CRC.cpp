#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

int return_xor(int x, int y);

int main()
{
	string key, data, buffer;
	cout<<"Enter the key:";
	cin>>key;
	cout<<"Enter the data:";
	cin>>data;
	for(int i=0;i<key.size()-1;i++){
		data.push_back('0');
	}
	int count=0;
	bool flag = false;
	int j=0;
	while(j<data.size()){
		flag = false;
		count = 0;
		for(int i=0;i<key.size();i++){
			int z = return_xor(key[i] - '0', data[i+j] - '0');
			if(z == 1){
				flag = true;
			}
			if(z == 0 && flag == false){
				count++;
			}
		}
		cout<<endl<<count<<endl;
		j = j + count;
		cout<<j<<endl;
	}
	return 0;
}

int return_xor(int x, int y)
{
	cout<<x<<" "<<y<<endl;
	return (x | y) & (~x | ~y);
}