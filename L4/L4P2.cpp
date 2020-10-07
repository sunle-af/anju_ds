#include <bits/stdc++.h>
using namespace std;
typedef struct  node
{
     int expo;
     int coeff ;
     node * next;
}node;
//this fuction will creates nodes for us
              
// Function to create new node 
void create_node(int x, int y, node **temp) 
{   
    node *r;
    node *z;
    z= *temp;
    if(z==NULL){
        r=(node*)malloc(sizeof(node));
        r->coeff=x;
        r->expo=y;
        *temp=r;
        r->next=(node*)malloc(sizeof(node));
        r=r->next;
        r->next=NULL;
    }
    else
    {
        r->coeff=x;
        r->expo=y;
        r->next=(node*)malloc (sizeof(node));
        r=r->next;
        r->next=NULL;

    } 
    }
//this will display the list
// Display Linked list 
void show(node *node) 
{ 
while(node->next != NULL) 
    { 
    printf("%dx^%d", node->coeff, node->expo); 
    node = node->next; 
    if(node->next != NULL) 
        cout<<" + ";
        //printf(" + "); 
    }cout<<endl;
} 
   
// Function Adding two polynomial numbers 
void polyadd(node *pl1, node * pl2, node *pls)  
{ 
while(pl1->next && pl2->next) 
    { 
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is 
        // and move its pointer 
        if(pl1->expo > pl2->expo) 
        { 
            pls->expo = pl1->expo; 
            pls->coeff = pl1->coeff; 
            pl1 = pl1->next; 
        } 
          
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is 
        // and move its pointer 
        else if(pl1->expo < pl2->expo) 
        { 
            pls->expo = pl2->expo; 
            pls->coeff = pl2->coeff; 
            pl2 = pl2->next; 
        } 
          
        // If power of both polynomial numbers is same then add their coefficients 
        else
        { 
            pls->expo = pl1->expo; 
            pls->coeff = pl1->coeff+pl2->coeff; 
            pl1 = pl1->next; 
            pl2 = pl2->next; 
        } 
          
        // Dynamically create new node 
        pls->next = (node *) malloc(sizeof(node));  
        pls = pls->next; 
        pls->next = NULL; 
    } 
while(pl1->next || pl2->next) 
    { 
        if(pl1->next) 
        { 
            pls->expo = pl1->expo; 
            pls->coeff = pl1->coeff; 
            pl1 = pl1->next; 
        } 
        if(pl2->next) 
        { 
            pls->expo = pl2->expo; 
            pls->coeff = pl2->coeff; 
            pl2 = pl2->next; 
        } 
        pls->next = (node *) malloc(sizeof(node));   
        pls = pls->next; 
        pls->next = NULL; 
    } 
} 
   
int main (){
      node *l1=NULL;
      node *l2=NULL;
      node *l3=NULL;
    //creating a node to store the sum  of list 1 and list 2
      node *listsum=NULL;
      listsum= (node*)malloc(sizeof(node));//basicallly it is allocating the memory
    //as before we are creating the node for storing the sum of the list 3 and the sum of the previous 2 list
      node* listsumf=NULL;
      listsumf= (node * )malloc (sizeof(node));//memory allocation    
   
    // Create first list of 5x^2 + 4x^1 + 2x^0 
    create_node(5,2,&l1); 
    create_node(4,1,&l1); 
    create_node(2,0,&l1);
    //displaying the first list
    show(l1); 
   
    // Creating the second list 5x^1+5x^0
    create_node(5,1,&l2);
    create_node(5,0,&l2);
    //displaying the second list
    show(l2);
   
    // Create the third list  7x^5+5x^3+6x^0
    create_node(7,5,&l3);
    create_node(5,3,&l3);
    create_node(6,0,&l3);
    show(l3);
  
    //basically the method can only add 2list so we do first addition of l1 and l2 then there sum we add with l3     
    polyadd(l1,l2,listsum);//here i added the list no1 and list no2 named as l1 and l2 repectively and stored it into the list
                         //named as listsum

    polyadd(l3,listsum,listsumf);//here i added the list listsum and list num3 named as listsum and l3 repectively and stored it into the list
                         //named as listsumf
    //finally printing out or diplaying the sum of all the three list
    show(listsumf);
    return 0;
}