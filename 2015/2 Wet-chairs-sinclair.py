class SlidingWindow:
    def __init__(self, data, min_width, min_ndry):
        self.data = data
        self.min_width = min_width
        self.min_ndry = min_ndry
        self.left = 0
        self.right = min_width - 1
        self.ndry = data[0:min_width].count('d')

    def is_solution(self):
        return (self.ndry >= self.min_ndry)

    def width(self):
        return (self.right - self.left + 1)

    def can_advance_left(self):
        return (self.width() > self.min_width)

    def advance_left(self):
        if self.data[self.left] == 'd':
            self.ndry -= 1
        self.left += 1

    def can_advance_right(self):
        return (self.right < len(self.data)-1)

    def advance_right(self):
        self.right += 1
        if self.data[self.right] == 'd':
            self.ndry += 1

    def __str__(self):
        s = self
        return "%d..%d (%d) ndry=%d min_ndry=%d" % (s.left, s.right, s.width(), s.ndry, s.min_ndry)

def data():
    with open("chairsin.txt") as f:
        yield map(int, f.readline().split())
        yield f.readline().strip()

def solve(data, n, min_dry):
    w = SlidingWindow(data, n, min_dry)
    print w
    best = len(data)
    while True:
        if w.is_solution():
            # We have a solution. Try to find a better one by advancing left.
            best = min(best, w.width())
            if w.can_advance_left():
                w.advance_left()
            else:
                return w.width()
        else:
            # We don't have a solution. Advance right to try to find one.
            if w.can_advance_right():
                w.advance_right()
            else:
                return best

# Main
x = data()
_, n, k = x.next()
chairs  = x.next()
answer  = solve(chairs, n, n-k)
print answer
with open("chairsout.txt", "w") as f:
    print >> f, answer

