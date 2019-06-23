I = open("wrapin.txt")

s, w = I.readline().strip().split()
w = int(w)

text = []
rawText = I.readline().strip()

def get_words(text):
	# split a line of text into words without whitespace
	# and returns that as a list
	return text.split()

while rawText != "#":
	text.extend(get_words(rawText))
	rawText = I.readline().strip()

formattedText = []

line = text[0]
line_lengths = []

for word in text[1:]:
	if len(line) + len(word) + 1 > w:
		formattedText.append(line)
		line_lengths.append(len(line))
		line = word
	else:
		line += " " + word

formattedText.append(line)
line_lengths.append(len(line))

# writing output according to format
o = open("wrapout.txt","w")
if s == "L":
	for line in formattedText:
		o.write(line+"\n")
elif s == "R":
	for line in formattedText:
		difference = w-len(line)
		o.write(" "*difference+line+"\n")
else:
	for line in formattedText[:-1]:
		spaces = w-len(line)
		totalGap = len(line.split())-1
		aveSpace = (spaces/totalGap)+1
		moreSpace = spaces%totalGap

		words = line.split()
		new = words[0]
		for i in xrange(1, totalGap+1):
			new += " "*aveSpace
			if i <= moreSpace:
				new += " "
			new += words[i]
		o.write(new+"\n")
	o.write(formattedText[-1]+"\n")

I.close()
o.close()



