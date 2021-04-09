main :: IO()
main = do
    print 1
    print 2
    print 3
    print n
    print (n + 1)
    print (f1 10 4)
    print (fact 5)
    print (myMin 2 7)
    print (isInside 5 2 10)
    print (calcAverage 3 4)
    print (fibRec 5)
    print (factIter 5)
    print (factIter 0)
    print (factIter 1)
    print (fibIter 40)
    print(isPrime 3)

n :: Int -- Int
n = 1

f1 :: Double -> Double -> Double
f1 a b = a * b

fact :: Int -> Int
fact n = if n == 0 then 1 else n * (fact (n - 1))
-- fact n -> n * fact (n - 1) -> n * (n - 1) * fact (n - 2) -> ...
-- ... -> n * (n - 1) * ... * 2  * 1 * 1 -> ...

factIter :: Int -> Int
factIter n = helper n 1

helper :: Int -> Int -> Int
helper i res =
    if i == 0 then res else helper (i - 1) (res * i)


isPrime :: Int -> Bool
isPrime 1 = False
isPrime n = helper 2
    where
        helper d
            | d == n       = True
            | mod n d == 0 = False
            | otherwise    = helper (d + 1)

-- factIter n -> helper n 1 -> helper (n - 1) (n * 1) -> ...
-- ... -> helper 0 (n * (n - 1) * (n - 2) * ... * 2 * 1 * 1) -> ...
-- ... -> (n * (n - 1) * (n - 2) * ... * 2 * 1 * 1)

-- Ctrl + Alt + N -> run
-- Ctrl + Alt + M -> stop

-- Int, Integer, Float, Double, Char, Bool, String

myMin :: Double -> Double -> Double
myMin a b = if a < b then a else b

isInside :: Int -> Int -> Int -> Bool
isInside x a b = x >= a && x <= b

calcAverage :: Double -> Double -> Double
calcAverage a b = (a ^ 2 + b ^ 2) / 2

-- 1, 1, 2, 3, 5, 8, 13, 21, ...
{-

fib(n) = {1                       , n <= 1
         {fib(n - 2) + fib(n - 1) , в противен случай

-}

fibRec :: Int -> Int
fibRec n = if n <= 1 then 1 else fibRec (n - 2) + fibRec (n - 1)

fibIter :: Int -> Int
fibIter n = helper 1 1 n
    where
        helper a b n = if n < 2 then b else helper b (a + b) (n - 1)