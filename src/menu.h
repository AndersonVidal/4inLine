
int exibirMenu() {
  printf("+---------------------------------------------------------------+\n"); 
  printf("| 1 - Iniciar jogo                                              |\n");
  printf("| 2 - Regras e dicas                                            |\n");
  printf("| 3 - Sobre                                                     |\n");
  printf("| 4 - Sair                                                      |\n");
  printf("| Qual a sua opção?                                             |\n");

  int opcao = -1;
  scanf("%d", &opcao);
  printf("+---------------------------------------------------------------+\n");
  return opcao;
}