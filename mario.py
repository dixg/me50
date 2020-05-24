from cs50 import get_int

def main():
    while True:
        height = get_int("Height: ")
        width = height
        if height > 0 and height < 9:
            break

    for i in range(1, height + 1):
        num_hash = i
        num_space = width - num_hash
        print(" " * num_space, end="")
        print("#" * num_hash, end="")
        print()


if __name__ == "__main__":
    main()