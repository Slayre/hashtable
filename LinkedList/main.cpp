/*
 * main.cpp
 *
 *  Created on: Feb 24, 2019
 *      Author: cole
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "linkedlist.hpp"
using namespace std;

typedef Node* NodeP;


int main()
{

	Node list;


	ifstream is;
	is.open("nums.txt");

	int tempint = 0;

	//initialize linkedlist with the first 50 values
	for (int n = 0; n < 50; n++){
		tempint = is.get();
		NodeP temp = new Node();
		list.add_at_head(temp, tempint);
	}

	//just add each number to the linkedlist in reverse
	for(int i = 0; i < 99; i++){
		for(int j = 0; j < 50; j++){
			NodeP temp = new Node(tempint);
			tempint = is.get();
			list.add(temp);
		}
		cout << "Adding no. " << i <<endl;
		//add after each num has been inputted
	}


	return 0;
}


/*
CS 400 Assignment 3
This assignment is adopted from Project Euler Question 13.

Requirement
- use file for the input (nums.txt)
- (recommended) use only one linked list to hold intermediate answer and final answer. You may use another one to reverse the answer.
- store the num reversely in the linked list. For example, the num 123 is stored as 3 (at first node), 2 (at second node)
 and 1 (at third node) in the linked list.
- write a function that performs the addition of numbers. This function will be called in the main.
- write a function that prints out the answer. The answer includes two parts: the total summation and the first 10 digits of the summation.
- comment the code clearly, especially for the number addition mechanism.

Grading
- compilable and meaningful attemps: 30 points. That is, the code must be compilable while it cannot be just a compilable hello world.
- linked list implementation: 20 points. The implementation should have at least following functions: add_at_head(), add_at_tail(), search(), set(), del(), traverse().
- functionality: 40 points. (file, string number handling, linked list usage and addition mechanism, answer printing)
- comment & indentation: 10 points.
- Total score: 30 + 20 + 40 + 10 = 100 points.

Submission:
- due: mar 1, 11:59pm
- please submit through handin program. Command: ~cs400/bin/handin 3 your_files.cpp nums.txt
*/


