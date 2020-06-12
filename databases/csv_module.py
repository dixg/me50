# importing csv module
import csv

# csv file name
filename = "small.csv"

# initializing the titles and rows list
fields = []
rows = []

# reading csv file
with open(filename, 'r') as csvfile:
	# creating a csv reader object
	csvreader = csv.reader(csvfile)

	# extracting field names through first row
	fields = next(csvreader)
	print("\nHeader: ", fields)

	# extracting each data row one by one
	for i in csvreader:
		rows.append(i)
			
	# 	print("i: ",i)
	print("Appended rows: ",rows)
	
# printing the field names
print('Field names are: ' + ', '.join(i for i in fields))

# printing first 5 rows
print('The rows are:\n')
for row in rows[:3]:
	# parsing each column of a row
	for col in row:
		print(col)
