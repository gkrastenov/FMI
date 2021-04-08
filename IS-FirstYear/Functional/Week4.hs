main :: IO()
main = do
    print x
    print xs
    print zs
    print [x]
    print xss
    print 12345
    print ( null [])
    print ( null xs)
    print ( head xs)
    print ( tail xs)
    print ( tail [1])
    print ( x: [])
    print (1: x: [])
    print (1 : [2,3,4])
    print ([1,2] ++ [2,3,4]) -- 0(n)
    print ([1,2,3,4] ++ [5]) 
    print(xs == [])
    print([x..10])
    print(lengthList [1,2,3,4,5,6,7,8])
    print(length [1,2,3,4,5,6,7,8]) -- length вградена функция 
    print(sumList [1,2,3])
    print(containsList [1..3] 3)
    print(containsList [1..3] 4)
    print(createPrimeList 1 10)
    print(removeFirstContainsElement [1,2,2,2,3] 2)
    print(removeContainsElement [1,2,2,2,3] 2)
    print(removeAllX [1,2,2,2,3] 2)
    print([2*x + 7 | x <- xs])
    print(incrementAllBy xs 10)
    print ([x | x <- [1..10], x `mod` 2 == 1, x > 3])


-- head връща първия елемент( главата)
-- tail връща останалите елементи след главата
-- null проверява дали е празен списъка
x :: Int
x = 2

xs :: [Int] 
xs = [1,2,3]

zs :: [Int]
zs = []

xss :: [[Int]]
xss = [[1, 2], [3,4], [], [5]]

-- Да се дефинира функция, която намира броя на елементите на списък
lengthList:: [Int] -> Int
lengthList xs
        | null xs = 0
        | otherwise = 1 + lengthList( tail xs)

lengthList2 :: [Int] -> Int
lengthList2 [] = 0
lengthList2 (_:xs) = 1 + lengthList2 xs
 
-- Да се дефинира функция, която намира сумата на елементите в списък
sumList:: [Int] -> Int
sumList xs
        | null xs = 0
        | otherwise = head xs + sumList( tail xs)

-- Да се дефинира функция, която намира дали даден елемент се съдържа в списък.
containsList:: [Int] -> Int -> Bool
containsList xs x
        | null xs = False
        | head xs == x = True
        | otherwise = containsList (tail xs) x

-- Да се дефинира функция, която генерира списък с простите числа в интервала [a,b].
createPrimeList :: Int -> Int -> [Int]
createPrimeList a b = helper a []
        where
            helper a xs
             | a == b = xs
             | isPrime a = helper (a + 1) (xs ++ [a])
             | otherwise = helper (a + 1) xs 

-- more faster then createPrimeList           
listPrimeNumbers :: Int -> Int -> [Int]
listPrimeNumbers a b = helper a b []
    where
        helper a b xs
            | a > b     = xs
            | isPrime b = helper a (b - 1) (b : xs)
            | otherwise = helper a (b - 1) xs

listPrimeNumbers' :: Int -> Int -> [Int]
listPrimeNumbers' a b = [n | n <- [a..b], isPrime' n]

isPrime' :: Int -> Bool
isPrime' n = [1, n] == [d | d <- [1..n], n `mod` d == 0]

isPrime :: Int -> Bool
isPrime 1 = False
isPrime n = helper 2
    where
        helper d
            | d == n       = True
            | mod n d == 0 = False
            | otherwise    = helper (d + 1)
-- Препознаване по образец
fact :: Int -> Int
fact 0 = 1
fact n = n * fact ( n - 1)

-- Да се дефинира функция, която премахва първия елемент, равен на x, от даден списък.
removeFirstContainsElement :: [Int] -> Int -> [Int]
removeFirstContainsElement list n = helper list [] 1
        where 
            helper list xs count
             | null list =  xs
             | head list == n && count == 1 = helper ( tail list) xs  (count - 1)
             | otherwise = helper ( tail list) ( xs ++ [head list]) count

removeFirstX :: Int -> [Int] -> [Int]
removeFirstX _ [] = []
removeFirstX x (z:zs) =
    if x == z then zs else z : removeFirstX x zs
 -- Да се дефинира функция, която премахва всички елементи на даден списък, които са равни на x. 

removeContainsElement :: [Int] -> Int -> [Int]
removeContainsElement list n = helper list [] 
        where 
            helper list xs
             | null list =  xs
             | head list == n = helper ( tail list) xs
             | otherwise = helper ( tail list) ( xs ++ [head list])    

removeAllX  :: [Int] -> Int -> [Int]
removeAllX xs x = [z | z <- xs, z /= x]

-- Да се дефинира функция incrementAllBy :: [Int] -> Int -> [Int], която получава списък и число и го добавя към всеки елемент на списъка.  
incrementAllBy :: [Int] -> Int -> [Int]
incrementAllBy xs z = [z + x | x <- xs]

f :: [Int] -> Int
f []       = 0
f [_]      = 0
f (_:x:xs) = x + f xs