while True:     # Infinite loop
    try:
        height = int(input("Height: "))     # Get height from user input

        if 0 < height < 9:                  # If height's value is between 1 and 8 (both inclusive)
            break                               # Then break
        continue                            # Else, try again

    except ValueError:      # If height is not an integer
        pass                    # Silently try again

for blocks in range(1, height + 1):      # For value in range 1 to 9 (loop will stop BEFORE 9)
    spaces = height - blocks                        # Number of spaces is equal to height - blocks (i.e. 8-1 = 7)

    print(" " * spaces, end="")                         # Print x (i.e. 7) space(s) and DO NOT GO to next line
    print("#" * blocks + "  " + "#" * blocks)     # Print y (i.e. 1) block(s) and GO to next line
