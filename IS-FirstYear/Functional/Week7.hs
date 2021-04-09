main :: IO()
main = do
    print (primesInRange 10 50)
    print (primesInRange' 10 50)
    print ( prodSumDivHelper 410 5)
    print (isSorted [1,2,3])
    print (isSorted [1,4,3])
    print (1 : [2,3,4])




--  Да се дефинира функция primesInRange :: Integer -> Integer -> [Integer], която конструира списък от простите числа в интервала [a,b].
isPrime :: Integer -> Bool
isPrime 1 = False
isPrime n = helper 2
    where
        helper d
            | d == n       = True
            | mod n d == 0 = False
            | otherwise    = helper (d + 1)
isPrime' :: Int -> Bool
isPrime' n = [1, n] == [d | d <- [1..n], n `mod` d == 0]

primesInRange :: Integer -> Integer -> [Integer]
primesInRange a b = helper a b []
           where
               helper a b xs
                | a > b = xs
                | isPrime a = helper (a +1) b (xs++[a])
                | otherwise = helper (a +1) b xs

primesInRange' :: Integer -> Integer -> [Integer]
primesInRange' a b = [x | x <- [a..b], isPrime x]  

-- Да се дефинира функция prodSumDiv :: [Integer] -> Integer -> Integer, която намира произведението на естествените числа в даден списък, сумата от делителите на които е кратна на k.
--prodSumDiv :: [Integer] -> Integer -> Integer
--prodSumDiv xs k = helper xs 1
--         where 
--             helper rs result
--              | null rs = result
--              | prodSumDivHelper (head rs) k = helper (tail rs)  result
--              | otherwise = helper (tail rs) result 

prodSumDivHelper :: Integer -> Integer -> Bool     
prodSumDivHelper num k = helper num 0 
          where 
              helper num sum
               | num == 0 = if (mod sum k) == 0 then True else False
               | otherwise = helper (div num 10) (sum + (mod num 10))
-- Да се дефинира функция isSorted :: [Int] -> Bool, която проверява дали списък е сортиран във възходящ ред.
-- isSorted :: [Int] -> Bool isSorted xs = xs == (sort xs)

isSorted :: [Int] -> Bool 
isSorted [] = True
isSorted (x:xs) = True 
isSorted (x:y:xs) = x < y && isSorted (y:xs)

isSorted' :: [Int] -> Bool
isSorted' xs 
     | length xs == 1 = True
     | otherwise = if (head xs) < head ( tail xs) then isSorted (tail xs) else False
-- Да се дефинира функция insert :: Int -> [Int] -> [Int], която добавя елемент в сортиран списък, като резултатният списък също е сортиран.               
insert :: Int -> [Int] -> [Int] 
insert x [] = [x] 
insert x (y:xs) 
 | x < y = (x:y:xs) 
 | otherwise = y : insert x xs