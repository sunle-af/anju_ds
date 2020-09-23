//basically we have to make a databases sytstem with some details of the students now the thing is
// in quetsion is it given use only the linked list
// the problem can be sloved by using hasing but as it was said to use only the linked list we are doing it 
// more inforamtion this program has too many limitation like too many execetptions are there which it cant handled it 
// is only for the trival solution 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// we are using it for better readability
typedef char* String;

// we are structin student which have following data 
typedef struct student {
 
     String other;
     String name;
     String coursecode;
     int age;
     String branch;
  struct student *next;
} Student;

// Students List type
typedef struct {
  Student *start;
  Student *end;
} Students_list;

// createing a new student, which allocat the memory and copy the values...
Student * createStudent(
String other,String name,String coursecode,int age,
  String branch) {
  // malloc is used for allcataion of the new student 
  Student *student = (Student *)malloc(sizeof(Student));
  if(student == NULL) return NULL;
  //now the -> arrow funciton or symbol is allocationg the memory for the name of the studets and so on 
   
  student->name = (String)malloc(strlen(name) + 1);
  if(student->name == NULL) return NULL;
  // copying the values strcpy
  strcpy(student->name, name);
  
  student->other = other;
  
  student->coursecode = coursecode;
  student->age = age;
  student->branch = branch;
  
  student->next = NULL;
  return student;
}

 
//it is creating a new Studnet list and the setting starting and end to an NULL list or an empty list
 Students_list * createliststudent() {
  // allocate memory for a new students list
  Students_list *students_list = (Students_list *)malloc(sizeof(Students_list));
  if(students_list == NULL) return NULL;
  // initialise the start and end to NULL so it's an empty list ready to be filled
  students_list->start = students_list->end = NULL;
  return students_list;
}

// add a new student to the students_list
bool pushlist(Students_list *students_list,  
String other,String name,String coursecode,int age,
  String branch ) {
  // create a new srtudent
  Student* student = createStudent(other,name,coursecode,age,branch);
  if(student == NULL) return false;
  // empty students_list
  if(students_list->start == NULL) {
    students_list->start = students_list->end = student;
  // has only one element
  }else if(students_list->start == students_list->end) {
    students_list->start->next = students_list->end = student;
  // has more than one element
  }else {
    students_list->end->next = student;
    students_list->end = students_list->end->next;
  }
  return true;
}

// print the items of the student list(array like output)
void printlist(Students_list *students_list,int comp) {
  Student *tmpStudent = students_list->start;
   
  
  // loop over the students_list
  while(tmpStudent != NULL) {

    printf("   %s, %s, %s, %i, %s ", tmpStudent->other, tmpStudent->name, tmpStudent->coursecode,tmpStudent->age,tmpStudent->branch);
    // don't print ',' if its the last element
    tmpStudent != students_list->end && printf(",\n") || printf("\n");
    tmpStudent = tmpStudent->next;
  }
 
}
///thiis is used in order to swap the node values in case there is a need to be 
void swaplist(Students_list *students_list, Student *previousNode, Student *a, Student *b) {
  Student *tmp = a;
  // swapping the first node and the next one
  if(previousNode == NULL) {
    students_list->start = b;
    tmp->next = b->next;
    students_list->start->next = tmp;
  // swapping the last node and the previous one
  }else if(b->next == NULL) {
    previousNode->next = b;
    tmp->next = b->next;
    b->next = tmp;
    students_list->end = tmp;
  // swapping other nodes
  }else {
    previousNode->next = b;
    tmp->next = b->next;
    b->next = tmp;
  }
}
   
///  So basically it is sorting the linked list on the basis or there age
// cool thing about this is we can even sort in both the order if we set
//  s,ture it will sort for descending order and if we write s,true it will sort the list in ascending order
// we are only asked to solve it by ascending oreder of there age

 
void sortlist(Students_list *students_list, bool isReversed) {
  // store the current and the previous Student
  Student *currentNode, *previousNode, *prev_previousNode;
  // store if there still a difference in the list means that we have some Students not sorted
  bool difference;
  loopAgain:
    // looping again and assuming no more difference
    difference = false;
    currentNode = previousNode = students_list->start;
    prev_previousNode = NULL;
    // loop over the list
    while(currentNode != NULL) {
      currentNode = currentNode->next;
      // check for cgpa if the current cgpa is less than the previous and in ascending mode
      // then swap the Students and the opposite in descending mode
      if(currentNode != NULL && (isReversed ? previousNode->age < currentNode->age :
          previousNode->age > currentNode->age)) {
        swaplist(students_list, prev_previousNode, previousNode, currentNode);
        difference = true;
      }
      prev_previousNode = previousNode;
      previousNode = currentNode;
    }
  // go to loop again since there still maybe no sorted Students yet
  if(difference) {
    goto loopAgain;
  }
}
int main() {
  Students_list *s = createliststudent();
  int i, n;

  printf("Enter total of students:\n");
  scanf("%d", &n);
    
        char uq[50]; 
        char other[50];
     char name[50];
     char coursecode[50];
     int age;
     char branch[50];
     int comp;

  for(i = 0;i < n; i++) { 
    
    printf("Enter choice for student %i: ",i+1);
    printf("    \n R for Roll number   ");
    printf("    \n M for Mobile number  ");
    printf("    \n O other unique ID ");
    scanf("%s", uq);
     comp=strcmp(uq,"R");
     
     if(comp==0) {
        printf("Enter roll number of the student %i: ",i+1);
    scanf("%s", &other);
    } 
    else
    {
         printf("Enter mobile number of the student %i: ",i+1);
    scanf("%s", &other);
    }

    
    printf("Enter name of the student %i: ",i+1);
    scanf("%s", name);

    printf("Enter coursecode of the student %i:", i+1 );
    scanf("%s", coursecode);

    printf("Enter age of the student %i: ",i+1);
    scanf("%d", &age);
    
    printf("Enter branch of the student %i: ",i+1);
    scanf("%s", branch);
    
    pushlist(s,other,name,coursecode,age,branch);
  }
  sortlist(s, false); 
  printf("The sorted list of the students is: \n");
   printlist(s,comp);
  return 0;
}