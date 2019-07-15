from functools import reduce


def divide(x, y):
    try:
        result = x / y
        # return print("result is", result)
    except ZeroDivisionError:
        print("division by zero!")
    except TypeError as err:
        print(err)
    else:
        print("result is", result)
    finally:
        print("executing finally clause")
        if not int(y) <= 0:
            return print('cast result', int(x) / int(y))


divide(2, 1)
divide(2, 0)
divide(2, '1')

a = [1, 2, 3]
b = [4, 5, 6, 7]

c = list(zip(a, b))
d = [a, b]
print('zipped lists:', c)
print('appended lists:', d)

a1, a2 = zip(*zip(a, b))
# a1, a2 = zip(a, b)

print('a1 zipped: ', a1)
print('a2 zipped: ', a2)
print('a1: ', list(a1))
print('a2: ', list(a2))

print('-----------------------------')


def my_func(*args, **kwargs):
    try:
        if 'toto' in kwargs:
            print(f"hi {kwargs.get('toto')} and {kwargs.get('titi')}")
        else:
            raise NameError('toto')
    except NameError:
        print('An exception flew by!')
    else:
        print('*args: ', *args)
        print('kwargs: ', kwargs)


my_func('toto', [0, 1, 2, 3], toto='tata', titi='tutu')
my_func('toto', [0, 1, 2, 3], popo='tata', titi='tutu')

print('-----------------------------')


def mult(*args):
    return reduce(lambda x, y: x * y, args)


def div(*args):
    try:
        result = reduce(lambda x, y: x / y, args)
    except ZeroDivisionError:
        print('division by zero')
    else:
        return result
    finally:
        print('All is fine!!')


print(mult(1, 2, 3, 4))
print(div(100, 2, 3))
print(div(100, 0, 3))
