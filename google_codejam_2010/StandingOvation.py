def standing_ovation(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        line_number = 1
        while test_case_number < int(lines[0]):
            test_case_number += 1
            # variables for this problem
            sum_persons_clapping = 0
            n_friends = 0
            shyness_lvl = 0
            for i in lines[line_number].split(' ')[1]:
                if i == '\n':
                    break
                elif sum_persons_clapping + n_friends >= shyness_lvl:
                    sum_persons_clapping += int(i)
                else:
                    n_friends += shyness_lvl - (sum_persons_clapping + n_friends)
                    sum_persons_clapping += int(i)
                shyness_lvl += 1
            # end of problem logic
            print("Case #{}: {}".format(test_case_number, n_friends))
            line_number += 1


standing_ovation('file.txt')
exit()
