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
line = []
line_length = 0

for word in text:
	if line_length + len(word) >= w:
		formattedText.append(line)
		line = [word]
		line_length = len(word)
	else:
		line.append(word)
		line_length += len(word)+1

formattedText.append(line)

# writing output according to format
o = open("wrapout.txt","w")
if s == "L":
	for line in formattedText:
		o.write(" ".join(line)+"\n")
elif s == "R":
	for line in formattedText:
		text = " ".join(line)
		o.write(" "*(w-len(text))+text+"\n")
else:
	for line in formattedText[:-1]:
		spaces = w-len("".join(line))
		totalGap = len(line)-1
		aveSpace = spaces//totalGap
		moreSpace = spaces - (aveSpace*totalGap)
	
		for i in xrange(moreSpace):
			o.write(line[i]+" "*(aveSpace+1))
		for i in xrange(moreSpace, totalGap):
			o.write(line[i]+" "*aveSpace)
		o.write(line[-1]+"\n")

	o.write(" ".join(formattedText[-1])+"\n")

I.close()
o.close()



