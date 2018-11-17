:- initialization(main).

apresentation(0).
game(1).
rules(2).
about(3).
goodBye(4).
menu(5).

callOption(Opt):- apresentation(Opt), ler_txt("../files/Apresentation.txt");
                  game(Opt), print("************Joguinho************");
                  menu(Opt), ler_txt("../files/Menu.txt");
                  rules(Opt), ler_txt("../files/Rules.txt");
                  about(Opt), ler_txt("../files/About.txt");
                  goodBye(Opt), ler_txt("../files/Goodbye.txt"),halt(0);
                  writeln("Opção invalida!").

ler_txt(Filename) :-  open(Filename,read,OS), 
                      get_char(OS,C), 
                      txt_to_list(C,L,OS), 
                      close(OS),
                      escreve(L).

txt_to_list(_,[],OS)  :-  at_end_of_stream(OS).
txt_to_list(C,[C|L],OS) :- get_char(OS,Q), txt_to_list(Q,L,OS).

escreve([]).
escreve([X|L1]):- write(X), escreve(L1).

readNumber(Number):- read_line_to_codes(user_input, Codes),
                     string_to_atom(Codes, Atom),
                     atom_number(Atom, Number).

callFluxoJogo():- callOption(5),
                  readNumber(Opt),
                  callOption(Opt),
                  callFluxoJogo().

main :- callOption(0),
        callFluxoJogo().