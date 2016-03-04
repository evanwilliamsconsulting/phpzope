import pickle
from Content import Content
from Wordage import Wordage 

contentDoc = Wordage('test')

fo = open("newdoc.txt","wb")
fo.write(pickle.dumps(contentDoc))
fo.close()

print pickle.dumps(contentDoc)
