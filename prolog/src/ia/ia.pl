:- use_module(library(lists)).

% Conta a quantidade de ocorrências do elemento X na lista
count([], X, 0).
count([X|T], X, Y):- count(T, X, Z), Y is 1 + Z.
count([X1|T], X, Z):- X1 \= X, count(T, X, Z).

% Busca o elemento na lista e retorna a posicao dele
indexOf([Element|_], Element, 0):- !.
indexOf([_|Tail], Element, Index):-
  indexOf(Tail, Element, Index1),
  !,
  Index is Index1+1.

% Fatia a lista
slice([X|_],1,1,[X]).
slice([X|Xs],1,K,[X|Ys]) :- K > 1, 
   K1 is K - 1, slice(Xs,1,K1,Ys).
slice([_|Xs],I,K,Ys) :- I > 1, 
   I1 is I - 1, K1 is K - 1, slice(Xs,I1,K1,Ys).

% Retorna a matriz transposta
transpose([], []).
transpose([F|Fs], Ts) :-
    transpose(F, [F|Fs], Ts).

transpose([], _, []).
transpose([_|Rs], Ms, [Ts|Tss]) :-
        lists_firsts_rests(Ms, Ts, Ms1),
        transpose(Rs, Ms1, Tss).

lists_firsts_rests([], [], []).
lists_firsts_rests([[F|Os]|Rest], [F|Fs], [Os|Oss]) :-
        lists_firsts_rests(Rest, Fs, Oss).


% Retorna a quantidade de elementos na lista
len([], LenResult):-
    LenResult is 0.
len([X|Y], LenResult):-
    len(Y, L),
    LenResult is L + 1.

% Verifica se há possibilidade de jogada na lista e retorna o index
 verifica(Lista, Player, Qtd, Index) :-
    count(Lista, Player, ReturnQtd),
    ReturnQtd =:= Qtd,
    indexOf(Lista, 0, Indexf),
    Index is Indexf;
    Index is -1.

% percorre a linha e faz o slice, passando para o verificador
percorre(Lista, Player, Qtd, -1, Index) :- Index is -1.
percorre([L|Ls], Player, Qtd, Count, Index) :-
    slice([L|Ls], 1, Qtd+1, Cutedlist),
    verifica(Cutedlist, Player, Qtd, Indexv),
    Indexv \= -1,
    Index is 6 - Qtd - Count + Indexv;
    Count1 is Count - 1,
    percorre(Ls, Player, Qtd, Count1, Index).

implBuscaVertical([], Player, Qtd, Index) :- Index is -1.
implBuscaVertical([T|Ts], Player, Qtd, Index) :-
    Qtd2 is 6-Qtd,
    percorre(T, Player, Qtd, Qtd2, Indexp),
    Indexp \= -1,
    len([T|Ts], Len),
    Index is 7 - Len;
    implBuscaVertical(Ts, Player, Qtd, Index).

buscaVertical(Tabuleiro, Player, Qtd, Index) :-
    transpose(Tabuleiro, Matrix),
    writeln(Matrix),
    implBuscaVertical(Matrix, Player, Qtd, Indexb),
    Index is Indexb.

% Percorre o tabuleiro linha por linha e passa a linha para o percorre
buscaHorizontal([], Player, Qtd, Index) :- Index is -1.
buscaHorizontal([T|Ts], Player, Qtd, Index) :-
    Qtd2 is 6-Qtd,
    percorre(T, Player, Qtd, Qtd2, Indexp),
    Indexp \= -1,
    Index is Indexp;
    buscaHorizontal(Ts, Player, Qtd, Index).
    
escolheJogada([T|Ts], Player, Qtd, Index) :-
    buscaHorizontal([T|Ts], Player, Qtd, Indexr),
    Indexr \= -1,
    Index is Indexr;
    buscaVertical([T|Ts], Player, Qtd, Indexr),
    Index is Indexr.

getJogada(Tabuleiro, Posicao):-
    escolheJogada(Tabuleiro, 2, 3, Index),
    Index \= -1,
    Posicao is Index;
    escolheJogada(Tabuleiro, 1, 3, Index),
    Index \= -1,
    Posicao is Index;
    escolheJogada(Tabuleiro, 1, 2, Index),
    Index \= -1,
    Posicao is Index;
    escolheJogada(Tabuleiro, 2, 2, Index),
    Index \= -1,
    Posicao is Index;
    escolheJogada(Tabuleiro, 2, 1, Index),
    Index \= -1,
    Posicao is Index;
    Posicao is -1.

%main:-
%    getJogada([
%    [0,0,0,0,0,0,0],
%    [0,0,0,0,0,0,0],
%    [0,0,0,0,0,0,0],
%    [0,0,0,0,0,0,0],
%    [0,1,0,0,1,0,0],
%    [0,1,1,0,2,2,0]
%    ], Index),
%    writeln(Index).
