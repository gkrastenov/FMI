main :: IO()
main = do
    print (f1 5)
    print (f2 f1 7)
    print ((\ a -> a * 5) 2) -- 10
    print ((f3 8) 7)
    print (f4 7)
    print (f3 8 7)
    print (f6 1 2 3 )
    print (((f6 1) 2) 3)
    print ((f6 1 2) 3)
    print (2 + 5)
    print (plus5 2)
    print ((\ x -> x == 0) 10)
    print ((\ x -> x == 0) 0)
    print ((== 0) 10)
    print ((== 0) 0)
    print ( map (+2)[1..10])
    print (f7 [10..20])
    print (((* 5) . (+ 2)) 7)
    print (map ((* 5) . (+ 2)) [1..10])
    print ((myNegate (>5) ) 5)
    print ((derive (\ x -> 2 * x * x) 1e-3) 10)
    print ((derive (\ x -> 2) 1e-3) 10)
    print ((derive2 (\ x -> 2 * x * x) 1e-3) 10)
    print ((deriven (\ x -> 2 * x * x) 0 1e-3) 10)
    print ((deriven (\ x -> 2 * x * x) 1 1e-3) 10)
    print ((deriven (\ x -> 2 * x * x) 2 1e-3) 10)
    print ((deriven (\ x -> 2 * x * x) 3 1e-3) 10)
    print ((repeated (^ 2) 3) 2)

f7 :: [Int] -> [Int]
f7 = map ( + 2) 
-- map1 f xs = [f x | x<-xs]
-- map f xs

map1 :: (a -> b) -> [a] -> [b]
map1 _ [] = []
map1 f (x:xs) = f x : map1 f xs

-- filter p xs = [x | x<- xs , p x]
filter1 ::(a -> Bool) -> [a] -> [a]
filter1 _ [] = []
filter1 p (x:xs) =
    if p x then x : filter1 p xs else filter1 p xs

f1 :: Int -> Int
f1 x = 2 * x

f2 :: (Int -> Int) -> Int -> Int
f2 f x = f ( x * 2)

f3 :: Int -> (Int -> Int)
f3 x = \ z -> z * x
-- f3 x z = x * z

f4 :: Int -> Int
f4 = f3 8

--- f5 :: (Int -> Int) -> Int -> (Int -> Int)

--f6 :: Int -> Int -> Int -> Int
f6 :: Int -> (Int -> (Int -> Int))
f6 a b c = a * b + c
-- f6 a b = \ c -> a * b + c
-- f6 a = \ b c -> a * b + c
-- f6 = \ a b c -> a * b + c

plus5 = ( + 5)

-- Задача 1. Дефинирайте следните функции:

--  a). (mIdentity x), функцията идентитет: връща x без да го променя.

--  б). (myCompose f g), която връща композицията на функциите f и g.

--  в). (myNegate p), която приема предикат p? и връща предиката (not p?).

--  г). (myCurry f x), която приема многоаргумента функция f и първи аргумент x и връща функцията, получена от частичното прилагане на x върху f.

myIdentity :: a -> a
myIdentity x = x

myCompose :: (a -> b) -> (c -> a) -> (c -> b)
myCompose f g = \ x -> f (g x)

myCompose' :: (a -> b) -> (c -> a) -> (c -> b)
myCompose' f g x = f (g x)

myCompose'' :: (a -> b) -> (c -> a) -> (c -> b)
myCompose'' f g = f . g

myNegate :: (a -> Bool) -> (a -> Bool)
myNegate p x = not (p x)

myNegate' :: (a -> Bool) -> (a -> Bool)
myNegate' p = \x -> not (p x)

myNegate'' :: (a -> Bool) -> (a -> Bool)
myNegate'' p = not . p

myCurry :: (Int -> Int -> Int -> Int) -> Int -> (Int -> Int -> Int)
myCurry f x = \ y z -> f x y z
--myCurry f x = f x

--  Да се дефинира процедура от по-висок ред (difference F a b), която по дадени едноаргументна реална функция F и две реални числа a и b намира разликата F(b) - F(a). Да се оцени примерно обръщение към процедурата.

difference :: Num b => (a -> b) -> a -> a -> b
difference f a b = (f b) - (f a)

-- Чрез използване на ламбда израз да се дефинира процедурен обект, който е еквивалентен на f, ако имаме дефиницията f x = 2 * x.
--f x = 2 * x
--f = \ x -> x * 2

-- а се дефинира процедура от по-висок ред (derive f eps), която намира първа производна на едноаргументната реална функция f с точност eps.
derive :: (Double -> Double) -> Double -> (Double -> Double)
derive f eps = \ x -> (f (x + eps) - f x) / eps

-- Да се дефинира процедура от по-висок ред (derive2 f eps), която намира втора производна на едноаргументната реална функция f с точност eps.
derive2 :: (Double -> Double) -> Double -> (Double -> Double)
derive2 f eps = derive (derive f eps) eps

-- Да се дефинира процедура от по-висок ред (deriven f n eps), която намира n-та производна на едноаргументната реална функция f с точност eps.
deriven :: (Double -> Double) -> Int -> Double -> (Double -> Double)
deriven f 0 _   = f
deriven f n eps = derive (deriven f (n - 1) eps) eps

--Да се дефинира процедура от по-висок ред (repeated f n), която намира n-кратна композиция на едноаргументната реална функция f:
repeated :: (a -> a) -> Int -> (a -> a)
repeated f 1 = f
repeated f n = f . (repeated f (n - 1)) 
-- repeated f n = \x  -> f ((repeated f (n - 1)) x) 