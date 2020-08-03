from cs50 import get_string

def main():
    letters = 0
    words = 0
    sentences = 0
    text = get_string("Text: ")
    for i in range(len(text)):
        if text[i].isalpha() == True: # All of these only happen if current char is a letter
            letters += 1
            if text[i + 1].isspace() == True:
                words += 1
            if text.find(',', i + 1, i + 2) != -1:
                words += 1
            if text.find('.', i + 1, i + 2) != -1:
                words += 1
                sentences += 1
            if text.find('?', i + 1, i + 2) != -1:
                words += 1
                sentences += 1
            if text.find('!', i + 1, i + 2) != -1:
                words +=1
                sentences += 1
    total = words / 100
    L = letters / total
    S = sentences / total
    findGradeLevel(L, S)

def findGradeLevel(L, S):
    gradeLevel = 0.0588 * L - 0.296 * S - 15.8 # Coleman-Liau Index
    if gradeLevel > 16:
        print("Grade 16+")
    elif gradeLevel < 1:
        print("Before Grade 1")
    else:
        gradeLevel = round(gradeLevel) # Make it a whole number
        print(f"Grade {gradeLevel}")

main()
