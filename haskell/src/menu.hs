import System.IO  
import Control.Monad


menu entrada | (entrada == 'B') = do
                let x = readFile "../files/About.txt"
                let t = show x
                return(t)
             | (entrada == 'R') = do
                let x = readFile "../files/Rules.txt"
                let t = show x
                return(t)
             | (entrada == 'A') = do 
                let x = readFile "../files/Apresentation.txt"
                let t = show x
                return(t)
             | (entrada == 'E') = do 
                let x = readFile "../files/Goodby.txt"
                let t = show x
                return(t)
             | (entrada == 'M') = do 
                let x = readFile "../files/Menu.txt"
                let t = show x
                return(t)
             | otherwise = do
                let t = "Opção invalida!!!"
                return(t)

compute_entrada entrada | (entrada == '1') = menu 'B'
                        | (entrada == '2') = menu 'R'
                        | (entrada == '3') = menu 'A'
                        | (entrada == '4') = menu 'E'
                        | otherwise = menu '0'

main :: IO()
main = do
    entrada <- getChar
    putStrLn (compute_entrada entrada)