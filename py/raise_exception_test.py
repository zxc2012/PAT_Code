class TraceBlock:
    def message(self,aa):
        print("enter",aa)
    def __enter__(self):
        print("enter class Trace")
        return self
    def __exit__(self, exc_type, exc_value, exc_tb):
        if exc_type is None:
            print("exit normally!")
        else:
            print("raise an Exception")##,str(exc_type))
with TraceBlock() as action:
 action.message("test 1")
 print("reached")
  
print('-' * 20, "\n")
 
with TraceBlock() as action:
 action.message("test 2")
 raise TypeError
 print("not reached")
