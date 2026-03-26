class Main:
    x = 0

    def __init__(self, x = 10):
        print("hello")
        self.x = x

    def test(self, max=100):
        print("hello")
        if max > 0:
            self.test(max - 1)


obj = Main()
obj.test(20)
