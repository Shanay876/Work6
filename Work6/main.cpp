//
//  main.cpp
//  ExtraCredit2
//
//  Created by Shanay Saddler on 11/18/14.
//  Copyright (c) 2014 ___SHANAY SADDLER___. All rights reserved.
//
#include <fstream>//header files
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>
using namespace std;
void get_user_input(char&, int&, int&, int&, int&);//declare functions
float compute_item_cost (char, int, int, int, int);
string gettype(char);
int main()
{
    cout<<"********************************************************************************************************\n";//Heading for the program
    cout << "Shanay Saddler" << endl;
    cout << "ID 02713672" << endl;
    cout << "SYCS-135 Computer Science I" << endl;
    cout << "Extra Credit" << endl;
    cout << "November 18, 2014" << endl;
    cout<<"********************************************************************************************************\n";
    int width, height, length, numofpieces;// declare variables
    char typeofwood;
    get_user_input(typeofwood, width, length, height, numofpieces);//call the get user input function..its not returning anything
    
}
void get_user_input(char& typeofwood, int& width, int& length, int& height, int& numofpieces)
{
    float total= 0,cost;
    string WOODTYPE;
    cout<<"Enter item <WOOD TYPE---No. of pieces---Width---Height---Length>"<<"\n";//prompting the user to enter info..(priming read)
    cin>>typeofwood>>numofpieces>>width>>height>>length;
    while(typeofwood!='T')//checking to see if T was entered for the type
    {
        WOODTYPE = gettype(typeofwood);//returns the string of what each letter represents
        cost = compute_item_cost (typeofwood, width, length, height, numofpieces);//compute the cost based on info entered
        total = total + cost;//defining total
        cout<<numofpieces<<" "<<width<<"X"<<height<<"X"<<length<<" "<<WOODTYPE<<", cost: $"<<setprecision(4)<<cost<<"\n";//print out
        cout<<"********************************************************************************************************\n";
        cout<<"Enter item <WOOD TYPE---No. of pieces---Width---Height---Length>"<<"\n";//prompt to see if T will be entered..If not..it loops again
        cin>>typeofwood;// if T is entered just read the type and break
        if (typeofwood!='T')//If T is not entered then you continue to input the other values
            cin  >> numofpieces>>width>>height>>length;
    }
    cout<< "Total is: $"<<(total)<<"\n";//if T is entered then output the total
}

float compute_item_cost (char typeofwood, int width, int length, int height, int numofpieces)//function to calculate cost
{
    float boardfoot;
    float cost;
    boardfoot= float(width*length*height)/12;
    if (typeofwood=='P')
        cost = boardfoot* 0.89*numofpieces;
    else if (typeofwood=='F')
        cost = boardfoot* 1.09*numofpieces;
    else if (typeofwood=='C')
        cost = boardfoot* 2.26*numofpieces;
    else if (typeofwood=='M')
        cost = boardfoot* 4.50*numofpieces;
    else
        cost = boardfoot* 3.10*numofpieces;
    return cost;
}
string gettype(char typeofwood)//function to define letters from input
{
    string Pine, Fir, Cedar, Maple, Oak;
    if (typeofwood=='P')
        return (Pine = "Pine");
    else if (typeofwood=='F')
        return (Fir = "Fir");
    else if (typeofwood=='C')
        return (Cedar = "Cedar");
    else if (typeofwood=='M')
        return (Maple = "Maple");
    else
        return (Oak = "Oak");
}
/*
 ********************************************************************************************************
 Shanay Saddler
 ID 02713672
 SYCS-135 Computer Science I
 Extra Credit
 November 18, 2014
 ********************************************************************************************************
 Enter item <WOOD TYPE---No. of pieces---Width---Height---Length>
 P 10 2 4 8
 10 2X4X8 Pine, cost: $47.47
 ********************************************************************************************************
 Enter item <WOOD TYPE---No. of pieces---Width---Height---Length>
 M 1 1 12 8
 1 1X12X8 Maple, cost: $36
 ********************************************************************************************************
 Enter item <WOOD TYPE---No. of pieces---Width---Height---Length>
 T
 Total is: $83.47
 Program ended with exit code: 0
 */
