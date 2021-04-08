main :: IO()
main = do
    print("my tests")
    print(validation 91)
    print(validation 18)
    print("have to be false")
    print(validation 1714) 
    print(validation 12345) 
    print(validation 891) 
    print(validation 123) 
    print(validation 4485756008422) -- dava true
    print("have to be true")
    print(validation 2121) 
    print(validation 4736778291034) -- 60
    print(validation 4485756008412) 
    print(validation 4214154976719) -- sum is 60

validation :: Int -> Bool
validation number
 | number < 10 = False
 | otherwise = helper number 0 0
  where
      helper :: Int -> Int -> Int -> Bool
      helper number result param
       | number < 10 = if param == 1 then isDivederByTen (result + checkIsBiggerThanTen( number * 2)) else isDivederByTen (result + number)
       | param == 1 = helper (div number 10)  ( result + checkIsBiggerThanTen ((mod number 10) * 2))  0                -- have to be double
       | otherwise = helper (div number 10) (result + (mod number 10)) 1

isDivederByTen :: Int -> Bool
isDivederByTen number = if(mod number 10) == 0 then True else False

checkIsBiggerThanTen :: Int -> Int
checkIsBiggerThanTen number = if(number >= 10) then ((div number 10 ) + (mod number 10)) else number