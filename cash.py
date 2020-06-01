from cs50 import get_float

def main():
    
    value = get_float("Change Owned: ")
    
    while value < 0:
        value = get_float("Change Owned: ")

    cents = round(value*100)

    num_coins = 0

    while cents >= 25:
        cents = cents - 25
        num_coins = num_coins + 1

    while cents >= 10:
        cents = cents - 10
        num_coins = num_coins + 1

    while cents >= 5:
        cents = cents - 5
        num_coins = num_coins + 1

    while cents >= 1:
        cents = cents - 1
        num_coins = num_coins + 1

    print(" ",num_coins)

if __name__ == "__main__":
    main() 