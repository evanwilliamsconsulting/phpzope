import pickle
#from document import Document
from simple import Simple
from simple import Complex


fo = open("newdoc.txt","rb")
newPickle = pickle.loads(fo.read())
fo.close()

print newPickle
print newPickle.__dict__
