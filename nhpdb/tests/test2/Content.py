from ExtensionClass import *
from Acquisition import Implicit

class Content(Base, Implicit):
    def __init__(self, name):
        self.__name__ = name
	self.id = ''
	self.username = ''
	self.original = ''
	self.title = ''

    def getName(self):
        return self.__name__

    def setName(self,name):
        self.__name__ = name
 
    def getId(self):
        return self.id
 
    def setId(self,id):
        self.id = id

    def getUsername(self):
        return self.username

    def setUsername(self,username):
        self.username = username

    def getOriginal(self):
	self.original = original

    def setOriginal(self,original):
        self.original = original
        
    def getTitle(self):
        seldf.title = title

    def setTitle(self,title):
        self.title = title

if __name__ == "__main__":
    print "Test"
