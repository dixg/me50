import sys
import csv
import sqlite3
from cs50 import SQL

db = SQL("sqlite:///students.db")
if len(sys.argv) < 2 or len(sys.argv) > 2:
    sys.exit(0)
given_house=sys.argv[1]
# print(given_house)
sql_q = "select DISTINCT first, middle, last, birth from students where house = ? order by last"
retun_value=db.execute(sql_q, (given_house,))
for dic in retun_value:
    list_rows = list(dic.values())
    for i in range(len(list_rows)):
        element = list_rows[i]
        if type(element) == int:
            str_int =  ", born " + str(element)
            list_rows[i] = str_int
    result_list=[]
    
    for element in list_rows:
        if element == 'None':
           pass
        else:
            result_list.append(element)
    print(' '.join(result_list))



