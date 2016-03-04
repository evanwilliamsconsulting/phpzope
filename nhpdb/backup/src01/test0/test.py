import pickle
from basic import Basic 

basicDoc = Basic(1,2)
print basicDoc.result()

fo = open("newdoc.txt","wb")
fo.write(pickle.dumps(basicDoc))
fo.close()

print pickle.dumps(basicDoc)
