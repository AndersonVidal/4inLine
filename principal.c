#include <stdio.h>
#include "menu.h"
#include "register.h"
#include "rules.h"
#include "about.h"

int main() {
  printf("4inLine\n");

  printf("Welcome\n");
  
  showMenu();

  char userChoice;
  while (userChoice != 'E') {  
    scanf("%c", &userChoice); 
    if (userChoice == 'N') {
      newGame();
    }
    else if (userChoice == 'R') {
      showRules();
    }
    else if (userChoice == 'A') {
      showAboutPanel();
    }
    else if (userChoice == 'E') {
      return 0;
    }
  }
  return 0;
}
