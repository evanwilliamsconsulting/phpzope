from ExtensionClass import *
from Acquisition import Implicit
from Content import Content

class Wordage(Content):
    def __init__(self, name):
	super.Content(self,name)
	self._wordage = "Hello.  There once lived a man in a house."
	self._columnsize = 45

    def getWordage(self):
        return wordage

    def setWordage(self,wordage):
        self.wordage = wordage

    def getColumnsize(self):
        return self.columnsize

    def setColumnsize(self,columnsize):
        self.columnsize = columnsize 

if __name__ == "__main__":
    print "Test"
