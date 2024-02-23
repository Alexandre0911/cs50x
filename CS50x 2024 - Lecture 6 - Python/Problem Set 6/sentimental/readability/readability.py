import cs50


def main():
    text = cs50.get_string("Text: ")
    print(grade(calculateIndex(text)))


def grade(index):
    if index < 1:
        return "Before Grade 1"
    elif index >= 16:
        return "Grade 16+"
    else:
        return f"Grade {index}"


def calculateIndex(text):
    text = text.split()

    words = len(text)
    letters = 0
    sentences = 0

    for i in text:
        for j in i:
            if j.isalpha():
                letters += 1
            if j in ['.', '?', '!']:
                sentences += 1

    L = letters / words * 100
    S = sentences / words * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    return index


main()
