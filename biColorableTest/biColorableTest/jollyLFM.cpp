//
//
//Josh Lee
//

//------------------
// C++ includes
//------------------
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>      
#include <stdlib.h>     
#include <cmath>
#include <map>
#include <queue>

//------------------
// Using statements
//------------------
using namespace std;

//---------------------
// Function prototypes
//---------------------
bool jollyCheck(int* seq);

/***********************************************************
DESCRIPTION - main
Prompts the user for a txt file containing the sequences to
check, parses the files, then calles jollyCheck. Displays
jolly if jollyCheck returns true and not jolly if jollyCheck
returns false or the line is invalid
***********************************************************/
int main(){
	    string s;
/*L01*/ while(getline(cin, s)){
/*L02*/		
	        vector<int> seq;
	        bool jolly = true;
	        stringstream temp;
	        string ss;
	        temp << s;
	        while(temp >> ss){
	            seq.push_back(atoi(ss.c_str()));
			}//while
	        if(seq[0] == 1){
	            jolly = true;
			}//if
	        else{
	            vector<bool> correct (seq.size() - 1, false);
/*L06*/         for(int i = 1; i < seq.size() - 1; i++){
/*L07*/		        int diff = abs(seq[i] - seq[i + 1]);
	                if(diff >= 1 && diff <= seq[0] - 1){
/*L08*/		             correct[i] = true;
	                }//if
	            }//for
/*L09*/         for(int a = 1; a < correct.size(); a++){
/*L11*/		        if(correct[a] == false){
	                    jolly = false;
	                    break;
	                }//if
	            }//for
	        }//else
/*L04*/     if(jolly){
	            cout << "Jolly" << endl;
			}//if
/*L05*/     else{
	            cout << "Not jolly" << endl;
			}//else
	    }//while
	    return 0;
}// main()

//end JollyJumpersLeeJoshO.cpp