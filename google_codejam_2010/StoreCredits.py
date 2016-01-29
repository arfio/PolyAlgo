def store_credits(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        for nLine in range(1, int(lines[0])*3, 3):
            test_case_number += 1
            balance = int(lines[nLine])
            items = [int(s) for s in lines[nLine+2].split() if s.isdigit()]

            result = search_sum(items, balance)

            print("Case #{}: {} {}".format(test_case_number, result[0], result[1]))


def search_sum(items, balance):
    for i, item in enumerate(items):
        for j, item2 in enumerate(items):
            if item + item2 == balance and i != j:
                if i < j:
                    return [i+1, j+1]
                else:
                    return [j+1, i+1]


store_credits('file.txt')
exit()
