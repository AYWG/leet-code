from threading import Condition
class FooBar:
    def __init__(self, n):
        self.n = n
        self.count = 0
        self.cv = Condition()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            with self.cv:
                while self.count % 2 == 1:
                    self.cv.wait()
                self.count += 1
                self.cv.notify()
                # printFoo() outputs "foo". Do not change or remove this line.
                printFoo()
            



    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            with self.cv:
                while self.count % 2 == 0:
                    self.cv.wait()
                self.count += 1
                self.cv.notify()
                # printBar() outputs "bar". Do not change or remove this line.
                printBar()