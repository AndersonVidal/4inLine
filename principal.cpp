using namespace std;

// C++ STANDARD LIBRARIES
#include <iostream>

// PROJECT LIBRARIES
#include "menu.h"

// COLORS DEFINITIONS
#define RED "\x1B[31m"
#define CYA "\x1B[36m"
#define WHI "\x1B[37m"

// OPTIONS DEFINITIONS
#define INICIAR 'I'
#define REGRAS 'R'
#define SOBRE 'S'
#define ENCERRAR 'E'

// FUNCTION DECLARATIONS
void manageMenu();

int main() {

  cout << CYA "***************************\n";
  cout << RED "        4 In A Line        \n";
  cout << CYA "***************************\n";
  cout << WHI "          Welcome!         \n\n";
  
  manageMenu();

  return 0;
}

// FUNCTION DEFINITIONS
void manageMenu() {
	while (true) { 
		char userChoice = showMenu();
		switch (userChoice) {
			case INICIAR:
				//startGame();
				break;

			case REGRAS:
				//showRules();
				break;

			case SOBRE:
				//showAbout();
				break;

			case ENCERRAR:
				return;

			default:
				cout << "Opção inválida\n\n";
    }
  }
  
}
