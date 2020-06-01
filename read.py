from cs50 import get_string

def main():
    text = get_string("Text: ")
    print(len(text))
    text_len = len(text)
    #t_letter=0
    #total_letter=0
    count=0
    word=1
    sen_count=0


    for i in range(len(text)):
         letter = text[i]
         if text[i].isupper() == True or text[i].islower()==True:
            count = count + 1
    print("count", count)
    
    for i in range(len(text)):
        if text[i].isspace() == True:
            word=word+1
    print("word", word)
    
    for i in range(text_len):
        letter = text[i]
        if((letter == '.') or (letter == '?') or (letter == '!')):
            pre_letter1 = text[i-1]
            pre_letter2 = text[i-2]
            if(pre_letter1.isupper() == True or pre_letter2.isupper() == True):
                continue
            else:
                sen_count = sen_count + 1
                print(f"sen_count: {sen_count}")
                
    
    #print(f"total_letter: {total_letter}")
    #print(f"total_words: {total_words}")
    print(f"sen_count: {sen_count}")
    
    pre_L = float(count/word);
    L = float(pre_L*100);
    
    pre_S = float(sen_count/word);
    S = float(pre_S*100);
    
    Index = round((0.0588 * L) - (0.296 * S) - 15.8);
    grade = int(Index);

    if(Index<1):
        print("Before Grade 1")

    elif(Index>=16):
        print("Grade 16+")
        
    else:
        print(f"Grade {grade}")
                
            

if __name__ == "__main__":
    main()