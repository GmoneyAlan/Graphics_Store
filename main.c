//Contributions of each team member
//Alan Garcia: login.h, login.c, and half of main.c
//Brian Novoa: product.c, product.h, and part of main.c

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "login.h"
#include "product.h"

//conditions for menu to run repeatedly
int main(void){
  while(getMenu()){
    if(!userExist())
      userCreate();
    else 
    if(signIn() == -1)
      continue;
    while(getAccMenu()){
      accountOptions();
    }
    if(userExist())
      store(getMenu());
  }
  return 0;
}

