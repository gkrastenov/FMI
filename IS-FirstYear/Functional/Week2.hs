main :: IO()
main = do
    print (myGCD 25 5)
    print (countDigits 3400)
    print (sumDigitsRec 2050)
    print( powByTen 2 0)

-- Задача: Да се дефинира функция myGCD a b, която връща най-големия общ делител на числата a и b.

-- first way
myGCD :: Integer -> Integer -> Integer
myGCD a b = if b == 0 then a else myGCD b (a `mod` b)

-- second way
myGCD2 :: Integer -> Integer -> Integer
myGCD2 a b = 
    if a == b then a
    else if a > b then myGCD2 (a - b) b
    else myGCD2 a (b - a)


-- Задача: Да се дефинира функция countDigits, която генерира линейно рекурсивен процес и намира броя на цифрите на дадено естествено число.
countDigits :: Integer -> Integer
countDigits num = helper num 0
    where
        helper num res = if num == 0 then res else helper (num `div` 10) (res + 1)

-- Задача: Да се дефинира функция sumDigitsRec, която генерира линейно рекурсивен процес и намира сумата от цифрите на дадено естествено число.
sumDigitsRec :: Integer -> Integer
sumDigitsRec num = helper num 0
    where
       helper num res = if num == 0 then res else helper (num `div` 10) (res + (num `mod` 10))
 
powByTen :: Integer -> Integer -> Integer
powByTen num step = helper num step num
    where
         helper num step res = if step == 0 then res else helper num (step - 1) (res * 10)

-- Задача: Да се дефинира функция reverseNumber, която генерира линейно итеративен процес и по дадено естествено число n намира числото, записано със същите цифри, но в обратен ред.


