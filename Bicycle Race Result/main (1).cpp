
// File Name: main.cpp
// 
// Author: Yousif Al Saadi
// CS 2308 Spring 2022
// 
// A bicycle race results that allows the user to access the results. 

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int count = 10;

struct Result{
  int bibNumber;
  string name;
  double distance;
  string time;
};

//***********************************************************
// readDataset: It reads the results from the file. 
// ifstream: it get the file from the main function.
// results: It gets the struct results from the main function with array 6. 
// size: it gets the size of the result
// return: it return the size of the file. 
//***********************************************************

int readDataset(ifstream& in, Result results[], int &size){
  //fin.open("dataset.txt");
  count = 0;
  
  while(in){
    in >> results[count].bibNumber;

    
    in >> ws;
    getline(in, results[count].name);
    
    in >> results[count].distance;
    
    in >> results[count].time;
    
    count++;
  }
  return size = count - 1;
}
  


//***********************************************************
// displayDataset: it will display the data from the file.
// results: It gets the struct results from the main function with array 6.
// size: it gets the size of the result
// No return function.
//***********************************************************

void displayDataset(Result results[], int size)
{
  int i;
  cout << left
    << setw(7) << "BibNum"
    << setw(18) << "Name"
    << right
    << setw(8) << "Distance"
    << setw(10) << "  Time  "
    << endl;
    for(i=0; i<size; i++){
      
      cout<<left<< setw(7)<< results[i].bibNumber;
      cout<<setw(18)<<results[i].name;
      cout<< right << setw(8)<<fixed<<setprecision(1)<<results[i].distance;
      cout<<setw(10) <<fixed<<setprecision(1)<<results[i].time;
      cout<<endl;

  }
  
}

//***********************************************************
// sortByNumber: it rearrange by its bib number.
// results: It gets the struct results from the main function with array 6.
// size: it gets the size of the result
// No return function. 
//***********************************************************

void sortByNumber(Result results[], int size){
   bool swap;
   Result temp;

   do {
      swap = false;
      for (int count = 0; count < (size - 1); count++)
      {
         if (results[count].bibNumber > results[count + 1].bibNumber)
         {
            temp = results[count];
            results[count] = results[count + 1];
            results[count + 1] = temp;
           
            swap = true;
         }
      }
   } while (swap);   

   displayDataset(results,size);
   
}

//***********************************************************
// sortByDistanceTime: it rearrange the results by their distance.
// results: It gets the struct results from the main function with array 6.
// size: it gets the size of the result
// No return function.
//***********************************************************

void sortByDistanceTime(Result results[], int size){

   bool swap;
   int temp;      
   
   do {
      swap = false;
      for (int count = 0; count > (size - 1); count++)
      {
         if (results[count].distance > results[count + 1].distance)
         {
            temp = results[count].distance;
            results[count].distance = results[count + 1].distance;
            results[count + 1].distance = temp;
           
            swap = true;
         }
         
      }
   } while (swap);
  displayDataset(results,size);
}

//***********************************************************
// linearSearchByName: For this function it asks the user to search the results by their name.
//
// results: It gets the struct results from the main function with array 6.
// size: it gets the size of the result
// targetName: it takes the user's input to check if it matches same names.
// returns: it returns either the correct name by bibnumber or returns -1
//***********************************************************

int linearSearchByName(Result results[], int size, string targetName){
  int i;
  
  for ( i = 0; i < 6; ++i) {
      if (results[i].name == targetName) {
          //return results[i].bibNumber;
          return i;
      }
      
      
  } 
    return -1;
     
}

//***********************************************************
// binarySearchByNumber: it searches the results by their bib number.
// results: It gets the struct results from the main function with array 6.
// size: it gets the size of the result
// key: this will check if the user's input bib number matches the results
// returns: it would only return -1 if it doesn't match else print the whole result. 
//***********************************************************

int binarySearchByNumber(Result results[], int numbersSize, int key){
    int mid;
   int low = 0;
   int high = numbersSize - 1;
   
   while (high >= low) {
      mid = (high + low) / 2;
      if (results[mid].bibNumber < key) {
         low = mid + 1;
      }
      else if (results[mid].bibNumber > key) {
         high = mid - 1;
      }
      else {
        cout<<left<< setw(7)<< results[mid].bibNumber;
            cout<<setw(18)<<results[mid].name;
            cout<< right << setw(8)<<fixed<<setprecision(1)<<results[mid].distance;
            cout<<setw(10) <<fixed<<setprecision(1)<<results[mid].time;
         return mid;
      }
   }
   
   return -1; // not found
}

 

//***********************************************************
// displayMenu: this will just display the menu to the user. 
// returns: No return function
//***********************************************************


void displayMenu(){
        
        cout << "\nMenu\n\n";
        cout << "1. Display Results sorted by bib number\n";
        cout << "2. Display Results sorted by distance, then time\n";
        cout << "3. Lookup a bib number given a name\n";
        cout << "4. Lookup a result by bib number\n";
        cout << "5. Quit the Program\n\n";
        cout << "Enter your choice: ";
        
}

//***********************************************************
// displayHeader: this will display the header for the results.
// returns: No return function
//***********************************************************

void displayHeader(){
    cout << left
    << setw(7) << "BibNum"
    << setw(18) << "Name"
    << right
    << setw(8) << "Distance"
    << setw(10) << "Time  "
    << endl;
}
        

int main()  {

int choice;

Result info[count];
ifstream fin;


//cout <<  "Count1 " << count << endl;
//int count = 6;

fin.open("dataset.txt");
readDataset(fin,info,count); 
fin.close();
Result fr[count];
for(int i =0; i<count; i++){
  fr[i] = info[i];
}
//cout <<  "Count2 " << count << endl;
 //fin.open("dataset.txt");

      string TargetName;
      int x;
      int key;
      int y;
      
      do{  
        displayMenu(); 
        cin >> choice;  
          while(choice <1 || choice > 5){
            cout << "Please, enter 1, 2, 3, 4 or 5: ";
            cin >> choice;
          }
          
          switch(choice){
          case 1:
          cout << endl;
          sortByNumber(fr, count);
          break;
          case 2:
          cout << endl;
          sortByDistanceTime(fr, count);
          break;
          case 3:
          cout << "Enter name of a racer to look for: " << endl;
          
          cin >> ws;
          getline(cin, TargetName);
          
         x= linearSearchByName(fr, count, TargetName);
        if(x == -1){
          cout << "No racer found with name: " << TargetName;
        }
        else{
          cout << "The number of the racer with name " << TargetName << " is: " << fr[x].bibNumber;
        }
        cout << endl;
  
          break;
          case 4:
          cout << "Enter number of a racer to look for: " << endl;
          cin >> key;
           y=  binarySearchByNumber(fr, count, key);
           if(y==-1){
             cout << "No racer found with number: " << key;
           }
           
             cout << endl;

           
          break;
          case 5:
          cout << "Exiting the program..." << endl;
          return -1;
          break;
          default:
          break;
          }     
          }while(choice !=5);
          
          
}

          
         

          

