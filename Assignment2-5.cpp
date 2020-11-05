#include<bits/stdc++.h>
using namespace std;
/*
Creator: Justin Rapczynski
Contact Information: JustinRapczynski@my.unt.edu
Title: CSCE 3110 Assignment 2: Breadth First Search
Insperation for my BFS algorithim was taken from the geeksforgeeks BFS tutorial
*/
//#define size 100;

typedef long long numofv;
vector <vector<numofv> > adjacency_list; 
vector <bool> visited; 
void inff();
void bfs(long long);  
void p2f();

int main()
{
    cout << endl;
    //call to get all the information from data2.txt
    inff();
    //call for our breadth first search
    bfs(2); 
    cout << "Program is complete! Please check out2.txt for results" << endl << endl;
}

//function that gets all information needed from data2.txt
void inff()
{
    cout << "Taking in information from data2.txt ...." << endl << endl;
    int x, y;
    //actual lines of input
    string line;
    //# of lines in input file
    int lCount = 0;
    //number of vericies
    numofv n;
    //open up our input file
    ifstream in("data2.txt"); 
    //count number of lines
    while (getline(in, line))
    {
        lCount++; 
    }
    n = lCount;
    //resize list for number of verticies
    adjacency_list.resize(n); 
    in.close();
    in.open("data2.txt");
    //get the data from each line of data2.txt
    while (getline(in, line))
    {
        istringstream is_string_stream(line);
        is_string_stream >> x;

        while( is_string_stream >> y)
        {
            adjacency_list[x - 1].push_back(y - 1); 
        }
    }
    visited.resize(n,false);
    in.close();
}

// Print function
void p2f ()
{
    bool connectedCheck = true;
    ofstream out("out2.txt");
    // check for connection
    for(numofv i = 0; i < visited.size(); i++)
    {
        if(visited[i] == false)
        { // Prints out when the graph is not connected
            out << "Graph is NOT connected" << endl;
            connectedCheck = 0;
            out.close();
            break;
        }
    }
    if(connectedCheck == true)
    { // Prints out when graph is connected
        out << "Graph IS connected" << endl; 
        out.close();
    }
    
}




// function that does the Breadth First Search
void bfs(numofv x)
{
    cout << "Performing BFS on given data...." << endl << endl;
    //checks if we already visited a spot
    visited[x]=true;
    queue <numofv> queue1; 
    numofv current;
    queue1.push(x); 
    //standard bfs sorting 
    while(!queue1.empty())
    {
        current=queue1.front();
        queue1.pop();

        for(numofv i = 0; i < adjacency_list[current].size(); i++)
        {
            if(!visited[adjacency_list[current][i]]) 
            {
                visited[adjacency_list[current][i]] = true; 
                queue1.push(adjacency_list[current][i]); 
            }
        }
    }
    bool connected=1;
   p2f();
}

