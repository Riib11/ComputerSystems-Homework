with open("helper.txt", "w+") as file:
    for i in range(200):
        if i % 10 == 0: file.write("\n")
        file.write("*nums++ = atoi(lines[i+"+str(i)+"]);\n")
