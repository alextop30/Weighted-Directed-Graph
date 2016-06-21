#include "wdigraph.h"
/*
* Function depth first search is responsible for performing
* depth first search using the adjacency matrix and printing
* the resulting path taken. This accomplished with a helper
* vector for visited flags and a stack holding the traversal
*
* Function takes a starting position on the adjacency matrix
* it does not return but prints the path to the console
*/

void wdigraph:: depth_first (int u) const
{
						//vector to show visited nodes
						//visited are set to 1
						//non visited are set to 0
	vector <int> visited(get_size(),0);

						//stack that keeps the path
						//that is taken through the
						//adjacency matrix
	stack <int> path;

	path.push(u);				//push the first element on the stack

	int mynum = u;				//make a copy of the element passed in for use

	visited[mynum] = 1;

	cout << label[mynum];			//print the label for the first element

	while(!path.empty())			//while the stack is not empty
	{					//go through the matrix row looking
						//for connections

		for (int i = 0; i < get_size(); ++i)
		{
						//if a connection exists and it has not
						//been visited push it - mark it so
						//push it on the stack and print
						//the label for the path
						//set counter to -1 to start from
						//zero the next time the loop runs

			if (adj_matrix[path.top()][i] > 0 && visited[i] < 1)
			{
				visited[i] = 1;
				cout << "->";
				cout << label[i];
				path.push(i);
				i = -1;
			}
	 	}

		path.pop();			//once the iner loop has finished pop
						//a path off the stack and start from
						//zero the same evaluation
	}

	cout << endl << endl;			//advance the cursor a complete blank line
}


/*
* Function print graph responsible for priting number of nodes
* in the graph along with the entire adjacency matrix in a
* neatly formatted table order - this function is constant
*
* Function does not return but it prints the information to
* the console
*/

void wdigraph :: print_graph ( ) const
{
	cout << endl;				//advance cursor to a new line

						//print Number of nodes in the matrix
	cout << "No of Nodes = " << get_size() << endl << endl;

						//Matrix header
	cout << "Adjacency Matrix" << endl << endl;

	cout << "  |";				//table format


						//for loop - that prints each label
						//in order as top headers of the
						//matrix table
	for (unsigned int j = 0; j < label.size(); j++)
	{

		cout << setw(3)  << label[j];	//print header one at a time
	}

	cout << endl;

	cout << "--|";				//additional table format

						//table format for bottom dash
						//line located under the label
						//top header
	cout << setfill('-') << setw((((label.size())*3)+1)) << " " << endl;
	cout << setfill(' ');			//stop the effect of filll


						//nested set of for loops
						//responsible for printing the matrix
						//in both dimensions z-down i-accross
	for (unsigned int z = 0; z < label.size(); z++)
	{
		cout << label[z] << " |";	//table format separates the label
						//headers down the table


		for (unsigned int i = 0; i < label.size(); i++)
		{
			cout << setw(3);	//each number is separated by 2 spaces
						//if a weight in the matrix is zero
						//a dash is printed in its place
			if( adj_matrix[z][i] == 0)
			{
				cout << "-";
			}
			else
			{
						//print the non zero weight
				cout << adj_matrix[z][i];
			}

		}

		cout << endl;
						//stop printing downward separator
						//at the end of the table
		if ( z != ((label.size()) -1))
		{
			cout << "  |" << endl;
		}
	}

	cout << endl;				//advance the cursor to the next line
}



