#include <stdio.h>
#include <stdlib.h> //including this library for the malloc, free, calloc functions
#include <string.h> //including this library for string manipulation
struct passenger { //information of a single passenger
 char name[50]; //name is for passenger name
 char departure[50]; //departure is for passenger departure location
 char arrival[50]; //arrival is for passenger arrival location
 char date[10]; //date is for the flight date
 int seat_number; //numerical data for seat_number
 struct passenger* next; //linking the node to another
};
struct passenger* head = NULL; //initializing the head pointer
void addPassenger(struct passenger **r, char name[], char departure[], char arrival[], char date[], int seat_number){//function to add a new passenger to th list; if the passenger to be add is already in the list it prints out "Passenger already in the list!"
    if(checkDuplicate(*r,name)==0){//if the passenger is already in the list,the function returns 0 ;
        printf("Passenger already in the list!\n");
    }
    else if(*r == NULL){//statement to check if the list is empty
        *r=(struct passenger *)malloc(sizeof(struct passenger));//if the list is empty this line is for declaring a new node
        strcpy((*r)->name,name); //assigning the name information to the new node
        strcpy((*r)->departure,departure);//assigning the departure information to the new node
        strcpy((*r)->arrival,arrival);//assigning the arrival information to the new node
        strcpy((*r)->date,date);//assigning the date information to the new node
        (*r)->seat_number=seat_number;//assigning the numerical data which is named by seat_number
        (*r)->next=NULL;//finally assigning the linking pointer to NULL
    }
    else {//this statement runs when the list is not empty
        struct passenger * temp = *r;//declaring a temporary pointer
        while(temp->next != NULL){ //traversing the list, we exit the loop when the wanted node is found
            temp = temp->next;
        }
        temp->next=(struct passenger*)malloc(sizeof(struct passenger));// declaring a new node
        strcpy(temp->next->name,name); //string manipulations
        strcpy(temp->next->departure,departure);
        strcpy(temp->next->arrival,arrival);
        strcpy(temp->next->date,date);
        temp->next->seat_number = seat_number;
        temp->next->next = NULL;
    }
}
int checkDuplicate(struct passenger *r,char name[]){
    if(r == NULL){//if the list is empty it returns 1
        return 1;
    }
    else{
    while(r->next!= NULL){
        if(strcmp(r->name,name)==0){//we understand that the node is in the list
            return 0; //function found in the list
    }
        else{
            r=r->next;
    }
}
}
return 1;
}
struct passenger * deletePassenger(struct passenger **r, char name[]){
    struct passenger * temp = *r;
    struct passenger * iter = *r;
    while (strcmp(temp->name,name) != 0){//traversing until finding the target node
        temp=temp->next;
    }
    if(temp == NULL){ //we couldnt find
        printf("No such person named:%s\n",name);
        return r;
    }
    else{//we found
        while(iter->next != temp){
            iter = iter->next;
        }
    iter->next = temp->next;
    free(temp);//freeing the node from the allocated memory to optimize ram usage
    return *r;
    }
}
void searchPassenger(struct passenger **r,char name[]){
    struct passenger * temp = *r; //
    while(strcmp(temp->name,name)!=0){//searching until the target node
        temp=temp->next;
    }
    if(temp == NULL){//target can not be found
        printf("The person you searched for cannot be found.\n");
    }
    else{//target found
        printf("%s, %s, %s, %s, %d\n",temp->name,temp->departure,temp->arrival,temp->date,temp->seat_number);
    }
}
void displayPassenger(struct passenger **r){
    struct passenger* iter =*r;//temporary variable to iterate the list
    if(iter == NULL){
        printf("Passenger list is empty!\n");
    }
    else{
        while(iter!=NULL){
            printf("Name: %s\nDeparture: %s\nArrival: %s\nDate: %s\nSeat_number: %d\n",iter->name,iter->departure,iter->arrival,iter->date,iter->seat_number);
            iter=iter->next;
        }
    }
}
int main()
{
    struct passenger* head = NULL; //head pointer to point the linked-list
    return 0;
}
