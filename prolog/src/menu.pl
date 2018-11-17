:- initialization(main).

menu(0).
about(1).
apresentation(2).
rules(3).
goodBye(4).

callFile(Opt):- menu(Opt), ler_txt("../files/Menu.txt");
                about(Opt), ler_txt("../files/About.txt");
                apresentation(Opt), ler_txt("../files/Apresentation.txt");
                rules(Opt), ler_txt("../files/Rules.txt");
                goodBye(Opt), ler_txt("../files/Goodbye.txt").

ler_txt(Filename) :-  open(Filename,read,OS), 
                      get_char(OS,C), 
                      txt_to_list(C,L,OS), 
                      close(OS),
                      escreve(L).

txt_to_list(_,[],OS)  :-  at_end_of_stream(OS).
txt_to_list(C,[C|L],OS) :- get_char(OS,Q), txt_to_list(Q,L,OS).

escreve([]).
escreve([X|L1]):- write(X), escreve(L1).

main :- callFile(0),
        halt(0).