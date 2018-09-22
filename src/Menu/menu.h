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
/*
Recebe um char que representa um arquivo .txt localizado no endereco
./src/TextArchives. O caminho e a correspondencia de char para endereco
de leitura do arquivo esta predefino em implementacao. Para adicionar
novos arquivos sera necessario criar uma nova correspondencia em codigo.
As correspondecias existentes sao:
    char    caminho_do_arquivo
    'B'     "./src/TextArchives/About.txt"
    'R'     "./src/TextArchives/Rules.txt"
    'A'     "./src/TextArchives/Apresentation.txt"
    'E'     "./src/TextArchives/Goodbye.txt"
*/
void showArchive(char type);