people = {
    "Carter": "+1-617-495-100",
    "David": "+1-617-495-100",
    "John": "+1-919-468-2750"
}

name = input("Name: ")

if name in people:
    number = people[name]
    print(f"Found {number}")
else:
    print("Not found")