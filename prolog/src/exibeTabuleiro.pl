exibeLinha([X|Y]) :- 
    swritef(S, '|  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |', [X|Y]),
    writeln(S).

exibeTabuleiro([]) :- .
exibeTabuleiro([X|Y]) :- 
    exibeLinha(X),
    exibeTabuleiro(Y).

%main:-
%    exibeTabuleiro([
%        [0,0,0,0,0,0,0],
%        [0,0,0,0,0,0,0],
%        [0,0,0,0,0,0,0],
%        [0,0,0,0,0,0,0],
%        [0,1,0,0,1,0,0],
%        [0,1,1,0,2,2,0]
%        ]).