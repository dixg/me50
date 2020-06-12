from cs50 import get_string
import sys
from cs50 import get_int
import csv


# data = open("databases/small.csv", "r")
header= []
search_str = []
cmdline = []
cmdline_list=[]
# cmdline = sys.argv
# print(cmdline)
# print(len(cmdline))

# for i in range(len(cmdline)):
#      cmdline_list = cmdline[1:]
# print("final list- ",cmdline_list)
# print("final list[0] ", sys.argv[1])


with open(sys.argv[1], 'r') as file:
    reader= csv.reader(file)
    header = next(reader)
    #print("header[]= ",header)
    search_str=header[1:]
   # print("search_st[]= ", search_str)

    all_rows = []
    list_names=[]
    for row in reader:
        list_name = row[0]
        #print("list_name ",list_name)
        list_row = row[1:]
        #print("            list_row = ",list_row)
        for i in range(len(search_str)):  # changed datatype
            list_row[i]=int(list_row[i])
       # print("^^^^^^^^list_row = ",list_row)

        all_rows.append(list_row)
        list_names.append(list_name)
        #print("all_rows = ", all_rows)
        # print("list_names = ", list_names)

    total_rows = reader.line_num -1
    # print("Total no. of rows: ", total_rows)
    # print("all_rows = ", all_rows)


seq = open(sys.argv[2], "r")
sequence_input = seq.readline()


#Function to get number of repetation
def get_repetation(str1,key,i):
    round = 0
    k=i
    while k < len(str1):
        count = 0

        for j in range(len(key)):   # If Key char matches in str1
            if(j + k > len(str1) - 1):
                break
            elif (key[j] == str1[j+k]): #
                count = count + 1
                #print("count =", count)
            else:
                break

        if (count == len(key)):
            k = (k + len(key))
            round = round + 1
            #print(" rotation complete round", round)

        else:
           # print("!!Str1 char does't match. ", k)
            return round

    return round
#program
str1 = sequence_input
seq_str = search_str
compare_list=[]
for num_str in range(len(seq_str)):
    key = seq_str[num_str]
    #print(key)
    arr = [0]*len(str1)
    #print("\nBefore, arr[]=", arr)
    #print("\n")
    #print("@@@@@2",len(str1))
    for i in range(len(str1)):
        #print("[i] =", i)
        num_repeat = get_repetation(str1,key,i)

        # print("num_repeat =", num_repeat)
        arr[i] = num_repeat
        # DONT  print("arr[i] =", arr[i])
        # compare_list[i] =  max(arr)
        # print("compare_list", compare_list)
        # print("i=",i)
    max_repeat = max(arr)
    # print("MAX!!!",max_repeat)
    # print("!!!!", num_str)
    compare_list.append(max(arr))

    compare_list[num_str] =  max_repeat


    #print("Largest repeation is of str", max(arr))
    # print("compare_list = ", compare_list)

# print("compare_list = ", compare_list)
found_answer = False
for i in range(total_rows):
    if(all_rows[i] == compare_list):
        found_answer = True
        print(list_names[i])
   
if not found_answer:
    print("No match")
        
        
        
    # list_name = row[0]
    # list_row = row[1:]
    # print("row ",list_name)
    # print("row = ",list_row)












