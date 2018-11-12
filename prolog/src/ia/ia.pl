:- use_module(library(lists)).

% Conta a quantidade de ocorrências do elemento X na lista
count([], X, 0).
count([X|T], X, Y):- count(T, X, Z), Y is 1 + Z.
count([X1|T], X, Z):- X1 \= X, count(T, X, Z).

%countall(List, X, C) :-
%    sort(List, List1),
%    member(X, List1),
%    count(List, X, C).

% Busca o elemento na lista e retorna a posicao dele
indexOf([Element|_], Element, 0):- !.
indexOf([_|Tail], Element, Index):-
  indexOf(Tail, Element, Index1),
  !,
  Index is Index1+1.

% Caso para: 1 casa vazia e 3 casas do player
case(1, 3, List, Index) :- 
    indexOf(List, 0, Index).

main:-
    count([1,1,0,1,2,2,2], 0, Count1),
    count([1,1,0,1,2,2,2], 1, Count2),
    writeln(Count1),
    writeln(Count2),
    case(Count1, Count2, [1,1,0,1,2,2,2], Index),
    writeln(Index).
