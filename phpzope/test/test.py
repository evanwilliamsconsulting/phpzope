import pickle
#from document import Document
from simple import Simple
from simple import Complex

newDoc = Simple("somedoc")
print newDoc.__dict__
newDoc2 = Complex("someotherdoc")
newDoc2.setSimple(newDoc)

fo = open("newdoc.txt","wb")
fo.write(pickle.dumps(newDoc2))
fo.close()

print pickle.dumps(newDoc2)
