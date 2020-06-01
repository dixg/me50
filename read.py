from cs50 import get_string

def main():
    text = get_string("Text: ")
    print(len(text))
    #t_letter=0
    #total_letter=0
    count=0
    word=1

    for i in range(len(text)):
         letter = text[i]
         if text[i].isalnum()==True:
            count = count + 1
    print("count", count)
    
    for i in range(len(text)):
        if text[i].isspace() == True:
            word=word+1
    print("word", word)
    
    
         
         


if __name__ == "__main__":
    main()