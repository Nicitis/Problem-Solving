n = int(input())
string = input()

for i in range(len(string)):
    while i + 3 <= len(string) and (string[i:i+3] == 'PS4' or string[i:i+3] == 'PS5'):
        if i + 3 < len(string):
            string = string[:i+2] + string[i+3:]
        else:
            string = string[:i+2]
print(string)