//Execution begins here

#include "helloworld/Hello.h"
#include "hash/GeneralHashFunctions.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

string RandomString(int);
long GetFileLength(string);
string GetFileContents(string,string*,long);
void CreateFile(string,string*,long);
void GetFile(string,string[],int);
bool LinearSearch(string*,long,string);
long BinarySearch(string*,long,string);
// void HashSearch(string*,long); 
void ReSeedArray(string*,long);
// look up trig identities
int main(int argc, char const *argv[])
{	
	srand(static_cast<unsigned int>(time(0)));

	char choice = '0';
	/* Delcare Array ===============*/
	const int SIZE = 20;
	string a[SIZE];
	string * b;
	string * c;
	long length = 0;

	do{
	/* Menu ========================*/
	cout 	<< "1) Reseed and Save" << endl
			<< "2) Load in Array" << endl
			<< "3) Singular Linear Search" << endl
			<< "4) Multi Stat Linear Search" << endl
			<< "5) Singular Binary Search" << endl
			<< "6) Multi Stat Binary Search" << endl
			<< "7) Multi Stat Hash Search" << endl
			<< "8) Exit" 		 << endl;	
	
	
	cin >> choice;

	if(choice == '1'){
		cout << "How large do you want the data set to be?" << endl << "> ";
		cin >> length;
		string *b = new string[length];
		ReSeedArray(b,length);
		CreateFile("array.txt",b,length);
	}
	if(choice == '2'){
	/* Establish file length to determine length
	 	of array. */
		length = GetFileLength("array.txt");
		b = new string[length];	
		c = new string[length/2];
	/* Get the contents of the two necessary files
		array.txt and search_array.txt*/
		GetFileContents("array.txt",b,length);
		GetFileContents("search_array.txt",c,length/2);
	}
	if(choice == '3'){
	/*==========================================
	LINEAR SEARCH
	============================================*/
		long searchpos = rand()%((length/2)-1);
		cout << "Looking for this term:" << endl << c[searchpos] << endl;
		// int tstart = time(0);
		const clock_t begin_time = clock();
		if (LinearSearch(b,length,c[searchpos])){
			cout << "Found a match! " << endl;
		}
		cout << float(clock() - begin_time)/ CLOCKS_PER_SEC << endl;
		// int tend = time(0);
		// cout << "Linear Search took " << tend - tstart << endl;		
	}
	if(choice == '4'){
	/*==========================================
	LINEAR SEARCH
	============================================*/
	long searchpos = 0;
	double timeframe = 0.0;
	long runs = 0,counter = 0;
	cout << "How many runs?" << endl << "> ";
	    cin >> runs;
		
		const clock_t begin_time = clock();

	    while(counter < runs){
	    	searchpos = rand()%((length/2)-1);
			const clock_t begin_time = clock();
			LinearSearch(b,length,c[searchpos]);	
			timeframe += float(clock() - begin_time)/ CLOCKS_PER_SEC;	   
		  	// if(val > 0){
		  	// 	cout << "Found value at position " << val << endl;
		  	// }
		  	// else{
		  	// 	cout << "Failed to find value" << endl;
		  	// }
		  	counter ++;
	    }
	    cout << "Total Time: " << timeframe << endl;
	    cout << "Average time: " << timeframe / runs << endl;

		// long searchpos = rand()%((length/2)-1);
		// cout << "Looking for this term:" << endl << c[searchpos] << endl;
		// // int tstart = time(0);
		// const clock_t begin_time = clock();
		// if (LinearSearch(b,length,c[searchpos])){
		// 	cout << "Found a match! " << endl;
		// }
		// cout << float(clock() - begin_time)/ CLOCKS_PER_SEC << endl;
		// int tend = time(0);
		// cout << "Linear Search took " << tend - tstart << endl;		
	}
	if(choice == '5'){
	/*==========================================
	BINARY SEARCH
	============================================*/
		long searchpos = rand()%((length/2)-1);
		cout << "Looking for this term:" << endl << c[searchpos] << endl;
		// Sort String Array
		long N = length / 1;
	    // int N = sizeof(b)/sizeof(b[0]);
	    sort(b,b+N);

		const clock_t begin_time = clock();
	    long val = BinarySearch(b,length,c[searchpos]);
		cout << float(clock() - begin_time)/ CLOCKS_PER_SEC << endl;	   
	  	if(val > 0){
	  		cout << "Found value at position " << val << endl;
	  	}
	  	else{
	  		cout << "Failed to find value" << endl;
	  	}
	}
	if(choice == '6'){
	/*==========================================
	BINARY SEARCH
	============================================*/
		long searchpos = 0;
		float timeframe = 0.0;
		// Sort String Array
		long N = length / 1;
	    // int N = sizeof(b)/sizeof(b[0]);
	    sort(b,b+N);
	    long runs = 0,counter = 0;
	    cout << "How many runs?" << endl << "> ";
	    cin >> runs;

	    while(counter < runs){
	    	searchpos = rand()%((length/2)-1);
			const clock_t begin_time = clock();
		    long val = BinarySearch(b,length,c[searchpos]);
			timeframe += float(clock() - begin_time)/ CLOCKS_PER_SEC;	   
		  	// if(val > 0){
		  	// 	cout << "Found value at position " << val << endl;
		  	// }
		  	// else{
		  	// 	cout << "Failed to find value" << endl;
		  	// }
		  	counter ++;
	    }
	    cout << "Total Time: " << timeframe << endl;
	    cout << "Average time" << timeframe / runs << endl;
	}
	// GetFileContents("array.txt");
	// for(int i = 0; i < SIZE; i++){
	// 	cout << a[i] << endl;
	// }
	if(choice == '7'){
	// ==========================================
	// HASH SEARCH
	// ============================================
		cout << "Hash Search" << endl;
		int collisionCounter 	= 0;
		char choice 			= '0';
		unsigned int tablesize 	= 0;
		float timeframe = 0;

		cout 	<< "=== Set table size ===" << endl
				<< "1) Set Table Size" << endl
				<< "2) Use Standard Size (inputs x2)" << endl << "> ";
		cin >> choice;

		if(choice == '1'){
			cout << "Set hash table size" << endl << "> ";
			cin >> tablesize;
		}
		else{
			tablesize = length * 2;
		}
		int* e = new int[tablesize];

		for(long i = 0; i < tablesize; i++){
			e[i] = 0;
		}
		//Hash Table
		for(unsigned int z = 0; z < length; z++){
			string key = b[z];
			long val = RSHash(key)%(tablesize);
			if(e[val] == 1){
				// cout << "Collision at " << val << endl;
				collisionCounter++;
			}
			else{
				e[val] = 1;
			}
		}
		int matchcount = 0;
		//Search for values
		for(unsigned int z = 0; z < length; z++){
			string key = b[z];
			const clock_t begin_time = clock();
			long val = RSHash(key)%(tablesize);
			if(e[val] == 1){
				matchcount++;
			}
			timeframe += float(clock() - begin_time)/ CLOCKS_PER_SEC;	   

		}
		float percentage = ((float)collisionCounter/(float)length);
		cout << "===================================" << endl
			<<	"============= RESULTS =============" << endl;
		cout << "Hashed " << length << " value(s)" << endl;
		cout << "Found " << matchcount << " match(s)" << endl;
		cout << collisionCounter << " collisions encountered (" << percentage * 100 << "%)"<< endl;
	    cout << "Total Time: " << timeframe << endl;
	    cout << "Average time per search" << timeframe / length << endl;
		cout << "===================================" << endl;
		// HashSearch();

		delete[] e;
	}

	}while(choice != '8');

	delete[] c;
	delete[] b;
	return 0;
}

string RandomString(int len){
	char *s;
	const char alphanum[] =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	stringstream a;

	for(int i = 0; i < len; ++i){
		a << alphanum[rand()%(sizeof(alphanum)-1)];
	}
	string stringy = a.str();

	return stringy;
}
bool LinearSearch(string arr[],long s,string arg){
	bool match = false;
	for(long i = 0;i<s;i++){
		if(arr[i] == arg){
			match = true;
			break;
		}
	}
	return match;
}
long BinarySearch(string arr[],long s, string arg){

	long first = 0, last = s;
	while(first <= last){
		long mid = (first + last) / 2;
		// cout << first << " to " << last << endl;
		if(arg > arr[mid]){
			first = mid + 1;
		}
		else if(arg < arr[mid]){
			last = mid - 1;
		}
		else{
			return mid; 
		}
	}
	return -(first + 1);
}
void CreateFile(string filename,string *array, long size){
	ofstream outfile(filename);
	for(int i = 0; i < size; i++){
		outfile << array[i] << endl;
	}
	outfile << endl;
	outfile.close();

	ofstream halffile("search_"+filename);
	for(int y = 0; y < size/2; y++){
		halffile << array[y] << endl;
	}
	halffile << endl;
	halffile.close();
}
long GetFileLength(string filename){
	ifstream infile(filename);
	// ifstream infile(filename,ios::binary | ios::ate);
	long file_length = 0;
	string temp = "";
		while(getline(infile,temp)){
			file_length++;
		}
	// long file_length = infile.tellg();
	infile.close();
	return file_length-1;
}
string GetFileContents(string filename, string *b,long filesize){
	ifstream infile(filename);
	int position = 0;

	if(infile.is_open()){
		cout << filename << " opened successfully." << endl;
		string temp;
		while(getline(infile,temp)){
			b[position] = temp;
			position++;
		}
		cout << "Read in " << position-1 << " line(s)" << endl;
	}else{
		cout << "File could not be opened!" << endl;
	}	

	// for(int z = 0; z < position; z++){
	// 	cout << z << "." << b[z] << endl;
	// }
}
void ReSeedArray(string *b,long s){
	for(int i = 0; i < s; i++){
		b[i] = RandomString(20);
	}
}
void HashSearch(){
	/* Build hash table */
}


/*=============================
	int: 			2,147,483,647
	unsigned int:	4,294,967,295
	long:			9,223,372,036,854,775,807
	<< numeric_limits<int>::max() << endl
==============================*/