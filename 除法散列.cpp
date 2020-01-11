#include <iostream>

using namespace std; 
const int hashTableLen = 11;

int hash(int key)
{
	return key % hashTableLen;	
}
int main()
{
	int hashTB[hashTableLen];
	for(int i = 0; i < hashTableLen; i++)
		hashTB[i] = -1;
	int value[]={21,32,224,734,244,2,34.50};
	for(int i = 0; i < 8; i++) 
	{
		hashTB[hash(value[i])] = value[i];
	}
	for(int i = 0; i < hashTableLen; i++)
	{
		cout << hashTB[i] << " ";
	}
	return 0;
}
