main :: IO()
main = do
    print(safePrimesCount 20 100) -- 4
    print(safePrimesCount 1 983) -- 25
    print(safePrimesCount 167 1892) -- 28
    print(safePrimesCount 1678 20097) -- 155

safePrimesCount :: Int -> Int -> Int
safePrimesCount a b = helper a b 0
 where 
     helper :: Int -> Int -> Int -> Int
     helper a b result  
      | a > b = result
      | otherwise = if isPrime(a) && safePrime(a) then helper (a + 1) b (result + 1) else helper (a + 1) b result


safePrime :: Int -> Bool
safePrime 1 = False
safePrime 2 = False
safePrime p = isPrime ( div (p-1) 2)

isPrime :: Int -> Bool
isPrime 1 = False
isPrime n 
 | n < 1  = error "error"
 | otherwise =  helper 2
  where
      helper d
       | d == n       = True
       | mod n d == 0 = False
       | otherwise    = helper (d + 1)

            