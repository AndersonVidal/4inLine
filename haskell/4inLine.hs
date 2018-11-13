printTabuleiro :: [[Char]] -> IO ()
printTabuleiro tabuleiro = do
    putStrLn([((tabuleiro !! 0) !! 0)] ++ " " ++ [((tabuleiro !! 0) !! 1)] ++ " " ++ [((tabuleiro !! 0) !! 2)] ++ " " ++ [((tabuleiro !! 0) !! 3)] ++ " " ++ [((tabuleiro !! 0) !! 4)] ++ " " ++ [((tabuleiro !! 0) !! 5)] ++ " " ++ [((tabuleiro !! 0) !! 6)])
    putStrLn([((tabuleiro !! 1) !! 0)] ++ " " ++ [((tabuleiro !! 1) !! 1)] ++ " " ++ [((tabuleiro !! 1) !! 2)] ++ " " ++ [((tabuleiro !! 1) !! 3)] ++ " " ++ [((tabuleiro !! 1) !! 4)] ++ " " ++ [((tabuleiro !! 1) !! 5)] ++ " " ++ [((tabuleiro !! 1) !! 6)])
    putStrLn([((tabuleiro !! 2) !! 0)] ++ " " ++ [((tabuleiro !! 2) !! 1)] ++ " " ++ [((tabuleiro !! 2) !! 2)] ++ " " ++ [((tabuleiro !! 2) !! 3)] ++ " " ++ [((tabuleiro !! 2) !! 4)] ++ " " ++ [((tabuleiro !! 2) !! 5)] ++ " " ++ [((tabuleiro !! 2) !! 6)])
    putStrLn([((tabuleiro !! 3) !! 0)] ++ " " ++ [((tabuleiro !! 3) !! 1)] ++ " " ++ [((tabuleiro !! 3) !! 2)] ++ " " ++ [((tabuleiro !! 3) !! 3)] ++ " " ++ [((tabuleiro !! 3) !! 4)] ++ " " ++ [((tabuleiro !! 3) !! 5)] ++ " " ++ [((tabuleiro !! 3) !! 6)])
    putStrLn([((tabuleiro !! 4) !! 0)] ++ " " ++ [((tabuleiro !! 4) !! 1)] ++ " " ++ [((tabuleiro !! 4) !! 2)] ++ " " ++ [((tabuleiro !! 4) !! 3)] ++ " " ++ [((tabuleiro !! 4) !! 4)] ++ " " ++ [((tabuleiro !! 4) !! 5)] ++ " " ++ [((tabuleiro !! 4) !! 6)])
    putStrLn([((tabuleiro !! 5) !! 0)] ++ " " ++ [((tabuleiro !! 5) !! 1)] ++ " " ++ [((tabuleiro !! 5) !! 2)] ++ " " ++ [((tabuleiro !! 5) !! 3)] ++ " " ++ [((tabuleiro !! 5) !! 4)] ++ " " ++ [((tabuleiro !! 5) !! 5)] ++ " " ++ [((tabuleiro !! 5) !! 6)])
    putStrLn("1 2 3 4 5 6 7")
    return()

marcaTabuleiro::[[Char]] -> Int -> Int -> Char -> [[Char]]
marcaTabuleiro tabuleiro c l jogador | (l > 5) = tabuleiro
                                     | ([((tabuleiro !! c) !! l)] == '*') = tabuleiro
                                     | otherwise = marcaTabuleiro tabuleiro c (l+1) jogador

main :: IO ()
main = do
    let tabuleiro = [['*','*','*','*','*','*','*'],
                     ['*','*','*','*','*','*','*'],
                     ['*','*','*','*','*','*','*'],
                     ['*','*','*','*','*','*','*'],
                     ['*','*','*','*','*','*','*'],
                     ['*','*','*','*','*','*','*'],
                     ['*','*','*','*','*','*','*']]

    printTabuleiro tabuleiro

    coluna <- readLn :: IO Int

    tabuleiro <- marcaTabuleiro tabuleiro coluna 0 'A'

    printTabuleiro tabuleiro
