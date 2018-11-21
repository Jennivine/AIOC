# sculpt-5.py -- fifth attempt to solve this without timeouts in Python
#
# In #4, the data structure was a (range) tree. However, because no-longer-useful nodes 
# were deleted, it was really a list. The algorithm seemed efficient, but it suffered lots
# of timeouts. This was possibly to do with garbage collection.
#
# Now, because the algorithm can use 1-dimensional data, I am going to implement it in an
# array, preallocated to contain as many nodes as neccesary (all with dummy data). They
# will then be mutated as necessary, with a "depth" index keeping track of how long our
# array really is.
#
# When placing a new block, we go from the beginning, using t1 and effective_t2 of each
# existing block to determine where the new block goes. Let's say the block "fits" at
# position 12 but not 13. Then all data from position 13 onward is now no longer
# necessary, so we put our new block in position 13 (overwriting the values of the
# existing object) and mark that as the last index.
#
# When we place a new block, it either fits "within" the parent block or it "overhangs"
# it. Iff the latter, we need to update the effective_t2 all the way back to the
# beginning.
#
# There is no "root" block. If the twentieth block lands on the ground, then it was not
# contained in the previous lot, and this block is written into position 0 and marked as
# the last index. So in the beginning, last_index = -1.

class Block:
  def __init__(self, t1, t2, ch):
    self.update_values(t1, t2, ch)

  def contains(self, t):
    return (self.t1 <= t <= self.t2)

  def update_values(self, t1, t2, ch):
    self.t1 = t1
    self.t2 = t2
    self.cumulative_height = ch

  def __repr__(self):
    return "(%d..%d[%d] ch=%d)" % \
        (self.t1, self.t2, self.effective_t2, self.cumulative_height)


class Blocks:
  def __init__(self):
    self.blocks = [None] * 100000  # pre-allocate maximum necessary blocks
    self.max_height = 0
    self.rightmost_location = -1
    self.last_index = -1

  def insert_block(self, t, w, h):
    # 1. Find place to insert and determine new cumulative_height.
    index = self._find_block_resting_place(t)
    ch    = self._cumulative_height(index, h)
    # 2. Write the block and update things that need to be updated.
    self._write_block_in_place(index, t, t+w-1, ch)
    self._update_information(index)
    return None

  def __repr__(self):
    blocks_str = "\n  ".join( [repr(self.blocks[i]) for i in self._active_indices()] )
    result     = "Blocks(last_index=%d max_h=%d) ->\n  %s" % \
                    (self.last_index, self.max_height, blocks_str)
    return result

  def _find_block_resting_place(self, t):
    if self.last_index < 0:
      # No blocks placed yet: place at index 0.
      return 0
    elif self.rightmost_location < t:
      # None of the existing blocks will contain this one: place at index 0.
      return 0
    else:
      # The current tower will contain this one: work backwards from most recent.
      for index, block in self._reverse_enumerate():
        if block.contains(t):
          return index + 1

  def _cumulative_height(self, index, h):
    if index > 0:
      return self.blocks[index-1].cumulative_height + h
    else:
      return h

  def _write_block_in_place(self, index, t1, t2, ch):
    if self.blocks[index] == None:
      # This location has not yet been written. Create a new block.
      self.blocks[index] = Block(t1, t2, ch)
    else:
      # We are overwriting an earlier block, to save memory churn.
      self.blocks[index].update_values(t1, t2, ch)

  # Update the things that need to be updated: max_height, last_index and rightmost_location.
  def _update_information(self, index):
    # last_index
    self.last_index = index
    # max_height
    height = self.blocks[index].cumulative_height
    if self.max_height < height:
      self.max_height = height
    # rightmost_location
    loc = self.blocks[index].t2
    if self.rightmost_location < loc:
      self.rightmost_location = loc
    return None

  # We want a range that goes from 0 to the last index, inclusive.
  def _active_indices(self):
    return xrange(0, self.last_index+1)

  def _reverse_enumerate(self):
    indices = xrange(0, self.last_index+1)
    for i in reversed(indices):
      yield (i, self.blocks[i])


class FileIO:
  # Return list of (time, width, height)
  @staticmethod
  def data(infilename):
    with open(infilename) as f:
      lines = f.readlines()
      del lines[0]
      result = []
      for line in lines:
        t, w, h = map(int, line.split(' '))
        result.append((t,w,h))
      return result

  @staticmethod
  def write_answer(answer, outfilename):
    with open(outfilename, "w") as f:
      f.write(str(answer) + "\n")


def solve(data):
  blocks = Blocks()
  for t,w,h in data:
    blocks.insert_block(t,w,h)
    #print blocks
    #print
  return blocks.max_height

sample_data = [
    (10,20,5),
    (22,20,3),
    (25,5,2),
    (38,7,3),
    (41,2,2),
    (42,2,1),
    (100,15,6),
    (130,10,6),
    (133,5,4)
]

data = FileIO.data("artin.txt")
answer = solve(data)
#print answer
FileIO.write_answer(answer, "artout.txt")
