s = input("Do you agree? ").lower()

if s in ["y", "ye", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not agreed")