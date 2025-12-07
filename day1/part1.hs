main :: IO()
main = readFile "input.txt" >>= putStrLn . show . getpassword 50 0 . lines

getpassword :: Int -> Int -> [String] -> Int
getpassword _ c [] = c
getpassword n c (('L':ss):xs)  
 | n == 0                     = getpassword ((n - read ss) `mod` 100) (c + 1) xs
 | otherwise                  = getpassword ((n - read ss) `mod` 100) c xs
getpassword n c (('R':ss):xs)  
 | n == 0                     = getpassword ((n + read ss) `mod` 100) (c + 1) xs
 | otherwise                  = getpassword ((n + read ss) `mod` 100) c xs
getpassword _ c _ = c
