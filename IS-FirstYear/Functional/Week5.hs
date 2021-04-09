import Data.Char
import Data.List

main :: IO()
main = do
    print (multiplyAllBy [1..10] 2)
    print (filterSmallerThan [1..10] 5)
    print ( isAscending 123)
    print ( isAscending 943)
    print (['a','b','c'])
    print (ord 'a')
    print (chr 49)
    print 49
    print (show 49)
    print (numToList 12345)
    print (v1)
    print (v2)
    print (v1, v2)
    print (fst v2)
    print (snd v2)
    print(snd3 v1)
    print(snd3' v3)
    print(snd3' v1)
    print(countMembers "admasdasdwa")
    print(sumMembers [1,2,3])
    print(sumMembers [1.2,2.3,3.9])
    print(sort [1,4,2,6,3])
    print(sort [(11,2),(1,2),(3,4),(5,6),(3,3)])
    print (zip' [1..10] [2, 4, 6, 1, 3])
    print (zip [1..10] [2, 4, 6, 1, 3])
    print(isAscending'' 12345)
    print(isAscending'' 12945)
    print(isImage [1,2,3] [2,3,5])
    print(isImage [1,2,3] [2,3,4])
    print(isImage [1,2,3] [])
    print(chunksOf 3 [1..10])
    print(divisors 1024)
    print(isTriangularHelper [0,0,0,0])
    print(isTriangularHelper [0, 4, 0, 0])
    print (isTriangular [[1, 2, 3, 4],
                         [0, 5, 6, 7],
                         [0, 0, 8, 9],
                         [0, 0, 0, 0]])
    print (isTriangular [[1, 2, 3, 4],
                         [0, 5, 6, 7],
                         [0, 0, 8, 9],
                         [0, 4, 0, 0]])






-- [Int], [[Int]], [[Int, Double]]

-- Да се дефинира функция multiplyAllBy :: [Int] -> Int -> [Int], която получава списък и число и умножава всеки елемент на списъка по числото.
multiplyAllBy :: [Int] -> Int -> [Int]
multiplyAllBy xs x = [ z*x | z<-xs]

-- Да се дефинира filterSmallerThan xs n, която получава списък xs и число n и премахва елементите на списъка xs, които са по-малко от числото n.
filterSmallerThan :: [Int] -> Int -> [Int]
filterSmallerThan xs x = [ z | z<-xs, z>x]

-- Да се дефинира функция isAscending :: Integer -> Bool, която проверява дали цифрите на число са във възходящ ред. Функцията да получава число, но да работи със списък от цифрите му.
getList :: Int -> [Int] 
getList n = helper n []
  where 
      helper n list 
       | n == 0 = list
       | otherwise = helper (div n 10) (mod n 10 : list)

numToList :: Int -> [Int]
numToList n = [ord d - ord '0'|d<- show n]

isAscending' :: Int -> Bool
isAscending' n = helper (numToList n)
    where
        helper []       = True
        helper [_]      = True
        helper (x:y:xs) = x <= y && helper (y:xs)

isAscending :: Int -> Bool 
isAscending n = helper (numToList n)
      where
           helper xs 
            | length xs == 1 = True 
            | head xs > head ( tail xs) = False 
            | otherwise = helper (tail xs)


-- xs !! 1 == head ( tail xs)
-- [Char] == string
-- ['a','b','c'] = "abc"
-- (Int, Double, String) == [1,1.24,"abc"]

-- vectors
v1 :: (Int, Double, String)
v1 = (1, 1.24, "abc")

v2 :: (Int, String)
v2 = (1, "abcd")

snd3 :: (Int, Double, String) -> Double
snd3 (_, x, _) = x

v3 :: (String, Int, Double)
v3 = ("gfa", 1, 2.54)

snd3' :: (a, b, c) -> b
snd3' (_, x, _) = x

countMembers :: [a] -> Int
countMembers xs =
    if null xs then 0 else 1 + countMembers (tail xs)

sumMembers :: Num a => [a] -> a
sumMembers xs =
    if null xs then 0 else head xs + sumMembers (tail xs)    

-- Eq a ->  ==, /=
-- Ord a -> <,>,<=, .... 
-- Num a ->  +,-,*, .......

zip' :: [a] -> [b] -> [(a, b)]
zip' []     _      = []
zip' _      []     = []
zip' (a:as) (b:bs) = (a, b) : zip' as bs

isAscending'' :: Int -> Bool
isAscending'' n = and [p<q | (p,q) <- zip ns ( tail ns)]
    where ns = numToList n

--  ai = x + bi  ai - bi = x
--Нека as = [a1, a2, … , ak] и bs = [b1, b2, … , bk] са непразни списъци с еднакъв брой числа. Да се дефинира предикат isImage :: [Int] -> [Int] -> Bool, който да връща „истина“ точно когато съществува такова число x, че ai = x + bi за всяко i = 1,..., k.
isImage :: [Int] -> [Int] -> Bool
isImage _ [] = False
isImage [] _ = False
isImage as bs = helper as bs (head as - head bs)
         where
             helper as bs x
              | null as || null bs = True
              | (head as - head bs) == x = helper ( tail as) ( tail bs) x
              | otherwise = False

isImage' :: [Int] -> [Int] -> Bool
isImage' (a:as) (b:bs) = as == [d + a - b|d<- bs]


-- Да се дефинира функция chunksOf :: Int -> [a] -> [[a]], която разделя входния списък на подсписъци с дължина равна на подаденото число.
-- import Data.List
-- take 3 [1..10] -> [1,2,3]
-- drop 3 [1..10] -> [4..10]

chunksOf :: Int -> [a] -> [[a]] 
chunksOf _ [] = []
chunksOf n xs  = (take n xs) : (chunksOf n (drop n xs))     

-- Да се дефинира функция divisors :: Integer -> [Integer], която генерира списък от всички (собствени) делители на дадено число
divisors :: Int -> [Int]
divisors 0 = []
divisors n = [x | x<- [1..n], mod n x == 0]


-- Да се дефинира предикат isTriangular :: [[Int]] -> Bool, който получава квадратна числова матрица, представена като списък от списъци, и проверява дали тя е горно триъгълна, т.е. дали всичките елементи под главния ѝ диагонал са нули.
isTriangular :: [[Int]] -> Bool
isTriangular xss = helper xss 0
         where 
             helper xss col
              | null xss = True
              | isTriangularHelper(take col (head xss) ) == True = helper (tail xss) (col + 1)
              | otherwise = False


isTriangularHelper :: [Int] -> Bool  
isTriangularHelper [] = True
isTriangularHelper xs = helper xs 0
          where
              helper xs param
               | null xs = True
               | head xs == param = helper (tail xs) param
               | otherwise = False

