from random import random, randint, choice


def f(x):
    def g(y):
        return y + x + 3

    return g


nf1 = f(1)
nf2 = f(3)

print('nf1 = f(1), nf1(1) = f(1)(1) => ', nf1(1))
print('nf2 = f(3), nf2(1) = f(3)(1) => ', nf2(1))


def polynomial_creator(a, b, c):
    def polynomial(x):
        return a * x ** 2 + b * x + c

    return polynomial


p1 = polynomial_creator(2, 3, -1)
p2 = polynomial_creator(-1, 2, 1)

print('p1 = ', p1)
print('p2 = ', p2)

for x in range(-2, 2, 1):
    print('x = ', x,
          '--p1(x) = ', p1(x),
          '--p2(x) = ', p2(x))

print('--------------------------')


def our_decorator(func):
    def function_wrapper(x):
        print("Wrapper func: before calling " + func.__name__)
        print(func(x))
        print("Wrapper func: after calling " + func.__name__)

    return function_wrapper


@our_decorator
def foo(x):
    print(f"=> foo has been called with '{x}' as argument")


@our_decorator
def succ(n):
    return n + 1


print("1. We call foo before decoration: foo('Hi')")
foo("Hi")

print("2. We now decorate foo with func:\n    foo = our_decorator(foo)")
# corresponding to @our_decorator above foo declaration
# foo = our_decorator(foo)

print("3. We call foo after decoration: foo(42)")
foo(42)

print("4. We call succ with same decorator: succ(10)")
succ(10)

print('--------------------------')


def my_decorator(func):
    def function_wrapper(*args, **kwargs):
        print("Before calling " + func.__name__)
        res = func(*args, **kwargs)
        print(res)
        print("After calling " + func.__name__)

    return function_wrapper


# @ symbol is not available for third party functions (eg. builtins)
random = my_decorator(random)
randint = my_decorator(randint)
choice = my_decorator(choice)

random()
randint(3, 8)
choice([4, 5, 6])

print('--------------------------')


# Use cases for decorators
def argument_test_natural_number(f):
    def helper(x):
        if type(x) == int and x > 0:
            return f(x)
        raise Exception("Argument is not an integer")

    return helper


@argument_test_natural_number
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n - 1)


for i in range(1, 10):
    print(i, factorial(i))

# print(factorial(-1))

print('--------------------------')


def call_counter(func):
    def helper(x):
        helper.calls += 1
        return func(x)

    helper.calls = 0

    return helper


@call_counter
def success(x):
    return x + 1


print(success.calls)
for i in range(10):
    success(i)

print(success.calls)

print('--------------------------')


def call_counter_1(func):
    def helper(*args, **kwargs):
        helper.calls += 1
        return func(*args, **kwargs)

    helper.calls = 0

    return helper


@call_counter_1
def succ_1(x):
    return print(x + 1)


@call_counter_1
def mul1(x, y=1):
    return print(x * y + 1)


print(succ_1.calls)
for i in range(10):
    succ_1(i)
mul1(3, 4)
mul1(4)
mul1(y=3, x=2)

print(succ_1.calls)
print(mul1.calls)

print('--------------------------')


def evening_greeting(func):
    def function_wrapper(x):
        print("Good evening, " + func.__name__ + " returns:")
        func(x)

    return function_wrapper


def morning_greeting(func):
    def function_wrapper(x):
        print("Good morning, " + func.__name__ + " returns:")
        func(x)

    return function_wrapper


@evening_greeting
def foo(x):
    print(42)


foo("Hi")

print('--------------------------')


def greeting(expr):
    def greeting_decorator(func):
        def function_wrapper(x):
            print(expr + ", " + func.__name__ + " returns:")
            print(x)
            func(x)
            print(f'docstring of {func.__name__}: {function_wrapper.__doc__}')
            print(f'module of {func.__name__}: {function_wrapper.__module__}')

        print(f'docstring of {function_wrapper.__name__}: {function_wrapper.__doc__}')
        print(f'module of {function_wrapper.__name__}: {function_wrapper.__module__}')
        return function_wrapper

    return greeting_decorator


@greeting("καλημερα")
def foo(x):
    print(f'{x}', 42)


foo("Salut")

print('--------------------------')

s = "Toronto is the largest City in Canada!!!!!!!!!!!!"
t = "Python courses in Toronto by Bodenseo!"
u = "".join(["".join(x) for x in zip(s, t)])
print('s = ', len(s))
print('t = ', len(t))
print(u)

dadaz = ["ab", "bc", "cd"]
print(dadaz)
pro = ("Python is good",)
dadaz.extend(pro)
print(dadaz)
