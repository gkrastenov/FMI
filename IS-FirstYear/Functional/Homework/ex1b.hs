main :: IO()
main = do
    print(specialSum 3 21)

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