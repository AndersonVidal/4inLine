:- initialization(main).

callFile(Opt):- Opt == 0 -> writeln("+---------------------------+
|                           |
|   [1] INICIAR JOGO        |
|   [2] REGRAS E DICAS      |
|   [3] SOBRE               |
|   [4] SAIR                |
|                           |
+---------------------------+").


main:- callFile(0),
       halt(0).
