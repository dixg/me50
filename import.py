import sys
import csv
from cs50 import SQL

db = SQL("sqlite:///students.db")
with open(sys.argv[1], "r") as file:
    if len(sys.argv) < 2 or len(sys.argv) > 2:
        sys.exit(0)
    reader = csv.DictReader(file)

    for row in reader:
        name = row["name"]
        house = row["house"]
        birth = row["birth"]
        print(house)
        print(birth)
        name_list=[name]
        list_final=name_list[0].split()
        print(list_final)
        
        if len(list_final)== 2:
            l_name=list_final[1]
            list_final[1]="None"
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?,?,?,?,?)", (list_final[0],list_final[1],l_name, house, birth));
            #db.execute("INSERT INTO students(first, middle , last) VALUES ({1}, %s, %s)", (list_final[0], list_final[1], l_name))
            
            # print("it has two strings")
            # print(list_final[0])
            # print(list_final[1])
            # print(l_name)
        else:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?,?,?,?,?)", (list_final[0],list_final[1],list_final[2],house, birth));
            # print("it has three strings")
            # print(list_final[0])
            # print(list_final[1])
            # print(list_final[2])
    
    
