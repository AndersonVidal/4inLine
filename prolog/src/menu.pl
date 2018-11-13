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

    % main :-
    %     open('myFile.txt', read, Str),
    %     read_file(Str,Lines),
    %     close(Str),
    %     write(Lines), nl.
    
    % read_file(Stream,[]) :-
    %     at_end_of_stream(Stream).
    
    % read_file(Stream,[X|L]) :-
    %     \+ at_end_of_stream(Stream),
    %     read(Stream,X),
    %     read_file(Stream,L).