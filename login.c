#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

char setName[10], inputName[10];
char setPassword[10], inputPass[10];
char secAns[50], secAns2[50], secAns3[50];
char sec1[50] = "What is your favorite color?";
char sec2[50] = "Who is your heroe?";
char sec3[50] = "What elementary school did you attend?";
bool userMade = false;
bool Menu = true;
bool accMenu = true;

//welcome sign up
void welcomeMessage(){
  printf("Welcome to the FLeX GPU store!\n");
  printf("Before you can access the store, please sign up by creating \na username and password.\n");
}

//Create user and store hes/hers info in the program
void userCreate(){

  welcomeMessage();
  printf("----------Account Creation----------\n");
  printf("Let's create your account!\n");
  printf("Please enter a username (10 characters max, no spaces):\n");
  scanf("%s", setName);
  printf("Please create a password (10 characters max, no spaces):\n");
  scanf("%s", setPassword);

  printf("Now to ensure security of your Account we will set\n");
  printf("3 security questions.\n");
  printf("%s\n", sec1);
  scanf("%s", secAns);
  printf("%s\n", sec2);
  scanf("%s", secAns2);
  printf("%s(no spaces)\n", sec3);
  scanf("%s", secAns3);

  printf("\nThank you! You will now be directed to the store.\n");
  printf("\n");
  userMade = true;
}

//Check if the user already exists in the network
bool userExist(){
  return userMade;
}

//The following methods are mainly used as testing
//getter method to return userName
const char *getUserName(){
  return setName;
}

//getter method to return password
const char *getPassword(){
  return setPassword;
}
//--------------------------------------------------------------------------

//The following methods are for the menu in main
//Conditions to exit the loop and sign out
bool getMenu(){
  return Menu;
}

void setMenu(bool menu){
  Menu = menu;
}

//Account settings menu setters and getters
bool getAccMenu(){
  return accMenu;
}

void setAccMenu(bool menu) {
  accMenu = menu;
}

//---------------------------------------------------------------

/*Method for the user to sign in, where the user has 3 tries total if they go over 3 tries the method wil return -1. Which will mean the user failed to sign in */ 
int signIn(){
  int count = 0;
  printf("You have 3 tries to sign in\n");
  printf("if you go over 3 program will restart\n");
  printf("Enter usernamme: \n");
  scanf("%s", inputName);
  while(strcmp(setName, inputName) != 0){
      count++;
      if(count == 3){
        setMenu(false);
        return -1;
      }
    scanf("%s", inputName);
  }
  printf("\n");
  printf("Enter password: \n");
  scanf("%s", inputPass);
  while(strcmp(setPassword, inputPass) != 0){   
      count++;
      if(count == 3){
        setMenu(false);
        return -1;
      }   
    scanf("%s", inputPass);
  }
  return 0;
}

/*Method for the user to change their username in the program where it will ask the user for their password at first with a total of 3 tries. If they go over 3 tries they are not allowed to change the username and returns to the menu.*/
void changeName(){
  char newName[10];
  int count = 0;
  printf("For you to be able to change your username you must\n");
  printf("enter your password with 3 tries.\n");
  while(count < 3 ){
    printf("Enter your password\n");
    scanf("%s", inputPass);
    if(strcmp(setPassword, inputPass) == 0){
      break;
    }
    count++;
  }
  if(count == 2){
    printf("Returning to the account options...\n");
    return;
  }
  printf("Enter a new username \n");
  printf("10 characters long & no spaces.\n");
  scanf("%s", newName);
  strcpy(setName, newName);

  printf("Your new username is: %s\n\n", setName);
}

//Method declaration earlier, so the method changePassword can use it
bool SecQuestions();

/* Method for the user to change password, where before they are allowed to do so they must answer their security questions, where there is a total of 3 tries will all three questions*/
void changePassword(){
  char newPass[10];
  if(!SecQuestions())
    return;

  printf("Enter a new password \n");
  printf("10 character long & no spaces. \n");
  scanf("%s", newPass);
  strcpy(setPassword, newPass);
 
  printf("Your new password is: %s\n\n", setPassword);
}

/* Method to delete the users account, where it will ask the user for their password(total of 3 tries), then proceeds to the user create menu*/
void deleteAccount(){
  int choice, count = 0;
  printf("For you to be able to delete your account you must\n");
  printf("enter your password within 3 tries.\n");
  while(count < 3 ){
    printf("Enter your password\n");
    scanf("%s", inputPass);
    if(strcmp(setPassword, inputPass) == 0){
      break;
    }
    count++;
  }
  if(count == 3)
    return;

  printf("Are you sure you want to delete your account?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  scanf("%d", &choice);
  if(choice == 2)
    return;
  printf("Okay...\n");
  userMade = false;
  for(int i = 0; i < strlen(setName);i++){
    setName[i] = '\0';
  }
  for(int i = 0; i < strlen(setPassword);i++){
    setPassword[i] = '\0';
  }
  for(int i = 0; i < strlen(secAns);i++){
    secAns[i] = '\0';
  }
  for(int i = 0; i < strlen(secAns2);i++){
    secAns2[i] = '\0';
  }
  for(int i = 0; i < strlen(secAns3);i++){
    secAns3[i] = '\0';
  }
  printf("Account deleted.\n");
}

/*Method that asks the user security questions with 3 total tries, if the user makes 3 or more mistakes it will return false otherise true*/
bool SecQuestions(){
  int count = 0;
  char secInput1[50], secInput2[50], secInput3[50];
  printf("To proceed answer the following Sec Questions\n(There is only 3 tries total)\n");
  printf("%s\n", sec1);
  scanf("%s", secInput1);
  while(strcmp(secInput1, secAns) != 0){
      count++;
      if(count == 3){
        printf("Incorrect, returning to settings...\n");
        return false;
      }  
      printf("Please try again.\n");
      scanf("%s", secInput1);
  }

  printf("%s\n", sec2);
  scanf("%s", secInput2);
  while(strcmp(secInput2, secAns2) != 0){
    count++;
    if(count == 3){
      printf("Incorrect, returning to settings...\n");
      return false;
    }  
    printf("Please try again.\n");
    scanf("%s", secInput2);
  }

  printf("%s\n", sec3);
  scanf("%s", secInput3);
  while(strcmp(secInput3, secAns3) != 0){
    count++;
    if(count == 3){
      printf("Incorrect, returning to settings...\n");
      return false;
    }  
    printf("Please try again.\n");
    scanf("%s", secInput3);
  }
  return true;
}

/*Main menu where it directs you to the store, account settings or even exit the program,
  account setting include the following options:
    1. Change username
    2. Change password
    3. Delete account
    4. Exit the account settings*/
void accountOptions(){
  int choice;
  if(userExist() == false)
    userCreate();

  printf("Welcome %s\n", setName);
  printf("1. To go to account settings\n");
  printf("2. To continue to the store\n");
  printf("3. Exit the program\n");
  scanf("%d", &choice);

  if(choice == 2){
    store(getMenu());
    return;
  }
  else if(choice == 3)\
    exit(0);  

  printf("\n-----------Account Settings-----------\n");

  printf("1. Change username\n");
  printf("2. Change password\n");
  printf("3. Delete Account\n");
  printf("4. Exit Account Settings\n");
  scanf("%d", &choice);

  switch(choice){
    case 1:
      changeName();
      break;
     case 2:
      changePassword();
      break;
     case 3:
      deleteAccount();
      break;
     case 4:
      setAccMenu(false);
      break;
     default:
      printf("Invalid option\n");  
  }
}