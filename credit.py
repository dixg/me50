from cs50 import get_int

def main():
    sum_odd = 0
    prod_digit = 0
    prod_digit2 = 0
    Num_digit = 1

    cc_num = get_int("Number: ")
    backup= cc_num

    store_count = len(str(abs(cc_num)))
    #print("length:", store_count)

    if store_count != 13 and store_count != 15 and store_count != 16:
        print("INVALID")
        return 0

    else:
       # print("VALID")
        while cc_num > 0:
           # print("  << Num_digit = ", Num_digit)
            num = cc_num % 10
            #print("THE NUM = ", num, end = '')

            if(Num_digit % 2 == 0):
                
                prod_even = num*2
                #print(" EVEN:prod_even = ", prod_even, end = '')

                if(prod_even >= 10):
                    while prod_even>0:
                        prod_digit2 = prod_even % 10
                        #print("   prod_digit2 = ", prod_digit2, end = '')
                        prod_even = prod_even//10
                        prod_digit = prod_digit + prod_digit2
                       # print("   prod_even = ", prod_even, end = '')
                        #print(" EVEN prod_digit = ", prod_digit, end = '')

                else:
                    prod_digit= prod_digit + prod_even
                    #print(" EVEN prod_digit = ", prod_digit, end = '')

            else:       #correct
                sum_odd = sum_odd + num
                #print(" ODD :sum_odd  =  ", sum_odd, end = '')

            cc_num= cc_num//10
            #print(" #cc_num = ",cc_num, end = '')
            Num_digit = Num_digit+1
            #print(" Num_digit = ", Num_digit)
            

    Final_factor= prod_digit + sum_odd

    #print("The sum is \n", Final_factor)

    if Final_factor % 10 == 0:
        #print("REAACHED")
        
        Visa_check1 = backup//pow(10,15)
        #print("Visa_check1 =", Visa_check1)
        Visa_check2=backup//pow(10,12) #Visa number size could be 13 digit.
        #print("Visa_check2 =", Visa_check2)
        Amex_check=backup//pow(10,13)
        #print("Amex_check =", Amex_check)
        MasterCard_check=backup//pow(10,14)
        #print("MasterCard_check =", MasterCard_check)

        if Visa_check1 == 4 or Visa_check2 == 4:
            print("VISA\n")
            return 0

        elif Amex_check == 34 or Amex_check == 37:
            print("AMEX\n")
            return 0

        elif MasterCard_check == 51 or MasterCard_check == 52 or MasterCard_check == 53 or MasterCard_check == 54 or MasterCard_check==55:
            print("MASTERCARD\n")
            return 0

        else:
            print("INVALID\n");
            return 0;

    else:
        print("INVALID\n")
        return 0

if __name__ == "__main__":
    main()