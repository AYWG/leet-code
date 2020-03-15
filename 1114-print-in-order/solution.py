from threading import Lock

class Foo:
    def __init__(self):
        self.counter = 0
        self.lock = Lock()


    def first(self, printFirst: 'Callable[[], None]') -> None:
        self.lock.acquire()
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.counter += 1
        self.lock.release()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        while True:
            self.lock.acquire()
            if self.counter < 1:
                self.lock.release()
                continue
            break
        
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        self.counter += 1
        self.lock.release()


    def third(self, printThird: 'Callable[[], None]') -> None:
        while True:
            self.lock.acquire()
            if self.counter < 2:
                self.lock.release()
                continue
            break
            
        # printThird() outputs "third". Do not change or remove this line.
        printThird()
        self.lock.release()