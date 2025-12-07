main :: IO()
main = readFile "input.txt" >>= putStrLn . show . getpassword 50 0 . lines


getpassword :: Int -> Int -> [String] -> Int
getpassword _ c [] = c
getpassword n c (('L':ss):xs) = getpassword ((n - r) `mod` 100) (c + extrasmod + extrasdiv) xs
  where extrasdiv = q 
        extrasmod | r == 0 = 0
                  | n == 0 = 0
                  | n - r <= 0 = 1
                  | otherwise = 0
        q = rotation `div` 100
        r = rotation `mod` 100
        rotation = read ss
getpassword n c (('R':ss):xs) = getpassword ((n + r) `mod` 100) (c + extrasmod + extrasdiv) xs
  where extrasdiv = q
        extrasmod | r == 0 = 0
                  | n == 0 = 0
                  | n + r >= 100 = 1
                  | otherwise    = 0
        q = rotation `div` 100
        r = rotation `mod` 100
        rotation = read ss 
getpassword _ c _ = c
