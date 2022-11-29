#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

//function to create node
struct node* createNode(int element){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = element;
    n->left = NULL;
    n->right = NULL;
    return n;
}

//preorder traversal in binary tree
void preOrder(struct node* root){
   
   if (root != NULL){
     printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
   }

  

 }

  //postorder traversal in binary tree
 void postOrder(struct node* root){

    if (root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data); 
    }

}


  //inorder traversal in binary tree
  void inOrder(struct node* root){
    
    if(root != NULL){
        postOrder(root->left);
        printf("%d ",root->data);
        postOrder(root->right);
    }

  }



int main(){

    //creating the root node
    struct node* root = createNode(1);
    struct node* lchild = createNode(2);
    struct node* rchild = createNode(3);

    root->left = lchild;
    root->right = rchild;
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    inOrder(root);


}
