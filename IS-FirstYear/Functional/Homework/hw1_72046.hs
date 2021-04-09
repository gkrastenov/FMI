main :: IO()
main = do
    --1a
    print(safePrimesCount 20 100) -- 4
    print(safePrimesCount 1 983) -- 25
    print(safePrimesCount 167 1892) -- 28
    print(safePrimesCount 1678 20097) -- 155
    --1b
    print(specialSum 3 21)
    --2
    print(validation 1714) 
    print(validation 12345) 
    print(validation 891) 
    print(validation 123) 
    print(validation 2121) 
    print(validation 4736778291034) 
    print(validation 4485756008412) 
    print(validation 4485756008422)
    print(validation 4214154976719) 

validation :: Int -> Bool
validation number
 | number < 10 = False
 | otherwise = helper number 0 0
  where
      helper :: Int -> Int -> Int -> Bool
      helper number result param
       | number < 10 = if param == 1 then isDivederByTen (result + checkIsBiggerThanTen( number * 2)) else isDivederByTen (result + number)
       | param == 1 = helper (div number 10)  ( result + checkIsBiggerThanTen ((mod number 10) * 2))  0        
       | otherwise = helper (div number 10) (result + (mod number 10)) 1

isDivederByTen :: Int -> Bool
isDivederByTen number = if(mod number 10) == 0 then True else False

-- Check if number is bigger than 10 if it is bigger then return sum of digits. Example 12 -> 1+2 = 3
checkIsBiggerThanTen :: Int -> Int
checkIsBiggerThanTen number = if(number >= 10) then ((div number 10 ) + (mod number 10)) else number


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

specialSum :: Int -> Int -> Int
specialSum count minNumber = helper count minNumber 0
 where
    helper::Int -> Int -> Int -> Int
    helper count current result
     | count == 0 = result
     | isNumberDeliverByTwo (current+1) == True = if isPrimePow(current+1) then helper (count-1) (current+1) (result+current) else helper count (current + 1) result
     | otherwise = helper count (current + 1) result

isNumberDeliverByTwo :: Int -> Bool
isNumberDeliverByTwo number
 | number == 1 = True 
 | mod number 2 == 1 = False 
 | mod number 2 == 0 = isNumberDeliverByTwo (div number 2) 


getPow :: Int -> Int-> Int
getPow number pow = if( number == 1) then pow else getPow (div number 2) ( pow + 1)

isPrimePow:: Int -> Bool
isPrimePow current = isPrime (getPow current 0)


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