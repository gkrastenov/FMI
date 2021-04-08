main :: IO()
main = do
    print( pow 2 1)
    print( isAscending 123)
    print ( countOccurences 22222 2)

-- Да се дефинира функция pow, която генерира линейно рекурсивен процес и намира x на степен n, където x е реално, а n - естествено число.
pow :: Double -> Int -> Double
pow n x  
    | x == 0 = 1
    | otherwise = helper n x n
     where 
        helper n x result = if x == 1 then result else helper n (x - 1) (result * n)

--  Да се дефинира предикат isPrime, който проверява дали дадено естествено число е просто.        

-- Да се дефинира предикат isAscending, който връща истина, ако цифрите на дадено естествено число са в нарастващ ред от първата към последната.
isAscending :: Int -> Bool
isAscending n 
        | n < 10 = True
        | otherwise = isAscendingHelper ( div n 10) ( mod n 10)

isAscendingHelper :: Int -> Int -> Bool
isAscendingHelper  num lastDigit
        | num < 10 = num < lastDigit
        | ( mod num 10) < lastDigit = isAscendingHelper ( div num 10) ( mod num 10)
        | otherwise = False

-- Да се дефинира функция countOccurences, намираща броя на срещанията на дадена цифра d в записа на число n.
countOccurences :: Int -> Int -> Int
countOccurences num digit
        | num < 10 = if num == digit then 1 else 0
        | otherwise = countOccurencesHelper num digit 0

countOccurencesHelper :: Int -> Int -> Int -> Int
countOccurencesHelper num digit countDigits
        | num < 10 = if num == digit then countDigits + 1 else countDigits
        | otherwise = if( mod num 10) == digit then countOccurencesHelper ( div num 10) digit ( countDigits + 1) else countOccurencesHelper ( div num 10) digit countDigits