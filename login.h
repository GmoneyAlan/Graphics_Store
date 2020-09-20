#ifndef LOGIN_H_
#define LOGIN_H_

void welcomeMessage();
void userCreate();
bool userExist();
int signIn();
const char *getUserName();
const char *getPassword();
bool getMenu();
bool setMenu(bool menu);
void changeName();
void accountOptions();
void changePassword();
bool getAccMenu();
void setAccMenu(bool menu);
bool secQuestions();

#endif