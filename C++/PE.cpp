#include <iostream>

using namespace std;


struct node{
	char value;
	node *left;
	node *right;
};

class btree{
public:
	btree();
	~btree();

	void insert(char key);
	node *search(char key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(node *leaf);
	void insert(char key, node *leaf);
	node *search(char key, node *leaf);
	void inorder_print(node *leaf);
	void postorder_print(node *leaf);
	void preorder_print(node *leaf);

	node *root;
};


btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(char key, node *leaf)
{

	if (key == 'H' || key == 'V')
        {
		
	
		if(leaf->right != root)
                {
			insert(key, leaf->right);
		}
		else
                {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
                        //return;
		}
		
		if(leaf->left != root)
                {
			insert(key, leaf->left);
		}
		else
                {
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
                        //return;
		}
        }
        else if (key != 'H' && key != 'V')
        {
                        if(leaf->right != root)
                {
			insert(key, leaf->right);
		}
		else
                {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = root;
			leaf->right->left = root;
                        //return;
		}
		
		if(leaf->left != root)
                {
			insert(key, leaf->left);
		}
		else
                {
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = root;
			leaf->left->right = root;
                        //return;
		}
            
        }   
            
            
            
            

}

void btree::insert(char key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *btree::search(char key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

node *btree::search(char key){
	return search(key, root);
}

void btree::destroy_tree(){
	destroy_tree(root);
}

void btree::inorder_print(){
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void btree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void btree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

int main(){

	//btree tree;
	btree *tree = new btree();

	
	
	
	
	
	
	
        
        
        
        
        
        tree->insert('V');
        tree->insert('H');
        tree->insert('4');
        tree->insert('3');
        tree->insert('H');
        tree->insert('V');
        tree->insert('5');
        tree->insert('7');
        tree->insert('V');
        tree->insert('2');
        tree->insert('H');
        tree->insert('6');
        tree->insert('1');
        

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

	delete tree;

}
