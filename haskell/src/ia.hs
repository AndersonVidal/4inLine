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

transpostaMtx :: [[Int]] -> [[Int]]
transpostaMtx ([]:_) = []
transpostaMtx m = (map head m) : transpostaMtx (map tail m)

implBuscaVertical :: [[Int]] -> Int -> Int -> Int
implBuscaVertical [] player qtd = -1
implBuscaVertical matriz player qtd
  | percorre (head matriz) player qtd [0..(5-qtd)] /= -1 = 7 - (length matriz)
  | otherwise = implBuscaVertical (tail matriz) player qtd

buscaVertical :: [[Int]] -> Int -> Int -> Int
buscaVertical matriz player qtd = implBuscaVertical (transpostaMtx matriz) player qtd

buscaHorizontal :: [[Int]] -> Int -> Int -> Int
buscaHorizontal [] player qtd = -1
buscaHorizontal matriz player qtd
  | percorre (head matriz) player qtd [0..(6-qtd)] == -1 = buscaHorizontal (tail matriz) player qtd
  | otherwise = percorre (head matriz) player qtd [0..(6-qtd)]

escolheJogada :: [[Int]] -> Int -> Int -> Int
escolheJogada matriz player qtd
  | buscaHorizontal matriz player qtd /= -1 = buscaHorizontal matriz player qtd
  | buscaVertical matriz player qtd /= -1 = buscaVertical matriz player qtd
  | otherwise = -1

getJogada :: [[Int]] -> Int
getJogada matriz
  | escolheJogada matriz 2 3 /= -1 = escolheJogada matriz 2 3
  | escolheJogada matriz 1 3 /= -1 = escolheJogada matriz 1 3
  | escolheJogada matriz 1 2 /= -1 = escolheJogada matriz 1 2
  | escolheJogada matriz 2 2 /= -1 = escolheJogada matriz 2 2
  | escolheJogada matriz 2 1 /= -1 = escolheJogada matriz 2 1
  | otherwise = 3

