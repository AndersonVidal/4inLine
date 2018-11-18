%Fatos do jogo
line(1).
line(2).
line(3).
line(4).
line(5).
line(6).

column(a).
column(b).
column(c).
column(d).
column(e).
column(f).
column(g).

board([
    [1, a, 0], [1, b, 0], [1, c, 0], [1, d, 0], [1, e, 0], [1, f, 0], [1, g, 0],
    [2, a, 0], [2, b, 0], [2, c, 0], [2, d, 0], [2, e, 0], [2, f, 0], [2, g, 0],
    [3, a, 0], [3, b, 0], [3, c, 0], [3, d, 0], [3, e, 0], [3, f, 0], [3, g, 0],
    [4, a, 0], [4, b, 0], [4, c, 0], [4, d, 0], [4, e, 0], [4, f, 0], [4, g, 0],
    [5, a, 0], [5, b, 0], [5, c, 0], [5, d, 0], [5, e, 0], [5, f, 0], [5, g, 0],
    [6, a, 0], [6, b, 0], [6, c, 0], [6, d, 0], [6, e, 0], [6, f, 0], [6, g, 0]
    ]).

player(1).
player(-1).
player(0).
player(1, 'X').
player(-1, 'O').
player(0, ' ').

roundPlayerValue(0, -1).
roundPlayerValue(1, 1).

cell([Line, Column, Value]) :- line(Line), column(Column), player(Value).


