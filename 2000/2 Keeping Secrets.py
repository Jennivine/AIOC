with open("secrtin.txt") as I:
    keyword = list(I.readline().strip())
    message = I.readline().strip()

cipher = list(message)
tracker = 0
for index, letter in enumerate(cipher):
    offset = ord(keyword[tracker]) - ord("A") + 1
    l = ord(letter) - ord("A")
    new_letter = ord("A") + (l + offset) % 26

    cipher[index] = chr(new_letter)

    tracker = (tracker+1)%len(keyword)

with open("secrtout.txt", "w") as O:
    O.write("".join(cipher) + "\n")
