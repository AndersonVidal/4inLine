/*
Exibe o menu do sistema
*/
void showMenu();
/*
Recebe um char e o classifica, gerando um status correspondente:
    Status  Comando
        1       1
        2       2
        3       3
        0       4
        -1     any
*/
int computeMenuLine(char *line);
/*
Recebe o valor de status e designa a execução da funcionalidade
correspondete:
    Status  Execucao
        1       Chamada para startGameRotine()
        2       Chamada para showRules()
        3       Chamada para showAbout()
        0       Finaliza o sistema
        -1      Chamada para commandExceptionResponse()
*/
void executeStatusOperation(int status);

void showArchive(char type);