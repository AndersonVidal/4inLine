import Control.Monad  
import Data.Char  

menu :: Char -> [Char]
menu entrada | (entrada == 'B') = "Aqui está o about.txt"
             | (entrada == 'R') = "Aqui está a rules.txt"
             | (entrada == 'A') = "Aqui está a apresentation.txt"
             | (entrada == 'E') = "Aqui está o goodby.txt"
             | otherwise = "Entrada inválida!!"

compute_entrada :: Char -> [Char]
compute_entrada entrada | (entrada == '1') = menu 'B'
                        | (entrada == '2') = menu 'R'
                        | (entrada == '3') = menu 'A'
                        | (entrada == '4') = menu 'E'
                        | otherwise = menu '0'

imprime_menu :: [Char]
imprime_menu = do


main :: IO()
main = do
    entrada <- getChar
    putStrLn (compute_entrada entrada)