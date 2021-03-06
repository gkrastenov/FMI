main :: IO()
main = do
    print (myGCD 25 5)
    print (countDigits 3400)


-- Задача 1. Да се дефинира функция myGCD a b, която връща най-големия общ делител на числата a и b.

-- first way
myGCD :: Integer -> Integer -> Integer
myGCD a b = if b == 0 then a else myGCD b (a `mod` b)

-- first way
myGCD2 :: Integer -> Integer -> Integer
myGCD2 a b = 
    if a == b then a
    else if a > b then myGCD2 (a - b) b
    else myGCD2 a (b - a)


-- Задача 2. Да се дефинира функция countDigits, която генерира линейно рекурсивен процес и намира броя на цифрите на дадено естествено число.
countDigits :: Integer -> Integer
countDigits num = helper num 0
    where
        helper num res = if num == 0 then res else helper (num `div` 10) (res + 1)