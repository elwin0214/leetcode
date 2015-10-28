/*
https://leetcode.com/problems/lru-cache/
LRU Cache My Submissions Question


Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

思路：
参考java LinkedHashMap

*/

#include <vector>
#include <map>
#include <set>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Node{
	int key;
	int value;
 struct Node *next;
	struct Node *before;
public:
	Node(int key,int value):key(key),value(value),next(NULL),before(NULL)
	{

	}
};
class List
{
private:
	struct Node *head;
	struct Node *tail;
public:
	List():head(NULL),tail(NULL)
	{

	}
	void addHead(Node *node)
	{
		//Node *n=new Node(value);
		if(head==NULL)
		{
			head=node;
			tail=node;
			return;
		}
		node->before=NULL;
		node->next=head;
		head->before=node;
		head=node;
	}
	void moveToHead(Node *node)
	{
		if(node==head)
		{
			return;
		}
		if(node==tail)
		{
			node->before->next=NULL;
			tail=node->before;
		}else{
			//list();
			node->next->before=node->before;
			node->before->next=node->next;
			//list();
		}
		node->next=head;
		head->before=node;
		head=node;
	}
	 
	Node* removeTail()
	{
		if(tail==NULL)return NULL;
		Node* node=tail;
		tail=tail->before;
		node->before->next=NULL;
		node->before=NULL;
		return node;
	}
	void listValues(){
		Node *node=head;
		if(node==NULL)return;
		while(node!=NULL)
		{
			cout<<node->value<< " ";
			node=node->next;
		}
		cout<<endl;

	}

	~List(){
		Node *node=head;
		if(node==NULL)return;
		while(node!=NULL)
		{	Node *tmp=node->next;
			cout<<"delete "<<node->key<<endl;
			delete node;
			node=tmp;
		}
		//cout<<endl;
	}
};
class LRUCache{
private:
	int capacity;
	map<int,Node*> data;

	List list;
public:
	LRUCache(int capacity):capacity(capacity)
	{
  	      
  }
	int get(int key) 
	{
		map<int,Node*>::iterator it=data.find(key);
		if(it==data.end())
		{
			return -1;
		}
		//cout<<"get "<<key<<endl;
		//moveToBefore(it->second);
		list.moveToHead(it->second);
		return it->second->value;
	}
	 
    
  void set(int key, int value) 
  {
		map<int,Node*>::iterator it=data.find(key);
		if(it==data.end())
		{
			Node *node=new Node(key,value);
			data.insert(pair<int,Node*>(key,node));
			list.addHead(node);
			if(data.size()>capacity)
			{
				Node* node=list.removeTail();
				//cout<<"remove " <<node->value<<endl;
				int deleteKey=node->key;
				delete node;
				map<int,Node*>::iterator it=data.find(deleteKey);
				data.erase(it);
			}
		}
		else
		{
			list.moveToHead(it->second);
			it->second->value=value;
			
		}
		        
  }

  void listValues()
  {
  	list.listValues();
  }
	
};

int main(){
	  Node n(1,2);
	  Node *a=new Node(1,2);
	  cout<<a->next<<endl;

	  List list;
 
 {
 	LRUCache cache(1) ;
 	cache.set(2,1);
 	cache.get(2);
 	cache.set(3,2);
 	cache.get(2);
 	cout<<	cache.get(3)<<endl;
 }

 {
 	LRUCache cache(2) ;
 	cache.set(2,1);
 	cache.set(2,2);
 	cout<<cache.get(2)<<endl;
 	cache.set(1,1);
 	cache.set(4,1);
 	//cache.get(2);
 	cout<<	cache.get(2)<<endl;
 }




}