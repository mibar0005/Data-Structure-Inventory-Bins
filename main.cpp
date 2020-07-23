//Miguel Ibarra
//Warehouse Bin Project

//header files
#include <iostream>
#include <string>
using namespace std;

//Create a bin structure and add data to it
struct Bin
{
  string partDesc;      //Part Description
  int numOfParts;       //Number of parts 
};

//Function Prototypes
void addParts (int, int);
void removeParts(int, int);
void getParts(int);

//initialize a contant value
const int PARTS = 10;

//initialize structure Bins variables
//Create a initialize the elements in the array
//of 10 bin structures
Bin bins[PARTS] = {{"Valve:\t\t\t\t\t\t", 10}, {"Bearing: \t\t\t\t\t", 5}, {"Brushing: \t\t\t\t\t", 15}, {"Coupling: \t\t\t\t\t", 21}, {"Flange: \t\t\t\t\t", 7}, {"Gear: \t\t\t\t\t\t",5}, {"GearHousing: \t\t\t\t", 5}, {"Vacuum Gripper: \t\t\t", 25}, {"Cable: \t\t\t\t\t\t", 18}, {"Rod:\t\t\t\t\t\t", 12} };

//Start of main function
int main ()
{
  //declare the variables 
  string bin;
  //This true value is used to enter the loop
  bool b = true;

  while (b)
  {
    //Program display
    cout << endl;
    cout << "******************************************************\n";
    cout << "Part Description          Number of parts in the Bin *" << endl;
    cout << "******************************************************\n";

    //Display the parts and number of units
    for (int index = 0; index < PARTS; index++)
    {
      cout << bins[index].partDesc << " " << bins[index].numOfParts << endl;
    }
    
    cout << "*******************************************\n\n";

    //Read the user input of required Bin type 
    //read bin type
    cout << "Please select a bin: ";
    cin >> bin;

    //Check bin types 
    if (bin == "Valve")
    {
      getParts(0);    //Call getParts Function
    }
    else if (bin == "Bearing")
    {
      getParts(1);    //Call getParts Function
    }
    else if (bin == "Brushing")
    {
      getParts(2);    //Call the getParts Function
    }
    else if (bin == "Coupling")
    {
      getParts(3);    //Call the getParts Function
    }
    else if (bin == "Flange")
    {
      getParts(4);    //Call the getParts Function
    }
    else if (bin == "Gear")
    {
      getParts(5);
    }
    else if (bin == "Gear Housing")
    {
      getParts(5);    //Call the getParts Function
    }
    else if (bin == "Vacuum Gripper")
    {
      getParts(7);    //Call the getPartsFunction
    }
    else if (bin == "Cable")
    {
      getParts(8);
    }
    else if (bin == "Rod")
    {
      getParts(9);
    }
    else 
    {
      b = false;
    }

  }

  //end of main function 
  return 0;
}

//getParts() function is used to get the bin
//getParts() function definition
void getParts(int index)
{
  string result;
  int parts;

  //read the user input to add or remove parts 
  cout << endl;
  cout << "Do you want to add or remove parts? ";
  cin >> result;

  //function call to add parts
  if (result == "add")
  {
    cout << endl;
    cout << "How many parts do you want to add? ";
    cin >> parts;
    addParts(parts, index);
  }
  //Function call to remove parts
  else if (result == "remove")
  {
    cout << endl;
    cout << "How many parts you want to remove? ";
    cin >> parts;
    removeParts(parts, index);
  }
  else
  {
    cout << endl;
    cout << "Sorry, you did not choose any one. \n\n";
  }

//end of getParts Function 
}

//addParts Function is used to add the given 
//number of parts to existing parts.
//add the parts to appropiate bin
//addParts Function Definition
void addParts(int parts, int idx)
{
  //Veryfy that the parts do not go over 30
  if ((bins[idx].numOfParts + parts) > 30)
  {
    cout << endl;
    cout << "Sorry, you have entered " << 30 - bins[idx].numOfParts << endl;
    cout << "The bin capacity is 30 \n\n";
  }
  else 
  {
    bins[idx].numOfParts = bins[idx].numOfParts + parts;
  }

  //end of addParts Function
}

//removeParts function is used to remove 
//a given number of units  from the bin
//removeParts function definition
void removeParts (int parts, int idx)
{
  //check for < 0 parts 
  if ((bins[idx].numOfParts - parts) < 0)
  {
    cout << endl;
    cout << "Sorry, you have enetered the parts to "
        << "be removed more than " << bins[idx].numOfParts
        << endl; 
  }
  else 
  {
    bins[idx].numOfParts = bins[idx].numOfParts - parts;
  }

  //end of removeParts Function 
}