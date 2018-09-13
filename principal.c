// C STANDARD LIBRARIES
#include <stdio.h>
#include <ctype.h>

// PROJECT LIBRARIES
#include "menu.h"
#include "createGame.h"
#include "rules.h"
#include "about.h"

// FUNCTION DECLARATIONS
void manageMenu();

// COLORS DEFINITIONS
#define NOR  "\x1B[0m"
#define RED  "\x1B[31m"
//#define GRE  "\x1B[32m"
//#define YEL  "\x1B[33m"
//#define BLU  "\x1B[34m"
//#define MAG  "\x1B[35m"
#define CYA  "\x1B[36m"
#define WHI  "\x1B[37m"

int main() {

  printf(CYA "***************************\n");
  printf(RED "        4 In A Line        \n");
  printf(CYA "***************************\n" NOR);

  printf(WHI "          Welcome!         \n\n" NOR);
  
  manageMenu();

  return 0;
}

// FUNCTION DEFINITIONS
void manageMenu() {
  showMenu();

  char userChoice = ' ';
  while (userChoice != getExitOption()) {  
    scanf("%c", &userChoice); 
    userChoice = toupper(userChoice);

    if (userChoice == getCreateGameOption()) {
      createGame();
    }
    else if (userChoice == getRulesOption()) {
      showRules();
    }
    else if (userChoice == getAboutOption()) {
      showAboutMsg();
    }
  }
}