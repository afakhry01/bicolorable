/** *********************************************************************
 * PROJECT: BiColorable
 *
 * DEVELOPMENT ENVIRONMENTS
 * Windows 10 with CLion 2017.2.1
 * Windows 10 with Visual Studio 2017
 *
 * HISTORY:
 * Date             Author              Description
 * ====             ======              ===========
 * 10/10/17         Andrew Fakhry       Initial build
 * 10/11/17         Andrew Fakhry       Development and fixing errors
 * 10/12/17         Andrew Fakhry       Fixing errors and testing
 * 10/12/17         Andrew Fakhry       Move to Visual Studio 2017 on Win 10
 *
 * DESCRIPTION:
 * A simple project that uses a single .cpp file program that conforms
 * to C++ 11 following Montana Tech Method Software Development Standard
 **********************************************************************  */


//--------------------
// C++ includes
//--------------------
#include <iostream>
#include <vector>

//--------------------
//Global constants
//--------------------
const int MAX_NODES = 199;

//--------------------
//Global variables
//--------------------
int nodeColorArray[MAX_NODES];
std::vector<int> adjacencyList[MAX_NODES];

//--------------------
//Function prototypes
//--------------------
bool
isBicolorable(int colorArray[], int nmbrNodes);

int
oppositeColor(int colorCode);

int
main() {
/** ------------------------------------------------------------------------------------------------------
 * DESCRIPTION
 * Calculates the possibility of having a BiColorable (bipartite)
 * set of nodes when they are connected through a number of edges
 * through searching for two adjacent nodes with the same color.
 *
 * REQUIREMENTS
 * R01  Input begins with a positive integer, nmbrNodes, indicating the number of nodes in the file.
 * R02	Second input is a positive integer, nmbrEdges, indicating the number of edges in the file.
 * R03	Two integer inputs, firstNode and the second node in one line separated with a single space.
 * R04	Last input, endProcess, indicates the end of inputs. EOF when endProcess is equal to zero.
 * R05	If nodes are bicolorable, Output prints out “BICOLORABLE”.
 * R06  If nodes are not bicolorable, Output prints out “NOT BICOLORABLE”.
 *
 * Sample run(s)
 * -------------
 *
 * RUN 1:
 * stdin:
 * 3
 * 3
 * 0 1
 * 1 2
 * 2 0
 * 9
 * 8
 * 0 1
 * 0 2
 * 0 3
 * 0 4
 * 0 5
 * 0 6
 * 0 7
 * 0 8
 * 0
 * stdout:
 * NOT BICOLORABLE.
 * BICOLORABLE.
 *
 * RUN 2:
 * stdin:
 * 4
 * 4
 * 0  1
 * 1  2
 * 2  3
 * 3  4
 * 0
 * stdout:
 * BICOLORABLE.
 *
 *
 * DESIGN
 * Significant variables & Solution Principals
 * -------------------------------------------
 * int nodeColorArray[] // An array to hold nodes colors
 * vector<int> adjacencyList[] // A vector to hold adjacent nodes
 * int nmbrNodes // Number of nodes - user input
 * int nmbrEdges // Number of edges - user input
 * int firstNode // First node of two connected nodes - user input
 * int secondNode // Second node of two connected nodes - user input
 *
 * Search for any two adjacent nodes that has the same color
 *
 * Algorithm
 * ---------
 * A01	Define:
 * 			const int MAX_NODES = 198;
 * 			bool nodeColorArray[MAX_NODES];
 * A02  While(true){
 * A03      Read nmbrNodes from stdin;
 * A04	    if (nmbrNodes is equal to 0) {
 * A05		    Exit;
 *          }
 * A06      Read nmbrEdges from stdin;
 * A07	    Populate nodeColorArray[] by assigning all values to zero
 * A08      Populate adjacencyList[] by reading from stdin
 * A09		    If (isBiColorable(nodeColorArray[], nmbrNodes) {
 * A10			    Write BICOLORABE. to stdout;
 * 			    }//If
 * A11		    Else {
 * 				    Write NOT BICOLORABE. to stdout;
 * 		}//While processing all graphs in input file
 * A13	Return to invoker;
 *
 * Algorithm Correctness Argument
 * ------------------------------
 * CR01	By  A01 definition of "Define".
 * CR02 By  A02 and A03 and A04 definition of "Read".
 * CR03 By  A05 and A06 cause program termination if input is zero.
 * CR04 By  A07 definition of "Populate"
 * CR05 By  A08 definition of "Read".
 * CR06 By  A09 and A10 and A11 definition of "Display".
 *
 * CODE CORRECTNESS ARGUMENT
 * CA01 By  L01 by  declaring constants.
 * CA02 By  L02 by  definition of cin.
 * CA03 By  L03 by  definition of ==.
 * CA04 By  L04 by  definition of =.
 * CA05 By  L05 by  definition of cin.
 * CA06 By  L06 by  definition of cout and function invocation.
 *
 * CALLING TREE
 * isBicolorable()
 * oppositeColor()
 ---------------------------------------------------------------------------------------------------------- */
/*L02*/ while (true) {
            int nmbrEdges, nmbrNodes;
            std::cin >> nmbrNodes;
/*L03*/     if (nmbrNodes == 0)
                return 0;
            std::cin >> nmbrEdges;
/*L04*/     for (int i = 0; i < nmbrNodes; ++i) {
                nodeColorArray[i] = 0;
                adjacencyList[i].clear();
            }
/*L05*/     for (int i = 0; i < nmbrEdges; ++i) {
                int firstNode, secondNode;
                std::cin >> firstNode >> secondNode;
                adjacencyList[firstNode].push_back(secondNode);
                adjacencyList[secondNode].push_back(firstNode);
            }
/*L06*/     if (isBicolorable(nodeColorArray, nmbrNodes)) {
                std::cout << "BICOLORABLE." << std::endl;
            } else {
                std::cout << "NOT BICOLORABLE." << std::endl;
            }
        } // while(true)
    } // main()

int
oppositeColor(int colorCode) {
/** ----------------------------------------------------------------------------
 * DESCRIPTION - oppositeColor
 * Return 1 (blue) if input is 2 (red) and vice versa.
 *
 * REQUIREMENTS
 * R01  On entry colorNode is guaranteed to be either 1 or 2.
 * R02  On entry the return value is guaranteed to be either 1 or 2.
 *
 * SAMPLE INVOCATION
 * colorCode = 1
 * return 2
 * colorCode = 2
 * return 1
 *
 * DESIGN
 * Significant variables & Solution Principles
 * -------------------------------------------
 * int colorCode //input and output parameter
 * Return 1 if colorCode is equal to 2 OR
 * Return 2 if colorCode is equal to 1
 *
 * Algorithm
 * ---------
 * A01  if (colorCode == 1)
 *          return 2;
 * A02  if (colorCode == 2)
 *          return 1;
 * -----------------------------------------------------------------------------*/
/*L01*/ if (colorCode == 1)
            colorCode = 2;
/*L02*/ else if (colorCode == 2)
            colorCode = 1;
        return colorCode;
}//end oppositeColor()

bool
isBicolorable(int colorArray[], int nmbrNodes) {
/** ----------------------------------------------------------------------------
 * DESCRIPTION - isBicolorable
 * Return true if nodes are bicolorable or false if nodes are not bicolorable.
 *
 * REQUIREMENTS
 * R01 On entry colorArray[] is an array of nodes colors
 * R02 Returns true if the graph represented by colorArray[] is bi-colorable or
 *     false otherwise
 *
 * SAMPLE INVOCATION
 * See main() Sample Runs
 *
 * DESIGN
 * Significant variables & Solution Principles
 * -------------------------------------------
 * int colorArray[], nmbrNodes //input parameter
 * Return false if two adjacent nodes have the same color
 * Return true otherwise
 *
 * Algorithm
 * ---------
 * A01 Set colorArray[0] = ‘0’;
 * A02 For (i from 0 though nmbrNodes) {
 * A03	For (j from 0 through adjacencyList.size()) {
 * A04		if (colorArray[adjacencyList <j>] == ‘0’) {
 * A05			Set colorArray[adjacencyList <j>] = oppositeColor(colorArray[i]);
 * 			}//if
 * A06		elseif (colorArray[adjacencyList <j>] == colorArray[i]) {
 *    			return false;
 * 			}//elseif
 * A07		else {
 *  			continue;
 * 			}//else
 * 		}//for
 * 	 }//for
 * 	return true;
 * -----------------------------------------------------------------------------*/
/*L01*/ colorArray[0] = 1;
/*L02*/ for (int ndx = 0; ndx < nmbrNodes; ndx++) {
/*L03*/     for (int itr = 0; itr < adjacencyList[ndx].size(); itr++) {
/*L04*/         if (colorArray[adjacencyList[ndx][itr]] == 0)
/*L05*/             colorArray[adjacencyList[ndx][itr]] = oppositeColor(colorArray[ndx]);
/*L06*/         else if (colorArray[adjacencyList[ndx][itr]] == colorArray[ndx])
                    return false;
/*L07*/         else
                    continue;
            }//end for
        }//end for
        return true;
}//end isBicolorable()