#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void readFromKeyboard(int [], int&);
void readFromFile(int [], int&);
void Sort(int [], int);
void printValues(const int [], int);
void printOccurrenceResult(const int [], int);

int main()
{
	const int MAX_INTEGERS = 50;
	int integersArray[MAX_INTEGERS];
	int entries;
	int numberOfEntries;
	int userChoice;
	cout << "Enter the number of entries: ";
	cin >> entries;
	while(entries < 0 || entries >= 50)
	{
		cout << "Enter the number of entries fewer than 50: ";
		cin >> entries;
	} 
	numberOfEntries = entries;
	cout << "\n1. Read Integers from the keyboard" << endl;
	cout << "2. Read Integers from a file" << endl;
	cout << "Enter your choice: ";
	cin >> userChoice;
	while(userChoice != 1 && userChoice != 2)
	{
		cout << "Enter choice (1 or 2 only): ";
		cin >> userChoice;
	} 
	if(userChoice == 1)

		readFromKeyboard(integersArray, entries);
	else 

		readFromFile(integersArray, entries);
	printValues(integersArray, entries);
	Sort(integersArray, entries);

	printValues(integersArray, entries);

	printOccurrenceResult(integersArray, entries);
	system("pause");
	return 0;
}
 
void readFromKeyboard(int integers[], int &n){
	int i=1;
	int number;
	while(i<=n){
		cout<<"Enter the "<<i<<". number: ";
		cin>>number;
		integers[i-1]=number;
		i++;
	}
} 
void readFromFile(int integers[], int &n)
{
	string inFileName;
	ifstream inFile;

	cout << "\nEnter a file name: ";
	cin >> inFileName;

	inFile.open(inFileName.c_str());
	while(inFile.fail())
	{
		cout << inFileName << " file is not opened or found." << endl;
		cout << "Enter a current file name: ";
		cin >> inFileName;
		inFile.open(inFileName.c_str());
	} 

	int i = 0;	
	while(inFile >> integers[i] && i < n)
	{
		i++;
	}
	if(i == 0)	
	{
		cout << "The file contains no numbers that is the file is empty." << endl;	
		system("pause");
		exit(1);
	}
	else if(i != n)
	{
		cout << "The file contains less than " << n << " numbers." << endl;	
		n = i;
	}
}

void Sort(int integers[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i; j < n; j++)
		{
			if(integers[i] < integers[j])
			{
				int temp = integers[i];
				integers[i] = integers[j];
				integers[j] = temp;
			} 
		} 
	} 
}
 
void printValues(const int integers[], int n)
{
	cout << "\nThe integers stored in the array:" << endl;
	for(int i = 0; i < n; i++)
		cout << integers[i] << " ";
	cout << endl;
}

void printOccurrenceResult(const int array[], int entries){
	cout<<"\n\nN\tCount\n";
	int n=0;
	for(int i=0;i<entries;i=i+n+1){
		n=0;
		for(int j=i+1;j<entries;j++){
			if(array[i]==array[j]){
				n++;
			}
		}
		cout<<array[i]<<"\t"<<n+1<<"\n";
	}
}
