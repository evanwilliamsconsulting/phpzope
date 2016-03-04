from ExtensionClass import *
from Acquisition import Implicit

class Simple(Base,Implicit):
    def __init__(self, name, **kw):
        self.__name__ = name
        self.__dict__.update(kw)
        self._v_favorite_color = 'blue'
        self._p_foo = 'bar'

    def __eq__(self, other):
        return cmpattrs(self, other, '__class__', *(self.__dict__.keys()))

class Complex(Implicit):
    def __init__(self,name):
	self.__name__ = name 

    def setSimple(self,myobj):
       	self.obj = myobj 

    def getSimple(self):
	return self.obj
