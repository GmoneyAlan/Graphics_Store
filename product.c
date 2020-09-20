#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "login.h"
#include "product.h"


int productChoice; // stores what gpu you pick //
int productOption; // stores the function 
int productQuantity[] = {50, 50, 50, 50};
int productDetails[4][3] = {{1365, 6, 399},
                            {1130, 6, 289},
                            {1605, 8, 499},
                            {1350, 11, 1200}
                           };
char storeName[6][71];
void exitMenu();
//Menu to exit the program
void exitMenu(){
  int choice;

  printf("Are you sure you want to exit?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  scanf("%d", &choice);

  if(choice == 2){
    store();
    return;
  } else if(choice == 1){
    exit(0);
    setMenu(false);
  }
}

 // method that prints the first store page //
void store () {
  printf("\n----------FLeX GPU Store----------\n");
  printf("Here is a list of our current available products.\n");
  printf("1. RTX 2060\n");
  printf("2. RX 5600\n");
  printf("3. RTX 2070 Super\n");
  printf("4. RTX 2080 Ti\n");
  printf("5. Exit");
  printf("\n");
  printf("Please select an option (1-5):");
  printf("\n");
  scanf("%d", &productChoice);

  
  // how to exit the menu //
  if(productChoice == 5) {
    exitMenu();
    return;
  }
  // if an invalid input happens //
  if(productChoice > 5) {
    printf("\n");
    printf("You entered an invalid option, please select only from 1-5 .");
    printf("\n");
    store();
  }
  store2();
}

// second page of store that shows more functions //
void store2 () {
  printf("\n");
  printf("Great choice, what would you like to do now?\n");
  printf("1. Product Info\n");
  printf("2. Buy product\n");
  printf("3. Sell product\n");
  printf("4. Back\n");
  printf("Please select an option (1-4):\n");
  scanf("%d", &productOption);
  if(productOption == 4) {
     store();
  }
  productOptionsMenu();
}

// method that displays info on the selected GPU //
void productInfo(int product) {
  productChoice = product;
  product--;
  printf("\n");
  printf("Specs: Base clock of %d MHz with %dgb of GDDR6 VRAM\nPrice: $%d\n", productDetails[product][0], productDetails[product][1], productDetails[product][2]);
}

// method that implements the buy option of the menu based on the gpu //
void buyProduct(int product) {
  int choice;
  product--;
  printf("\n");
  printf("The GPU you selected comes out to a total of $%d plus a $7.99 shipping fee, would you like to continue to checkout? (1-2)\n", productDetails[product][2]);
  printf("1. Yes\n");
  printf("2: No\n");
  scanf("%d", &choice);
  if(choice == 1) {
    checkout(choice);
  }
  else {
    printf("We are now redirecting you to the store page!\n");
    store();
  }
}

// checkout method based on the gpu you selected //
void checkout() {
  char adress [20];
  char name [20];
  char name2 [20];
  printf("\n");
  printf("----------Checkout----------\n");
  printf("Please enter your first name (20 characters max, no spaces):\n");    
  scanf("%s", name);
  printf("Please enter your last name (20 characters max, no spaces):\n"); 
  scanf("%s", name2);
  printf("Please enter a valid adress to ship to (20 characters max, no spaces):\n");
  scanf("%s", adress);
  printf("\n");
  printf("Thank you %s %s! Your order is now being processed by our staff and will be shipped to %s!\n", name, name2, adress);
  printf("We will now redirect you to the store page, thank you for shopping with FLeX!\n");
  store();
}

// sell option of  the menu that "sells" your gpe //
void sell(int product) {
  int choice;
  char name [20];
  char name2 [20];
  printf("\n");
  printf("----------Sell----------\n");
  printf("Welcome to the sell section!\n");
  printf("We can offer to buy the GPU you selected for a total 10 percent off its normal price, would you like to sell?\n");
  printf("1. Yes\n");
  printf("2: No\n");
  scanf("%d", &choice);
  printf("\n");
  if(choice == 1) {
    printf("Great! We just need some info to complete this transaction.\n");
    printf("Please enter your first name (20 characters max, no spaces):\n");
    scanf("%s", name);
    printf("Please enter your last name (20 characters max, no spaces):\n");
    scanf("%s", name2);
    printf("\n");
    printf("Alrighty %s %s! Our specialists are transferring the money to you shortly.\n", name, name2);
    printf("We will now redirect you to the store page, thank you for shopping with FLeX!\n");
  }
  else if(choice == 2) {
    printf("Changed your mind?\n");
    printf("We wil now redirect you to the store page.\n");
  }
}

// switch case that actually navigates and makes sure it displays the right menus/info //
void productOptionsMenu () {
  switch (productOption) {
    case 1 : 
      if(productChoice == 1) {
        productInfo(productChoice);
        store();
      }
      if(productChoice == 2) {
        productInfo(productChoice);
        store();
      }
      if(productChoice == 3) {
        productInfo(productChoice);
        store();
      }
      if(productChoice == 4) {
        productInfo(productChoice);
        store();
      }
      break;
    case 2 :
      if(productChoice == 1) {
        buyProduct(productChoice);
        store();
      }
      if(productChoice == 2) {
        buyProduct(productChoice);
        store();
      }
      if(productChoice == 3) {
        buyProduct(productChoice);
        store();
      }
      if(productChoice == 4) {
        buyProduct(productChoice);
        store();
      }
      break;
    case 3 : 
      if(productChoice == 1) {
        sell(productChoice);
        store();
      }
      if(productChoice == 2) {
        sell(productChoice);
        store();
      }
      if(productChoice == 3) {
        sell(productChoice);
        store();
      }
      if(productChoice == 4) {
        sell(productChoice);
        store();
      }
      break;
    default :
      printf("\n");
      printf("You entered an invalid choice, please enter only 1-4 .");
      printf("\n");
      store();
      break;
  }
}

//Method to update quantity of product in this class
void setProduct(int a, int b, int c, int d) {
  productQuantity[0] = a;
  productQuantity[1] = b;
  productQuantity[2] = c;
  productQuantity[3] = d;
}

//Method to update to quantity of values in the program
void quantity(int arr[]){
  for(int i = 0; i < 4; i++)
    arr[i] = productQuantity[i];
}





