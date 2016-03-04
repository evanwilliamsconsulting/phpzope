# www.dangtrinh.com/2013/06/sqlalchemy-python-module-with-mysql.html
# create table sqltest
# use sqltest
#  create table mytable (id int(11) not null auto_increment, name varchar(100) not null, value varchar(100) not null,PRIMARY KEY(id));

# BUMP
#
# "What is the meaning of BUMP?"

#
# http://stackoverflow.com/questions/24872541/could-not-assemble-any-primary-key-columns-for-mapped-table
#


from sqlalchemy import create_engine
engine = create_engine('mysql://root:ptH3984z@localhost:3306/sqltest',echo=False)

from sqlalchemy.orm import sessionmaker
Session = sessionmaker(bind=engine)
session = Session()

from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String

Base = declarative_base()
class MyTable(Base):
    __tablename__ = 'mytable'
    id == Column(Integer,primary_key=True)
    name = Column(String(100))
    value = Column(String(100))
   
    def __init__(self,name,value):
        self.name = name
        self.value = value
 
    def __repr__(self):
        return "<MyTable(%s,%s)>" % (self.name,self.value)
