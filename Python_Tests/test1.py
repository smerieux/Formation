from math import sqrt


class Cmplx(object):
    # __slots__ permet d'économiser l'espace, et d'allouer la mémoire de manière minimaliste. Dans ce cas,
    # chaque instance de la classe ne contiendra pas de dictionnaire complet accessible via __dict__, par exemple:
    __slots__ = ['reel', 'imag']

    def __init__(self, x, y):
        self.reel = x
        self.imag = y

    def norm(self):
        return sqrt(self.reel ** 2 + self.imag ** 2)

    def __repr__(self):
        return f"{self.reel}, {self.imag}"


def traitement_complexe(iterable):
    for x in iterable:
        if x not in (1, 3, 7) and x % 2 != 0:
            if x + x < 13:
                yield x
            else:
                yield x - 2


def numbers_limits(numbers):
    min_ = min([int(i) for i in numbers.split()])
    max_ = max([int(i) for i in numbers.split()])
    numbers = f"{max_} {min_}"
    return numbers


def likes(names):
    nb_names = len(names)
    if not nb_names:
        return 'no one likes this'
    elif 0 < nb_names < 4:
        if nb_names == 1:
            return f'{names[0]} likes this'
        elif nb_names == 2:
            return f'{names[0]} and {names[1]} like this'
        elif nb_names == 3:
            return f'{names[0]}, {names[1]} and {names[2]} like this'
    else:
        return f'{names[0]}, {names[1]} and {len(names) - 2} others like this'
    # More elegant way to do this!!
    n = len(names)
    return {
        0: 'no one likes this',
        1: '{} likes this',
        2: '{} and {} like this',
        3: '{}, {} and {} like this',
        4: '{}, {} and {others} others like this'
    }[min(4, n)].format(*names[:3], others=n - 2)


def create_phone_number(n):
    # return f'{n[0]}{n[1]}{n[2]} {n[3]}{n[4]}{n[5]}-{n[6]}{n[7]}{n[8]}{n[9]}'
    # An other way with format() and *n that convert a list n into *n arguments
    return "({}{}{}) {}{}{}-{}{}{}{}".format(*n)


# def evaluate(value, sign):
#     result = 0
#     if '+' in sign:
#         result = value + int(sign[1:])
#     elif '-' in sign:
#         result = value - int(sign[1:])
#     elif '*' in sign:
#         result = value * int(sign[1:])
#     elif '/' in sign:
#         result = int(value / int(sign[1:]))
#     return result
#
#
# def zero(expression=None):
#     value = 0
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def one(expression=None):
#     value = 1
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def two(expression=None):
#     value = 2
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def three(expression=None):
#     value = 3
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def four(expression=None):
#     value = 4
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def five(expression=None):
#     value = 5
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def six(expression=None):
#     value = 6
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def seven(expression=None):
#     value = 7
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def eight(expression=None):
#     value = 8
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def nine(expression=None):
#     value = 9
#     if expression is not None:
#         value = evaluate(value, expression)
#     return value
#
#
# def plus(value=None):
#     return f'+{value}'
#
#
# def minus(value=None):
#     return f'-{value}'
#
#
# def times(value=None):
#     return f'*{value}'
#
#
# def divided_by(value=None):
#     return f'/{value}'


def zero(f=None): return 0 if not f else f(0)


def one(f=None): return 1 if not f else f(1)


def two(f=None): return 2 if not f else f(2)


def three(f=None): return 3 if not f else f(3)


def four(f=None): return 4 if not f else f(4)


def five(f=None): return 5 if not f else f(5)


def six(f=None): return 6 if not f else f(6)


def seven(f=None): return 7 if not f else f(7)


def eight(f=None): return 8 if not f else f(8)


def nine(f=None): return 9 if not f else f(9)


def plus(y): return lambda x: x + y


def minus(y): return lambda x: x - y


def times(y): return lambda x: x * y


def divided_by(y): return lambda x: x / y


def fibo(a=0, b=1):
    while True:
        yield a
        a, b = b, a + b


def firstn(n):
    num = 0
    while num < n:
        yield num
        num += 1


if __name__ == '__main__':
    print("-".join(map(str, traitement_complexe(range(20)))))
    print("-".join(str(traitement_complexe(range(20)))))
    print(traitement_complexe(range(20)))
    z = Cmplx(1, 5)
    # Ajout dynamique d'un attribut non référencé
    # z.fake = z.reel + z.imag
    # print(z.__dict__)
    print(f" z repr: {z.__repr__}")
    print(Cmplx.__dict__)
    print(numbers_limits("4 5 29 54 4 0 -214 542 -64 1 -3 6 -6"))
    print(likes([]))
    print(likes(['Peter']))
    print(likes(['Jacob', 'Alex']))
    print(likes(['Max', 'John', 'Mark']))
    print(likes(['Alex', 'Jacob', 'Mark', 'Max']))
    names = ['Alex', 'Jacob', 'Mark', 'Max']
    n = len(names)
    ret = {
        0: 'no one likes this',
        1: '{} likes this',
        2: '{} and {} like this',
        3: '{}, {} and {} like this',
        4: '{}, {} and {others} others like this'
    }
    toto = ret[3]
    tata = ret[min(4, n)].format(*names[:3], others=n - 2)
    print(tata)
    print(create_phone_number([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]))
    print(create_phone_number([1, 1, 1, 1, 1, 1, 1, 1, 1, 1]))
    print(create_phone_number([0, 2, 3, 0, 5, 6, 0, 8, 9, 0]))
    print(one(plus(zero())))
    print(one(plus(two())))
    print(one(minus(zero())))
    print(one(times(zero())))
    print(two(plus(zero())))
    print(two(minus(zero())))
    print('----------------')
    print(seven(times(five())))
    print(four(plus(nine())))
    print(eight(minus(three())))
    print(six(divided_by(two())))
    print('----------------')
    q = fibo()
    print(q)
    for x in q:
        if x < 20000:
            print(f'----{x}----')
        else:
            break
    # sum_of_first_n = sum(firstn(1000000))
    sum_of_first_n = firstn(1000000)
    print(sum(sum_of_first_n))
    lum_of_first_n = sum(range(1000000))
    print(lum_of_first_n)

