letter_to_number = {
    97: "2", 98: "22", 99: "222",
    100: "3", 101: "33", 102: "333",
    103: "4", 104: "44", 105: "444",
    106: "5", 107: "55", 108: "555",
    109: "6", 110: "66", 111: "666",
    112: "7", 113: "77", 114: "777", 115: "7777",
    116: "8", 117: "88", 118: "888",
    119: "9", 120: "99", 121: "999", 122: "9999"
}


def t9_spelling(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        for nLine in range(1, int(lines[0]) + 1):
            test_case_number += 1
            sentence = lines[nLine]

            numbers = convert_text_to_t9(sentence)

            print("Case #{}: {}".format(test_case_number, numbers))


def convert_text_to_t9(sentence):
    numbers = ""
    number_before = "#"
    for letter in sentence:
        if letter == ' ':
            number_after = "0"
        elif str.islower(letter):
            number_after = letter_to_number[ord(letter)]
        else:
            continue

        if number_after[0] == number_before[0]:
            numbers += ' '
            numbers += number_after
        else:
            numbers += number_after
            number_before = number_after
    return numbers

t9_spelling('file.txt')
exit()
