def reverse_words():
    with open('file.txt', mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        for line in lines:
            test_case_number += 1
            mots = line.split(' ')
            mots.reverse()
            print("Case #{}: {}".format(test_case_number, " ".join(mots).replace("\n", "")))


reverse_words()
exit()
