:- use_module(library(dialect/sicstus), [if/3]).
?- consult('init.pl').
?- use_module(library(lists)).


%

%Avalia uma jogada possivel
possible([X], Column, L) :-
    X = [L, C, P],
    C == Column,
    player(P, ' ').

possible([X|Y], Column, L) :-
    X = [L, C, P],
    C == Column,
    player(P, ' '),
    if(possible(Y, Column, L), P = 0, P = 1).
    
    
    

