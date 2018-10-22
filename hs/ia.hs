indexOf :: [Int] -> Int -> Int
indexOf [] elemento = -1
indexOf (x:xs) elemento
  | x == elemento = length xs
  | otherwise = indexOf xs elemento

verificador :: [Int] -> Int -> Int -> Int
verificador lista player qtd
  | length (filter (==player) lista) == qtd = qtd - (indexOf lista 0)
  | otherwise = -1 

slice :: [Int] -> Int -> Int -> [Int]
slice xs from to = take (to - from + 1) (drop from xs)  

percorre :: [Int] -> Int -> Int -> [Int] -> Int
percorre lista player qtd [] = -1
percorre lista player qtd (x:xs)
  | verificador (slice lista x (x+qtd)) player qtd == -1 = percorre lista player qtd xs
  | otherwise = (verificador (slice lista x (x+qtd)) player qtd) + x

buscaHorizontal :: [[Int]] -> Int -> Int -> Int
buscaHorizontal [] player qtd = -1
buscaHorizontal matriz player qtd
  | percorre (head matriz) player qtd [0..(7-qtd)] == -1 = buscaHorizontal (tail matriz) player qtd
  | otherwise = percorre (head matriz) player qtd [0..(6-qtd)]


main :: IO ()
main =  do
  let tabuleiro = [[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[1,1,1,1,1,1,1]]
  let player = 1
  let qtd = 3
  
  print(buscaHorizontal tabuleiro player qtd)

