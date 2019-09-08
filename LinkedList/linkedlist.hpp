/*
 * linkedlist.hpp
 *
 *  Created on: Feb 24, 2019
 *      Author: cole
 */


class Node{
	typedef Node* NodeP;
	int data;
	NodeP next;
public:
	Node(){
		this->data = 0;
		this->next = NULL;
	}
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
	Node(NodeP next, int data){
		this->data = data;
		this->next = next;
	}

	void add_at_head(NodeP& head, int data)
	{
		NodeP temp = head;
		head = new Node(data);
		head->next = temp;

	}
	void add_at_tail(NodeP& head, int data)
	{
		if (head == NULL) {
			head = new Node(data);
		}
		else {
			NodeP temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new Node(data);
		}
	}
	void del(NodeP& head, int target) {
		// first case: when the l.l. is empty
		if (!head) {
			return;
		}
		//second case: when it is head to be deleted.
		if (head && head->data == target) {
			NodeP temp = head;
			head = head->next;
			delete temp;
		}
		NodeP prev = NULL;
		NodeP curr = head;
		while (curr != NULL && curr->data != target) {
			prev = curr;
			curr = curr->next;
		}
		if (curr == NULL) {
			return;
		}
		// fourth case: find a non-head node target
		// delete the node pointed by the curr
		prev->next = curr->next;
		delete curr;

	}
	NodeP add(NodeP& node)
	{
		int data = this->data;
		data += node->data;
		int remainder = data / 10;
		data %= 10;
		this->data = data;
		this->next->data += remainder;
		return this;
	}
	void print(NodeP& head)
	{

		while(head != NULL){
			std::cout << head->data;
			head = head->next;
		}
	}


};


