from cs50 import get_string

    
def main():
    text = get_string("Text: ")
    #print(len(text))
    
    t_letter=0
    total_letter=0
    t_word=0
    total_words=1
    t_sentence=0
    total_sentences=0

   

    for i in range(0, len(text)):
        letter = text[i];
        #print(letter)
        t_letter=count_letters(letter);
        #print(f"t_letter:{t_letter}")
        total_letter = total_letter+t_letter
         #print(f"total_letter: {total_letter}")
       
        t_word = count_words(letter);
        total_words = total_words+t_word
        
        if((letter == '.') or (letter == '?') or (letter == '!')):
            pre_letter1 = text[i-1]
            pre_letter2 = text[i-2]
            if(pre_letter1.isupper() == True or pre_letter2.isupper() == True):
                continue
            else:
                t_sentence = count_sentences(letter);
                total_sentences = total_sentences + t_sentence
    
    
    #print(f"total_letter: {total_letter}")
    #print(f"total_words: {total_words}")
    #print(f"total_sentences: {total_sentences}")
    
    pre_L = float(total_letter/total_words);
    L = float(pre_L*100);
    
    pre_S = float(total_sentences/total_words);
    S = float(pre_S*100);
    
    Index = round((0.0588 * L) - (0.296 * S) - 15.8);
    grade = int(Index);

    if(Index<1):
        print("Before Grade 1")

    elif(Index>=16):
        print("Grade 16+")
        
    else:
        print(f"Grade {grade}")


def count_letters(letter):
    count = 0
    #print(type(letter))
    if ((letter >= 'a' and letter <= 'z') or (letter >= 'A' and letter <= 'Z')):
        count = count + 1
        #print(f"count of count_letters: {count}")
    return count
    
def count_words(letter):
    #print(f"in fun2")
    count2 = 0
    if letter.isspace()==True:
        count2 = count2 + 1
        #print(f"COUNT of count_words: {count2}")
    return count2

def count_sentences(letter):
    count3 = 0
    if((letter == '.') or (letter == '?') or (letter == '!')):
        count3 = count3 + 1
       # print(f"Count of count_sentences : {count3}")
    return count3

if __name__ == "__main__":
    main()