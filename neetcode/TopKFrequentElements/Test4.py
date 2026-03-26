def simple_decorator(func):
    print("compiled")
    def wrapper(x):
        print("Before the function call")
        func()
        print("After the function call")
    return wrapper

@simple_decorator
def greet():
    print("Hello!")



#greet()


