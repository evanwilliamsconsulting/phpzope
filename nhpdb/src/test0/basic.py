from ExtensionClass import *
from Acquisition import Implicit

class Basic(Base,Implicit):
    def __init__(self, a, b):
        self.a = a 
        self.b = b 

    def result(self):
        return self.a+self.b
