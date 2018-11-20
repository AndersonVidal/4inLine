% Conta a quantidade de ocorrências do elemento X na lista
count([], _, 0).
count([X|T], X, Y):- count(T, X, Z), Y is 1 + Z.
count([X1|T], X, Z):- X1 \= X, count(T, X, Z).

% Fatia a lista
slice([X|_],1,1,[X]).
slice([X|Xs],1,K,[X|Ys]) :- K > 1, 
   K1 is K - 1, slice(Xs,1,K1,Ys).
slice([_|Xs],I,K,Ys) :- I > 1, 
   I1 is I - 1, K1 is K - 1, slice(Xs,I1,K1,Ys).

checaHorizontal([L|Ls], Player, Count) :- Count is -1.
checaHorizontal([L|Ls], Player, Count) :-
    slice([L|Ls], 1, 4, Cutedlist),
    count(Cutedlist, Player, Count2),
    writeln(Count2),
    Count2 =:= 4,
    Count is Count2;
    checaHorizontal(Ls, Player, Count).

buscaHorizontal([], Player, Ganhou) :- Ganhou = false.
buscaHorizontal([T|Ts], Player, Ganhou) :-
    Qtd2 is 6-Qtd,
    checaHorizontal(T, Player, Qtd, Qtd2, Indexp),
    Indexp \= -1,
    Index is Indexp;
    buscaHorizontal(Ts, Player, Qtd, Index).