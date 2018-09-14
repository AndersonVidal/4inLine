// C STANDARD LIBRARIES
#include <iostream>

// COLORS DEFINITIONS
#define YEL "\x1B[33m"
#define WHI "\x1B[37m"

char showMenu() {
  cout << YEL "I - Iniciar jogo\n";
  cout << "R - Regras e dicas\n";
  cout << "S - Sobre\n";
  cout << "E - Encerrar\n\n";
  cout << "Escolha uma opção: " WHI;

  char userChoice;
  cin >> userChoice; 
  return toupper(userChoice);
}
