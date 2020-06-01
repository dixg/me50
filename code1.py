# Logical operators
import inspect
from cs50 import get_string
import cs50
inspect.getfile(cs50)
print(cs50.__fil)
# Prompt user to agree
s = get_string("Do you agree?\n")

if s.lower() in ["y","yes"]:
    print("Agreed")
elif s.lower() in ["n", "no"]:
    print("NOTTTTT")
