
menu entrada | (entrada == 'B') = do
                    x <- readFile "../files/About.txt"
                    putStrLn x
             | (entrada == 'R') = do
                x <- readFile "../files/Rules.txt"
                putStrLn x
             | (entrada == 'A') = do 
                x <- readFile "../files/Apresentaion.txt"
                putStrLn x
             | (entrada == 'E') = do 
                x <- readFile "../files/Goodbye.txt"
                putStrLn x
             | (entrada == 'M') = do 
                x <- readFile "../files/Menu.txt"
                putStrLn x
             | otherwise = do
                putStrLn "Opção invalida!!!"

compute_entrada entrada | (entrada == '1') = do 
                            menu 'B'
                        | (entrada == '2') = do 
                            menu 'R'
                        | (entrada == '3') = do 
                            menu 'E'
                        | otherwise = do 
                            menu '0'

main :: IO()
main = do
    entrada <- getChar
    compute_entrada entrada