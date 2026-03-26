class Test:
    def test(self, x):
        self.x = 10


obj = Test()
Test.test(obj, 10)
