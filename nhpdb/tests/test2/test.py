import pickle
from Content import Content 

contentDoc = Content('test')

fo = open("newdoc.txt","wb")
fo.write(pickle.dumps(contentDoc))
fo.close()

print pickle.dumps(contentDoc)
